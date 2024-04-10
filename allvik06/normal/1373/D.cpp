#include <bits/stdc++.h>

using namespace std;
#define int long long
#define f first
#define s second
const int INF = 1e15;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (i % 2 == 0) a[i] = -a[i];
        }
        vector <int> pref(n);
        vector <pair <int, int>> maxx(n + 1, {-INF, -INF});
        pref[0] = a[0];
        for (int i = 1; i < n; ++i) {
            pref[i] = pref[i - 1] + a[i];
        }
        for (int i = n - 1; i >= 0; --i) {
            maxx[i] = maxx[i + 1];
            if (i % 2 == 0) maxx[i].f = max(maxx[i].f, pref[i]);
            else maxx[i].s = max(maxx[i].s, pref[i]);
        }
        int ans = 0, res = 0;
        for (int i = 0; i < n; i += 2) ans -= a[i];
        res = max(res, maxx[0].s);
        for (int i = 1; i < n; ++i) {
            if (i % 2 == 0) res = max(res, maxx[i].s - pref[i - 1]);
            else res = max(res, maxx[i].f - pref[i - 1]);
        }
        cout << ans + res << "\n";
    }
}