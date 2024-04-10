#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 100005;

int t, n, m, a[MN], b[MN], c[MN], leaf[MN];

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) leaf[i] = 0;
        for (int i = 1; i <= m; i++) cin >> a[i] >> b[i] >> c[i], leaf[b[i]] = 1;
        int cen = 0;
        for (int i = 1; i <= n; i++) if (!leaf[i]) cen = i;
        for (int i = 1; i <= n; i++) if (i != cen) printf("%lld %lld\n", i, cen);
    }

    return 0;
}