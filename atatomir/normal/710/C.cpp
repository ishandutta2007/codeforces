#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 55

int n, i, j, mid, even, odd;
int mat[maxN][maxN];

int main()
{
    scanf("%d", &n);

    mid = (n + 1) / 2;

    mat[mid][mid] = 1;
    for (i = 1; mid - i > 0; i++)
        for (j = -i + 1; j <= i - 1; j++)
            mat[mid - i][mid + j] = mat[mid + i][mid + j] = 1;

    for (i = 1; i <= n; i++) mat[mid][i] = 1;


    even = 2; odd = 1;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (mat[i][j] == 0) {
                mat[i][j] = even;
                even += 2;
            } else {
                mat[i][j] = odd;
                odd += 2;
            }

            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}