#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 2; i <= n; i++)
        cin >> p[i];
    vector<ll> l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];
    int ans = 0;
    vector<ll> val(n + 1);
    for (int i = n; i >= 1; i--) {
        if (l[i] > val[i]) {
            ++ans;
            val[i] = r[i];
        }
        val[p[i]] += min(val[i], r[i]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}