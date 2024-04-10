#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#define int ll
using namespace std;
using ll = long long;
using ld = double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using ull = unsigned long long;

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define x first
#define y second
//#define int ll

const int maxn = 5e5;
const int mod = 998244353;
const int M = 1e9 + 7;
const int inf = 1e9;
const ll inf64 = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-6;
const int BL = 317;

int pw[maxn + 1];

struct DSU {
    vi p, s, v1, v2; int c;
    DSU(int n) : p(n), s(n, 1), c(n) { iota(all(p), 0); }
    int get(int v) { return p[v]==v?v:p[v]=get(p[v]); }
    int unite(int u, int v) {
        if((u=get(u)) != (v=get(v))) {
            if(s[u] < s[v]) swap(u, v);
            p[v] = u; s[u] += s[v];
            v1.pb(u); v2.pb(v); c--;
        }
    }
    void rest() {
        while(sz(v1)) {
            int u = v1.back(), v = v2.back();
            v1.pop_back(); v2.pop_back();
            p[v] = v; s[u] -= s[v]; c++;
        }
    }
};

int n, m, k;
ll c[maxn];
map<ll, int> re;
int u[maxn], v[maxn];
vi g[maxn];

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    pw[0] = 1;
    for(int i = 0; i < maxn; i++) pw[i + 1] = 2 * pw[i] % M;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) cin >> c[i];
    for(int i = 0; i < m; i++) {
        cin >> u[i] >> v[i];
        u[i]--; v[i]--;
        re[c[u[i]] ^ c[v[i]]];
    }
    int dif = 0;
    for(auto it = re.begin(); it != re.end(); it++) it->y = dif++;
    ll ans = 1LL * pw[n] * ((pw[k] - dif + M) % M) % M;
    for(int i = 0; i < m; i++) g[re[c[u[i]] ^ c[v[i]]]].pb(i);
    DSU dsu(n);
    for(int i = 0; i < dif; i++) {
        for(int j : g[i]) dsu.unite(u[j], v[j]);
        ans = (ans + pw[dsu.c]) % M;
        dsu.rest();
    }
    cout << ans;
}