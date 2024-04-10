#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;


const int MAXN = 1000001;

int a[MAXN][5], b[MAXN][5];
int n, m;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    scanf("%d %d\n", &n, &m);
    
    for (int x = 1; x <= 4; x++)
    {
        for (int i = 0; i < n; i++) b[i][x] = 1;
        for (int i = 0; i < m; i++) a[i][x] = 1;
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            scanf("%c", &c);
            if (c == '.') continue;

            int x = c - '0';

            if (j == 0)
            {
                for (int k = 1; k <= 4; k++)
                    b[i][k] &= k == x;
            }
            else
            {
                b[i][1] &= ((x == 1) || (x == 2)) && (j % 2 == 0) || ((x == 3) || (x == 4)) && (j % 2 == 1);
                b[i][2] &= ((x == 1) || (x == 2)) && (j % 2 == 0) || ((x == 3) || (x == 4)) && (j % 2 == 1);
                b[i][3] &= ((x == 1) || (x == 2)) && (j % 2 == 1) || ((x == 3) || (x == 4)) && (j % 2 == 0);
                b[i][4] &= ((x == 1) || (x == 2)) && (j % 2 == 1) || ((x == 3) || (x == 4)) && (j % 2 == 0);
            }


            if (i == 0)
            {
                for (int k = 1; k <= 4; k++)
                    a[j][k] &= k == x;
            }
            else
            {
                a[j][1] &= ((x == 1) || (x == 4)) && (i % 2 == 0) || ((x == 2) || (x == 3)) && (i % 2 == 1);
                a[j][4] &= ((x == 1) || (x == 4)) && (i % 2 == 0) || ((x == 2) || (x == 3)) && (i % 2 == 1);
                a[j][2] &= ((x == 1) || (x == 4)) && (i % 2 == 1) || ((x == 2) || (x == 3)) && (i % 2 == 0);
                a[j][3] &= ((x == 1) || (x == 4)) && (i % 2 == 1) || ((x == 2) || (x == 3)) && (i % 2 == 0);
            }
        }
        scanf("\n");
    }


    int ans = 0;
    int MOD = 1000003;
    for (int x = 1; x <= 4; x++)
        if (a[0][x] && b[0][x])
        {
            int res = 1;
            for (int j = 1; j < m; j++)
            {
                res *=
                    ((int)a[j][1] + (int)a[j][2]) * (((x == 1) || (x == 2)) && (j % 2 == 0) || ((x == 3) || (x == 4)) && (j % 2 == 1)) +
                    ((int)a[j][3] + (int)a[j][4]) * (((x == 1) || (x == 2)) && (j % 2 == 1) || ((x == 3) || (x == 4)) && (j % 2 == 0));
                res %= MOD;
            }
            for (int i = 1; i < n; i++)
            {
                res *=
                    ((int)b[i][1] + (int)b[i][4]) * (((x == 1) || (x == 4)) && (i % 2 == 0) || ((x == 2) || (x == 3)) && (i % 2 == 1)) +
                    ((int)b[i][2] + (int)b[i][3]) * (((x == 1) || (x == 4)) && (i % 2 == 1) || ((x == 2) || (x == 3)) && (i % 2 == 0));
                res %= MOD;
            }
            (ans += res) %= MOD;
        }
    printf("%d\n", (int)ans);
    return 0;
}