#include <cstdio>
#include <algorithm>
#include <ctime>

using namespace std;

const int MAXN = 20003;

int a[MAXN], f[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    int n;
    int ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        ans += a[i];
    }
    for (int i = 1; i <= n / 3; i++)
        if (n % i == 0)
        {
            for (int j = 0; j < i; j++)
                f[j] = 0;

            for (int j = 0; j < n; j++)
                f[j % i] += a[j];

            for (int j = 0; j < i; j++)
                ans = max(ans, f[j]);
        }
    printf("%d\n", ans);

    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}