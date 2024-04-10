#include <cstdio>
#include <algorithm>

using namespace std;


const int MAXN = 100005;

int f[MAXN];
int g[MAXN];
int a[MAXN];
int n;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        a[i] = (int)1e+9;
        for (int k = 2; k <= i; k++)
        {
            int x = 2 * i + k - k * k;
            if (x <= 0) break;
            if (x % (2 * k)) continue;
            x /= 2 * k;

            int G = g[x + k - 1] ^ g[x - 1];
            f[G] = i;
            if (G == 0)
                a[i] = min(a[i], k);
        }
        while (f[g[i]] == i) g[i]++;
        g[i] ^= g[i - 1];
    }
    printf("%d\n", (g[n] ^ g[n - 1])? a[n] : -1);
    return 0;
}