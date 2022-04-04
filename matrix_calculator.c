#include<stdio.h>

void input(int r,int c,int a[r][c]) //function to input array elements
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}
void display(int r,int c,int a[r][c]) //function to display array elememts
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf(" \n");
    }
    printf("\n");
}
void multiplicate(int r1, int c1,int c2,int a[r1][c1],int b[c1][c2],int c[r1][c2]) //function to multiply 2 matrices
{
    int row,col,k;
    for(row=0;row<r1;row++)
    {
        for(col=0;col<c2;col++)
        {
            c[row][col]=0;
            for(k=0;k<c1;k++)
            {
                c[row][col]=c[row][col]+(a[row][k]*b[k][col]);
            }
        }
    }
}
void checkmultiply() //function to check compatiblility of matrices and multiply them
{
    int r1,r2,c1,c2;

    printf("Enter size of matrix 1 in mxn format \n");
    scanf("%d %d",&r1,&c1);
    printf("Enter size of matrix 2 in mxn format \n");
    scanf("%d %d",&r2,&c2);
    if(c1==r2)
    {
        printf("\n**Compatible Matrices**\n");
        int a[r1][c1];
        int b[r2][c2];
        int c[r1][c2];
        printf("\nEnter elements of 1st matrix\n");
        input(r1,c1,a);
        printf("\nEnter elements of 2nd matrix\n");
        input(r2,c2,b);

        multiplicate(r1,c1,c2,a,b,c);

        printf("\n 1st matrix : \n");
        display(r1,c1,a);
        printf("2nd matrix : \n");
        display(r2,c2,b);
        printf("Multiplied matrix : \n");
        display(r1,c2,c);
    }
    else
    {
        printf("Not compatible matrices, can't multiply \n");

    }

}

void checktriangular() //function to check triangular matrices
{
    int r,c;
    printf("\nEnter size of matrix in m x n format\n");
    scanf("%d %d",&r,&c);

    int dda[r][c];

    printf("\nEnter matrix elements\n");
    input(r,c,dda);
    printf("\nEntered Matrix \n");
    display(r,c,dda);

    int upflag=1,lowflag=1;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(i<j && dda[i][j]!=0)
            lowflag=0;

            if(i>j && dda[i][j]!=0)
            upflag=0;

        }
    }
    if(upflag==0 && lowflag==0)
        printf("Not a Triangular Matrix \n");
    else
    {
        if(upflag==1)
            printf("Upper Triangular Matrix \n");

        if(lowflag==1)
            printf("Lower Triangular Matrix \n");
    }

}
void transpose(int r,int c,int dda[r][c],int dda2[r][c]) //function perform transpose of matrices
{

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            dda2[i][j]=dda[j][i];
        }
    }

}
void checktranspose() //function to transpose 2 matrices
{
    int r,c;
    printf("\nEnter size of matrix in m x n format\n");
    scanf("%d %d",&r,&c);

    int dda[r][c];
    int dda2[r][c];

    printf("\nEnter matrix elements\n");
    input(r,c,dda);
    transpose(r,c,dda,dda2);
    printf("\nOriginal Matrix: \n");
    display(r,c,dda);
    printf("\nTransposed Matrix: \n");
    display(r,c,dda2);
}
int main() //main function
{
    for(;;)
    {
    int ch;
    printf("\nEnter 1 fo Matrix Multilplication, 2 for Triangular Matrix , 3 for Transpose of a Matrix, 0 to exit\n");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:
            checkmultiply();
            break;
        case 2:
            checktriangular();
            break;
        case 3:
            checktranspose();
            break;
        case 0:
            return 0;
            break;
        default:
        printf("Wrong Choice XD\n");

    }
    }
    return 0;
}
