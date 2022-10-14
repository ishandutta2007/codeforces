#include <bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define puu pair<unsigned, unsigned>
#define ll long long
#define mp make_pair
#define ui unsigned
#define ull unsigned long long
#define ld double
#define pld pair<ld, ld>
#define pll pair<ll, ll>

const int INF = 1e9 + 1;
const ll INFLL = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto &c : a) cin >> c;
    vector<pair<vector<int>, int>> with(n);
    for (int i = 0; i < n; i++) with[i].se = i;
    while (m--) {
        int v, u;
        cin >> u >> v;
        u--; v--;
        with[v].fi.pb(u);
    }
    for (auto &c : with) sort(all(c.fi));
    sort(all(with));
    int i = 0;
    while (with[i].fi.empty()) i++;
    ll ans = 0;
    for (; i < n; i++) {
        int j = i;
        ll sum = a[with[i].se];
        while (j + 1 < n && with[j + 1].fi == with[j].fi) {
            j++;
            sum += a[with[j].se];
        }
        ans = __gcd(ans, sum);
        i = j;
    }
    cout << ans << "\n";
}

int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}