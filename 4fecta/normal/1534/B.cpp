#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 400005;

int t, n, a[MN];

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int sum = 0;
        for (int i = 1; i <= n + 1; i++) sum += abs(a[i] - a[i - 1]);
        for (int i = 1; i <= n; i++) {
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) sum -= a[i] - max(a[i - 1], a[i + 1]);
        }
        printf("%lld\n", sum);
        for (int i = 1; i <= n; i++) a[i] = 0;
    }

    return 0;
}