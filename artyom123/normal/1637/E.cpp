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
    map<int, int> cnt;
    vector<int> a(n);
    for (auto &c : a) {
        cin >> c;
        cnt[c]++;
    }
    vector<vector<int>> fixedcnt(n + 1);
    vector<int> diffcnt;
    for (auto &c : cnt) {
        fixedcnt[c.se].pb(c.fi);
        diffcnt.pb(c.se);
    }
    for (auto &c : fixedcnt) {
        sort(all(c));
        reverse(all(c));
    }
    sort(all(diffcnt));
    diffcnt.resize(unique(all(diffcnt)) - diffcnt.begin());
    unordered_map<int, unordered_map<int, int>> ban;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        ban[x][y] = 1;
    }
    ll ans = 0;
    for (auto &c : cnt) {
        int x = c.fi;
        auto &b = ban[x];
        for (auto &d : diffcnt) {
            for (auto &y : fixedcnt[d]) {
                if (b.find(y) != b.end()) continue;
                if (y <= x) break;
                ans = max(ans, (ll)(x + y) * (c.se + d));
                break;
            }
        }
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