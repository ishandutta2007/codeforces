#include <bits/stdc++.h>
using namespace std;
const int N = 1003;
const int b[4][4] =
{
    {8, 9, 1, 13},
    {3, 12, 7, 5},
    {0, 2, 4, 11},
    {6, 10, 15, 14}
};

int n;
int a[N][N];

int main()
{
    cin >> n;
    int q = 0;
    for (int i = 0; i < n; i += 4)
    {
        for (int j = 0; j < n; j += 4)
        {
            for (int ii = i; ii < i + 4; ++ii)
            {
                for (int jj = j; jj < j + 4; ++jj)
                {
                    a[ii][jj] = b[ii - i][jj - j] + q;
                }
            }
            q += (4 * 4);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}