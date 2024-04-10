#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;


const int MAXN = 222222;
const int MOD = 1000000007;

int f[MAXN];
pair <int, int> a[MAXN];
int x[MAXN];
int n, m, k;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a[i].second, &a[i].first);
        x[k++] = a[i].first;
        x[k++] = a[i].second;
    }
    x[k++] = 0;
    x[k++] = n;

    sort(x, x + k);
    k = unique(x, x + k) - x;
    n = lower_bound(x, x + k, n) - x + 1;

    sort(a, a + m);
    for (int i = 0; i < m; i++)
    {
        a[i].first = lower_bound(x, x + k, a[i].first) - x + 1;
        a[i].second = lower_bound(x, x + k, a[i].second) - x + 1;
    }

    f[1] = 1;
    for (int i = 2, j = 0; i <= n; i++)
    {
        f[i] = f[i - 1];
        while (j < m && a[j].first == i)
        {
            int x = f[a[j].first - 1] - f[a[j].second - 1];
            if (x < 0) x += MOD;
            if (x >= MOD) x -= MOD;

            f[i] += x;
            if (f[i] < 0) f[i] += MOD;
            if (f[i] >= MOD) f[i] -= MOD;
            j++;
        }
    }
    int ans = f[n] - f[n - 1];
    if (ans < 0) ans += MOD;
    if (ans >= MOD) ans -= MOD;
    printf("%d\n", ans);
    return 0;
}