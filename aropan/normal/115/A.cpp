#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 2222;


int n, ans = 0;
int x[MAXN];
int a[MAXN][MAXN];

int dfs(int x, int d)
{
    if (d > ans) ans = d;
    for (int i = 0; i < n; i++)
        if (a[x][i])
            dfs(i, d + 1);
    return 0;
}
        
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
        if (x[i] == -1) continue;
        a[x[i] - 1][i] = 1;
    }
    for (int i = 0; i < n; i++)
        if (x[i] == -1)
            dfs(i, 1);
    printf("%d\n", ans);
    return 0;
}