#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>

using namespace std;


const int MAXN = 100001;
const int MAXM = MAXN + MAXN;

int last[MAXN];
int next[MAXM], dest[MAXM];
int f[MAXN], g[MAXN], s[MAXN];

int n;
long long ans, F, G;

int dfs(int x, int p)
{
    s[x] = 1;
    for (int i = last[x]; i; i = next[i])
    {
        int y = dest[i];
        if (y != p)
        {
            dfs(y, x);
            s[x] += s[y];
            f[x] += f[y];
            if (g[x]) ans += (long long)g[x] * s[y] * f[y];
        }
    }
    if (g[x]) ans += (long long)g[x] * (F - f[x]) * (n - s[x]);
    return 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        dest[i] = y;
        next[i] = last[x];
        last[x] = i;

        dest[i + n] = x;
        next[i + n] = last[y];
        last[y] = i + n;
    }

    F = G = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &f[i], &g[i]);
        F += f[i];
        G += g[i];
    }

    dfs(1, 0);

    printf("%.20lf\n", (double)ans / (F * G));

    fprintf(stderr, "Time of execution: %.3lf sec.\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}