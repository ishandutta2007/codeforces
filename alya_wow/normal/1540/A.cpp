#include <bits/stdc++.h>
#define fr first
#define sc second
#define m_p make_pair
#define all(x) (x).begin(), (x).end()
#define unique(a) a.resize(unique(a.begin(), a.end()) - a.begin())
#define low_bo(a, x) ((int)(lower_bound(a.begin(), a.end(), x) - a.begin()))
#define up_bo(a, x) ((int)(upper_bound(a.begin(), a.end(), x) - a.begin()))

using namespace std;

mt19937 rnd(223);

#define TIME (clock() * 1.0 / CLOCKS_PER_SEC)
using ll = long long;
using ld = double;

const int maxn = 1e5 + 100, inf = 1e9 + 100;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        sort(all(a));
        ll ans = a.back();
        for (int i = 0; i < n; i++) {
            ans += a[i] * (ll)((n - i - 1) - i);
        }
        cout << ans << '\n';
    }
}

int main() {
#ifdef ONPC
    freopen("../a.in", "r", stdin);
    //freopen("../a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout.precision(20);
    solve();
    cerr << "\n\nConsumed " << TIME;
}