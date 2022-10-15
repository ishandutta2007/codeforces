#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define int ll
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 200005;

int t, n, a[MN];

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int sum = 0, mx = 0;
        for (int i = 2; i <= n; i++) sum += abs(a[i] - a[i - 1]);
        for (int i = 2; i < n; i++) {
            int old = abs(a[i] - a[i - 1]) + abs(a[i + 1] - a[i]);
            int nw = abs(a[i + 1] - a[i - 1]);
            mx = max(mx, old - nw);
        }
        mx = max(mx, abs(a[2] - a[1]));
        mx = max(mx, abs(a[n] - a[n - 1]));
        printf("%lld\n", sum - mx);
    }

    return 0;
 }