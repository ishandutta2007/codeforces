#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a){
    return o << a.X << ' ' << a.Y;
}
template<typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a){
    return o >> a.X >> a.Y;
}
const int mod = 1e9 + 7, abc = 864197532, Doludu = 123, N = 200001, K = 111;

struct edge {
    int u, v, w;
    bool operator < (const edge &o) {
        return w > o.w;
    }
};

struct Dsu {
    vector <int> dsu;
    vector <bool> tag;
    int n;
    Dsu (int _n) : n(_n) {
        dsu.resize(n);
        tag.resize(n, false);
        iota(all(dsu), 0);
    }
    int Find(int x) {
        if (dsu[x] == x) return x;
        return dsu[x] = Find(dsu[x]);
    }
    bool Union(int u, int v) {
        u = Find(u), v = Find(v);
        if (u == v) {
            if (tag[u]) return false;
            return tag[u] = true;
        }
        if (tag[u] && tag[v]) return false;
        dsu[u] = v;
        if (tag[u]) tag[v] = true;
        return true;
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <edge> E(m);
    for (int i = 0; i < m; ++i) cin >> E[i].u >> E[i].v >> E[i].w, E[i].u--, E[i].v--;
    sort(all(E));
    Dsu dsu(n);
    int ans = 0;
    for (edge &e : E) {
        if (dsu.Union(e.u, e.v)) ans += e.w;
    }
    cout << ans << endl;
}