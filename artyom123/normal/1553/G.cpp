#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double
#define mp make_pair
#define ull unsigned long long

const int INF = 1e9 + 1;
const ll INFLL = (ll)1e18 + 1;
const int MAXN = 1e6 + 5;

struct DSU {
    vector<int> p, sz;

    DSU() {}
    DSU(int n) {
        p.resize(n);
        sz.resize(n, 1);
        iota(all(p), 0);
    }

    int get_par(int v) {
        if (p[v] == v) return v;
        return p[v] = get_par(p[v]);
    }

    void merge(int v, int u) {
        v = get_par(v);
        u = get_par(u);
        if (v == u) return;
        if (sz[v] < sz[u]) swap(v, u);
        p[u] = v;
        sz[v] += sz[u];
    }
};

vector<int> e(MAXN);

void calc() {
    vector<int> p;
    for (int i = 2; i < MAXN; i++) {
        if (e[i] == 0) {
            e[i] = i;
            p.pb(i);
        }
        for (int j = 0; j < (int)p.size() && p[j] <= e[i] && p[j] * i < MAXN; j++) {
            e[i * p[j]] = p[j];
        }
    }
}

vector<int> fact(int n) {
    vector<int> p;
    while (n != 1) {
        p.pb(e[n]);
        n = n / e[n];
    }
    return p;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    calc();
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    DSU d(n);
    vector<int> id(MAXN, -1);
    vector<int> kek(MAXN, -1);
    for (int i = 0; i < n; i++) id[a[i]] = i;
    for (int k = 2; k < MAXN; k++) {
        vector<int> pos;
        for (int i = k; i < MAXN; i += k) {
            if (id[i] != -1) {
                pos.pb(id[i]);
                kek[k] = id[i];
            }
        }
        for (int i = 1; i < (int)pos.size(); i++) d.merge(pos[0], pos[i]);
    }
    vector<set<int>> g(n);
    for (int i = 0; i < n; i++) {
        vector<int> p1 = fact(a[i] + 1);
        vector<int> p2 = fact(a[i]);
        vector<int> lol;
        for (auto &c : p1) lol.pb(c);
        for (auto &c : p2) lol.pb(c);
        for (auto &c1 : lol) {
            for (auto &c2 : lol) {
                if (kek[c1] != -1 && kek[c2] != -1) {
                    g[d.get_par(kek[c1])].insert(d.get_par(kek[c2]));
                    g[d.get_par(kek[c2])].insert(d.get_par(kek[c1]));
                }
            }
        }
    }
    while (q--) {
        int s, t;
        cin >> s >> t;
        s--; t--;
        s = d.get_par(s);
        t = d.get_par(t);
        if (s == t) cout << 0 << "\n";
        else if (g[s].count(t)) cout << 1 << "\n";
        else cout << 2 << "\n";
    }
    return 0;
}