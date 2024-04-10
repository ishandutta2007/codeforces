#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long long ull;
const int maxn = (int)1e6 + 100;
const ll inf = (1ll<<60);
const int mod2 = (int)998244353;
const int mod = (int)1e9 + 7;
int n, m;
vector<ll> b;
vector<ll> c;

void add(ll x) {
    for(int i = 0; i < b.size(); i++) {
        if(c[i] & x) {
            x ^= b[i];
        }
    }
    if(x > 0) {
        ll y = 1;
        while(!(x & y)) y*=2;
        for(int i = 0; i < b.size(); i++) {
            if(b[i] & y) {
                b[i] ^= x;
            }
        }
        b.push_back(x);
        c.push_back(y);
    }
}
ll d[maxn];
int u[maxn];
vector< pair<ll, ll> > g[maxn];
vector<int> ord;
void dfs(int v) {
    u[v] = 1;
    ord.push_back(v);
    for(auto to: g[v]) {
        if(u[to.first] == 0) {
            d[to.first] = d[v] ^ to.second;
            dfs(to.first);
        } else if(u[to.first] == 1) {
            add(d[v] ^ d[to.first] ^ to.second);
        }
    }
    u[v] = 2;
}
void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        ll x, y, z;
        cin >> x >> y >> z;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        if(u[i]) continue;
        b.clear();
        c.clear();
        ord.clear();
        dfs(i);
        ll sz = ord.size();
        ll C = sz * (sz-1)/2;
        C %= mod;
        for(int j = 1; j < b.size(); j++) C = (C * 2) % mod;
        for(int j = 0; j <= 60; j++) {
            int ok = 0;
            ll cur = (1ll<<j);
            for(ll x: b) {
                if(x&cur) {
                    ok=1;
                }
            }
            if(ok) {
                ans = (ans + cur % mod * C % mod) % mod;
            } else {
                ll cnt=0;
                for(int v: ord) {
                    if(d[v] & cur) {
                        cnt++;
                    }
                }
                ll cur_ans = cnt * (sz - cnt) % mod;
                cur_ans = (cur % mod * cur_ans) % mod;
                for(int j = 0; j < b.size(); j++) {
                    cur_ans = (cur_ans * 2) % mod;
                }
                ans += cur_ans;
                ans %= mod;
            }

        }
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}