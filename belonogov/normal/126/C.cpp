#include <iostream>
#include <cstdio>

using namespace std;
const int MAXN = 2e3 + 2;
int a[MAXN][MAXN];
int b1[MAXN];
int b2[MAXN];
int c1[MAXN];
int c2[MAXN];
int count = 0;
char s[MAXN];

int main()
{
    int n, i, j, x, y;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%s", s);
        for (j = 0; j < n; j++)
            a[i][j] = s[j] - '0';
    }
    for (i = 0; i < n - 1; i++)
        for (j = 0; j <= i; j++)
        {
            x = n - 1 - i + j;
            y = j;
            if ((a[x][y] + b1[x] + b2[y]) % 2 == 1)
            {
                count++;
                b1[x]++;
                b2[y]++;
            }
        }
    for (i = 0; i < n - 1; i++)
        for (j = 0; j <= i; j++)
        {
            x = i - j;
            y = n - 1 - j;
            if ((a[x][y] + c1[x] + c2[y]) % 2 == 1)
            {
                count++;
                c1[x]++;
                c2[y]++;
            }
        }
    for (i = 0; i < n; i++)
    {
        if ((a[i][i] + b1[i] + b2[i] + c1[i] + c2[i]) % 2 == 1)
            count++;
    }
    cout << count;
    return 0;
}