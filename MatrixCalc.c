#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void getCofactor(int A[][100], int temp[][100], int p, int q, int n)
{
    int i = 0, j = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = A[row][col];
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinant(int A[][100], int n)
{
    int D = 0;
    if (n == 1)
        return A[0][0];
    int temp[100][100];
    int sign = 1;
    for (int i = 0; i < n; i++)
    {
        getCofactor(A, temp, 0, i, n);
        D += sign * A[0][i] * determinant(temp, n - 1);
        sign = -sign;
    }
    return D;
}

void adjoint(int A[][100], int adj[][100], int n)
{
    if (n == 1)
    {
        adj[0][0] = 1;
        return;
    }
    int sign = 1, temp[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            getCofactor(A, temp, i, j, n);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = sign * determinant(temp, n - 1);
        }
    }
}

void inverse(int A[][100], float inv[][100], int n)
{
    int det = determinant(A, n);
    if (det == 0)
    {
        printf("Matrix is singular and cannot be inverted\n");
        return;
    }
    int adj[100][100];
    adjoint(A, adj, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            inv[i][j] = (float)adj[i][j] / det;
        }
    }
}

int main()
{
    int cflag = 1; // looping flag

    while (cflag == 1)
    {
        system("clear");
        printf("----------------------------\n");
        printf("\t\t-----------------------\n");
        printf("\n\t\t~~ Matrix Calculator ~~\n");
        printf("\t\t-----------------------\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Scalar Multiply\n");
        printf("4. Matrix Multiply\n");
        printf("5. Matrix Transpose\n");
        printf("6. Matrix Determinant\n");
        printf("7. Adjoint Matrix\n");
        printf("8. Inverse Matrix\n");
        printf("9. Exit\n");
        printf("----------------------------\n");
        int ch;
        printf("Enter Operation! \n");
        scanf("%d", &ch);

        int n1, n2;
        switch (ch)
        {
        case 1:
            system("clear");
            printf("\t\t-----------------------\n");
            printf("\n\t\t~~ Matrix Addition ~~\n");
            printf("\t\t-----------------------\n");
            printf("\nEnter Row & Coloumn of matrix A [nxn]! \n");
            scanf("%d", &n1);

            printf("\nEnter Row & Coloumn of matrix B [nxn]! \n");
            scanf("%d", &n2);
            int m1[10][10];
            int m2[10][10];
            if (n1 == n2)
            {
                printf("Enter elements of matrix A !\n");
                for (int i = 0; i < n1; i++)
                {
                    for (int j = 0; j < n1; j++)
                    {
                        scanf("%d", &m1[i][j]);
                    }
                }
                printf("Enter elements of matrix B !\n");
                for (int i = 0; i < n1; i++)
                {
                    for (int j = 0; j < n1; j++)
                    {
                        scanf("%d", &m2[i][j]);
                    }
                }
            }
            else
            {
                printf("Matrix Size should be same\n");
            }
            printf("Matrix A is\n");
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < n1; j++)
                {
                    printf("%d ", m1[i][j]);
                }
                printf("\n");
            }
            printf("Matrix B is\n");
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < n1; j++)
                {
                    printf("%d ", m2[i][j]);
                }
                printf("\n");
            }
            // additon :
            printf("New Matrix is\n");
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < n1; j++)
                {
                    printf("%d ", (m1[i][j] + m2[i][j]));
                }
                printf("\n");
            }

            printf("\nDo you want to continue? \n1. yes\n2. no \n");
            scanf("%d", &cflag);

            break;

        case 2:
            system("clear");
            printf("\t\t-----------------------\n");
            printf("\n\t\t~~ Matrix Subtraction ~~\n");
            printf("\t\t-----------------------\n");
            printf("\nEnter Row & Coloumn of matrix A [nxn]! \n");
            scanf("%d", &n1);

            printf("\nEnter Row & Coloumn of matrix B [nxn]! \n");
            scanf("%d", &n2);

            if (n1 == n2)
            {
                int m3[10][10];
                int m4[10][10];
                printf("Enter elements of matrix A !\n");
                for (int i = 0; i < n1; i++)
                {
                    for (int j = 0; j < n1; j++)
                    {
                        scanf("%d", &m1[i][j]);
                    }
                }
                printf("Enter elements of matrix B !\n");
                for (int i = 0; i < n1; i++)
                {
                    for (int j = 0; j < n1; j++)
                    {
                        scanf("%d", &m2[i][j]);
                    }
                }
            }
            else
            {
                printf("Matrix Size should be same\n");
            }
            printf("Matrix A is\n");
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < n1; j++)
                {
                    printf("%d ", m1[i][j]);
                }
                printf("\n");
            }
            printf("Matrix B is\n");
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < n1; j++)
                {
                    printf("%d ", m2[i][j]);
                }
                printf("\n");
            }
            // subtration :
            printf("New Matrix is\n");
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < n1; j++)
                {
                    printf("%d ", (m1[i][j] - m2[i][j]));
                }
                printf("\n");
            }

            printf("\nDo you want to continue? \n1. yes\n2. no \n");
            scanf("%d", &cflag);

            break;

        case 3:
            system("clear");
            printf("\t\t-----------------------\n");
            printf("\n\t\t~~ Matrix Scalar Multiplication ~~\n");
            printf("\t\t-----------------------\n");
            printf("\nEnter Row & Coloumn of matrix A [nxn]! \n");
            scanf("%d", &n1);
            int m[10][10];

            printf("Enter elements of matrix  !\n");
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < n1; j++)
                {
                    scanf("%d", &m[i][j]);
                }
            }
            int k;
            printf("Enter the value of scalar K \n");
            scanf("%d", &k);

            printf("Matrix A is\n");
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < n1; j++)
                {
                    printf("%d ", m[i][j]);
                }
                printf("\n");
            }

            // scalar multi :
            printf("New Matrix is\n");
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < n1; j++)
                {
                    printf("%d ", (k * m[i][j]));
                }
                printf("\n");
            }

            printf("\nDo you want to continue? \n1. yes\n2. no \n");
            scanf("%d", &cflag);

            break;

        case 4:
            system("clear");
            printf("\t\t-----------------------\n");
            printf("\n\t\t~~ Matrix Multiplication ~~\n");
            printf("\t\t-----------------------\n");
            printf("\nEnter Row & Coloumn of matrix A [nxn]! \n");
            scanf("%d", &n1);

            printf("\nEnter Row & Coloumn of matrix B [nxn]! \n");
            scanf("%d", &n2);

            if (n1 == n2)
            {
                int m5[10][10];
                int m6[10][10];
                int m7[10][10];
                printf("Enter elements of matrix A !\n");
                for (int i = 0; i < n1; i++)
                {
                    for (int j = 0; j < n1; j++)
                    {
                        scanf("%d", &m5[i][j]);
                    }
                }
                printf("Enter elements of matrix B !\n");
                for (int i = 0; i < n1; i++)
                {
                    for (int j = 0; j < n1; j++)
                    {
                        scanf("%d", &m6[i][j]);
                    }
                }
                // matrix multiplication
                for (int i = 0; i < n1; i++)
                {
                    for (int j = 0; j < n2; j++)
                    {
                        int sum = 0;
                        for (int k = 0; k < n2; k++)
                        {
                            sum += m5[i][k] * m6[k][j];
                        }
                        m7[i][j] = sum;
                    }
                }

                printf("New Matrix is!\n");
                for (int i = 0; i < n1; i++)
                {
                    for (int j = 0; j < n1; j++)
                    {
                        printf("%d ", m7[i][j]);
                    }
                    printf("\n");
                }
            }
            else
            {
                printf("Matrix Size should be same\n");
            }
            break;

        case 5:
            system("clear");
            printf("\t\t-----------------------\n");
            printf("\n\t\t~~ Matrix Transpose ~~\n");
            printf("\t\t-----------------------\n");
            printf("\nEnter Row & Coloumn of matrix [nxn]! \n");
            scanf("%d", &n1);
            int m8[10][10];

            printf("Enter elements of matrix  !\n");
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < n1; j++)
                {
                    scanf("%d", &m8[i][j]);
                }
            }

            printf("Matrix is\n");
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < n1; j++)
                {
                    printf("%d ", m8[i][j]);
                }
                printf("\n");
            }

            printf("New Matrix is!\n");
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < n1; j++)
                {
                    printf("%d ", m8[j][i]);
                }
                printf("\n");
            }

            printf("\nDo you want to continue? \n1. yes\n2. no \n");
            scanf("%d", &cflag);

            break;

        case 6:
            system("clear");
            printf("\t\t-----------------------\n");
            printf("\n\t\t~~ Matrix Determinant ~~\n");
            printf("\t\t-----------------------\n");
            printf("\nEnter Row & Coloumn of matrix [nxn]! \n");
            scanf("%d", &n1);
            int m9[100][100];
            printf("Enter elements of matrix  !\n");
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < n1; j++)
                {
                    scanf("%d", &m9[i][j]);
                }
            }

            printf("Matrix is\n");
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < n1; j++)
                {
                    printf("%d ", m9[i][j]);
                }
                printf("\n");
            }

            int det = determinant(m9, n1);
            printf("Determinant: %d\n", det);

            printf("\nDo you want to continue? \n1. yes\n2. no \n");
            scanf("%d", &cflag);

            break;

        case 7:

            system("clear");
            printf("\t\t-----------------------\n");
            printf("\n\t\t~~ Adjoint Matrix ~~\n");
            printf("\t\t-----------------------\n");
            printf("\nEnter Row & Coloumn of matrix [nxn]! \n");
            scanf("%d", &n1);
            int m10[100][100];

            printf("Enter elements of matrix  !\n");
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < n1; j++)
                {
                    scanf("%d", &m10[i][j]);
                }
            }

            printf("Matrix is\n");
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < n1; j++)
                {
                    printf("%d ", m10[i][j]);
                }
                printf("\n");
            }

            int adj[100][100];
            adjoint(m10, adj, n1);

            printf("Adjoint matrix:\n");
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < n1; j++)
                {
                    printf("%d ", adj[i][j]);
                }
                printf("\n");
            }

            printf("\nDo you want to continue? \n1. yes\n2. no \n");
            scanf("%d", &cflag);

            break;

        case 8:
            system("clear");
            printf("\t\t-----------------------\n");
            printf("\n\t\t~~ Inverse Of Matrix ~~\n");
            printf("\t\t-----------------------\n");
            printf("\nEnter Row & Coloumn of matrix [nxn]! \n");
            scanf("%d", &n1);
            int m11[100][100];

            printf("Enter elements of matrix  !\n");
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < n1; j++)
                {
                    scanf("%d", &m11[i][j]);
                }
            }

            printf("Matrix is\n");
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < n1; j++)
                {
                    printf("%d ", m11[i][j]);
                }
                printf("\n");
            }

            float inv[100][100];
            inverse(m11, inv, n1);

            printf("Inverse matrix:\n");
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < n1; j++)
                {
                    printf("%.2f ", inv[i][j]);
                }
                printf("\n");
            }

            printf("\nDo you want to continue? \n1. yes\n2. no \n");
            scanf("%d", &cflag);

            break;

        case 9:
            system("clear");
            printf("Have a great day! \nBye Bye\n");
            exit(0);
            break;

        default:
            printf("\nInvalid Entry \n");

            printf("\nDo you want to continue? \n1. yes\n2. no \n");
            scanf("%d", &cflag);

            break;
        }
    }
    return 0;
}