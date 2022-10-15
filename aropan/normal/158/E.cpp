#include <cstdio>
#include <algorithm>
#include <ctime>

using namespace std;


const int MAXN = 4007;

int f[MAXN];
int n, k;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif

    scanf("%d %d", &n, &k);
    for (int i = 0; i <= k; i++)
        f[i] = 1;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int t, d;
        scanf("%d %d", &t, &d);
        for (int j = 0; j <= k; j++)
            ans = max(ans, t - f[j]);

        for (int j = k; j >= 0; j--)
        {
            f[j] = max(f[j], t) + d;
            if (j) f[j] = min(f[j], f[j - 1]);
        }
    }
    for (int j = 0; j <= k; j++)
        ans = max(ans, 86401 - f[j]);

    printf("%d\n", ans);

    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}