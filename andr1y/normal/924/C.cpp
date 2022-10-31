#include <cstdio>
#include <algorithm>

typedef long long int64;
static const int MAXN = 1e5 + 4;

static int n, m[MAXN];
static int t[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &m[i]);

    for (int i = n - 1, cur = 0; i >= 0; --i) {
        cur = std::max(0, cur - 1);
        cur = std::max(cur, m[i] + 1);
        t[i] = cur;
    }

    int64 ans = 0;
    for (int i = 0, cur = 0; i < n; ++i) {
        cur = std::max(cur, t[i]);
        ans += cur;
    }

    for (int i = 0; i < n; ++i) ans -= (m[i] + 1);
    printf("%lld\n", ans);

    return 0;
}