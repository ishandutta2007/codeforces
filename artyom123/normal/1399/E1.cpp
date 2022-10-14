#include<bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pii pair<int, int>

const int INF = 2e9 + 1;

struct edge{
    int v, u, w;
    ll d;
    edge(){}
    edge(int v, int u, int w, ll d) : v(v), u(u), w(w), d(d) {}
    bool operator< (const edge &e) const {
        if (d != e.d) return d < e.d;
        if (v != e.v) return v < e.v;
        return u < e.u;
    }
};

vector<vector<int>> g;
map<pair<int, int>, int> ma;
vector<int> cnt;

void dfs(int v, int p) {
    bool is_leaf = true;
    for (auto &to : g[v]) {
        if (to != p) {
            is_leaf = false;
            dfs(to, v);
            ma[{min(v, to), max(v, to)}] = cnt[to];
            cnt[v] += cnt[to];
        }
    }
    if (is_leaf) cnt[v] = 1;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll need;
        cin >> need;
        g.clear();
        g.resize(n);
        cnt.assign(n, 0);
        ma.clear();
        vector<pii> e;
        vector<int> kek(n - 1);
        for (int i = 0; i < n - 1; i++) {
            int a, b, w;
            cin >> a >> b >> w; a--; b--;
            g[a].pb(b);
            g[b].pb(a);
            kek[i] = w;
            e.pb(min(a, b), max(a, b));
        }
        dfs(0, -1);
        set<edge> s;
        ll now = 0;
        for (int i = 0; i < n - 1; i++) {
            s.insert(edge(e[i].fi, e[i].se, kek[i], (ll)(kek[i] - kek[i] / 2) * (ma[{e[i].fi, e[i].se}])));
            now += (ll)kek[i] * ma[{e[i].fi, e[i].se}];
        }
        int ans = 0;
        while (now > need) {
            ans++;
            auto lol = *s.rbegin();
            s.erase(lol);
            now -= lol.d;
            lol.w /= 2;
            lol.d = (ll)(lol.w - lol.w / 2) * ma[{lol.v, lol.u}];
            s.insert(lol);
        }
        cout << ans << "\n";
    }
    return 0;
}