#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        int n, a[105];
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int mx = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int f = a[i], s = a[j], d = j - i;
                int cnt = 2;
                for (int k = j + 1; k <= n; k++) {
                    if (s * d + (s - f) * (k - j) == a[k] * d) cnt++;
                }
                mx = max(mx, cnt);
            }
        }
        printf("%lld\n", n - mx);

    }

    return 0;
}