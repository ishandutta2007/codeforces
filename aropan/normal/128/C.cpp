#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>

using namespace std;

const int MOD = 1000000007;

const int MAXN = 1007;

int c[MAXN][MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    c[0][0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        c[i][0] = c[i - 1][0];
        for (int j = 1; j <= i; j++)
        {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            if (c[i][j] >= MOD) c[i][j] -= MOD;
        }
    }

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    if (2 * k >= n || 2 * k >= m)
        printf("0\n");
    else
        printf("%d\n", (int)((long long)c[n - 1][2 * k] * (long long)c[m - 1][2 * k] % MOD));
        

    fprintf(stderr, "Time of execution: %.3lf sec.\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}