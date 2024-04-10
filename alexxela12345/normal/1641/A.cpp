#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll

void solve() {
    int n, x;
    cin >> n >> x;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        m[a]++;
    }
    int ans = 0;
    while (!m.empty()) {
        auto pp = *m.begin();
        m.erase(m.begin());
        if (m.count(pp.first * x)) {
            if (m[pp.first * x] == 1) {
                m.erase(m.find(pp.first * x));
            } else {
                m[pp.first * x]--;
            }
        } else {
            ans++;
        }
        pp.second--;
        if (pp.second) {
            m.insert(pp);
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}