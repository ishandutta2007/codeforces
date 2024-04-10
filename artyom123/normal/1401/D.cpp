#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;
const int mod = 1e9 + 7;

vector<vector<int>> g;

vector<int> sz;

void dfs(int v, int p) {
    sz[v] = 1;
    for (auto &to : g[v]) {
        if (to != p) {
            dfs(to, v);
            sz[v] += sz[to];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        g.clear();
        g.resize(n);
        vector<pii> e;
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b; a--; b--;
            e.pb(a, b);
            g[a].pb(b); g[b].pb(a);
        }
        sz.assign(n, 0);
        dfs(0, -1);
        vector<ll> cnt;
        for (auto &c : e) {
            ll mn = min(sz[c.fi], sz[c.se]);
            cnt.pb(mn * (n - mn));
        }
        sort(all(cnt));
        reverse(all(cnt));
        //for (auto &c : cnt) cout << '!' << " " << c << endl;
        int m;
        cin >> m;
        vector<ll> p(m);
        for (auto &c : p) cin >> c;
        sort(all(p));
        reverse(all(p));
        ll ans = 0;
        if (m >= n - 1) {
            int kek = m - (n - 2);
            ll lol = 1;
            for (int i = 0; i < kek; i++) {
                lol *= p[i];
                lol %= mod;
            }
            ans += lol * cnt[0];
            ans %= mod;
            for (int i = 1; i < n - 1; i++) {
                ans += cnt[i] * p[kek + i - 1];
                ans %= mod;
            }
        } else {
            for (int i = 0; i < m; i++) {
                ans += cnt[i] * p[i];
                ans %= mod;
            }
            for (int i = m; i < n - 1; i++) {
                ans += cnt[i];
                ans %= mod;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}