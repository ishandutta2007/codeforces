#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>

using namespace std;


const int MAXN = 2000000;

long long a[MAXN];
long long l[MAXN], r[MAXN];
long long f[MAXN], g[MAXN], c[MAXN];
long long k, len;
int n, m;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    scanf("%d %I64d", &n, &k);
    len = (long long)9e+18;
    for (int i = 0; i < n; i++)
    {
        scanf("%I64d %I64d", &l[i], &r[i]);
        len = min(len, r[i] - l[i]);
    }

    m = 0;
    for (int i = 1; i <= 19; i++)
    {
        for (int j = 0; j < (1 << i); j++)
        {
            long long x = 0;
            for (int k = i - 1; k >= 0; k--)
            {
                (x *= 10) += 4;
                if (j & (1 << k)) x += 3;
            }
            a[++m] = x;
        }
    }

    sort(r, r + n);
    for (int i = 0; i <= m + 1; i++) c[i] = 0;
    for (int i = 1, j = 0; i <= m; i++)
    {
        c[i] = c[i - 1];
        f[i] =
            c[i - 1] <= (k + 1) / (a[i] - a[i - 1])?
                (a[i] - a[i - 1]) * c[i - 1] + f[i - 1] : k + 1;

        while (j < n && r[j] <= a[i])
        {
            c[i]++;
            f[i] += a[i] - r[j];
            j++;
        }

        if (f[i] > k) f[i] = k + 1;
    }

    sort(l, l + n);
    reverse(l, l + n);

    for (int i = 0; i <= m + 1; i++) c[i] = 0;
    for (int i = m, j = 0; i >= 1; i--)
    {
        c[i] = c[i + 1];
        g[i] =
            c[i + 1] <= (k + 1) / (a[i + 1] - a[i])?
                (a[i + 1] - a[i]) * c[i + 1] + g[i + 1] : k + 1;

        while (j < n && a[i] <= l[j])
        {
            c[i]++;
            g[i] += l[j] - a[i];
            j++;
        }

        if (g[i] > k) g[i] = k + 1;
    }


    int ans = 0;
    for (int i = 1, j = 1; i <= m; i++)
    {
        while (g[i] + f[j] <= k && a[j] <= a[i] + len) j++;
        ans = max(ans, j - i);
    }
    printf("%d\n", ans);
                           
    fprintf(stderr, "Time of execution: %.3lf sec.\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}