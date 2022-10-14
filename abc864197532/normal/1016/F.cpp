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
const int mod = 1e8 + 7, abc = 864197532, N = 300087, K = 111;

struct Seg {
    int l, r, m, cnt;
    lli val, mx;
    Seg* ch[2];
    Seg (int _l, int _r, vector <lli> &a) : l(_l), r(_r), m(l + r >> 1), cnt(0), mx(0) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m, a);
            ch[1] = new Seg(m, r, a);
            pull();
        } else {
            mx = val = a[l];
        }
    }
    void pull() {
        if (!cnt) mx = (r - l > 1 ? max(ch[0]->mx, ch[1]->mx) : val);
        else mx = -1ll << 60;
    }
    void add(int a, int b, int v) {
        if (a <= l && r <= b) {
            cnt += v;
        } else {
            if (a < m) ch[0]->add(a, b, v);
            if (m < b) ch[1]->add(a, b, v);
        }
        pull();
    }
};

vector <pii> adj[N];
lli dep[N], mx, curdep;
int in[N], out[N], _t, sz[N];

void dfs1(int v, int pa) {
    in[v] = _t++;
    sz[v] = 1;
    for (auto [u, w] : adj[v]) if (u != pa) {
        dep[u] = dep[v] + w;
        dfs1(u, v);
        sz[v] += sz[u];
    }
    out[v] = _t;
}

Seg* root;

void dfs2(int v, int pa) {
    sz[v] = 1;
    root->add(in[v], out[v], 1);
    for (auto [u, w] : adj[v]) {
        root->add(in[u], in[u] + 1, 1);
    }
    mx = max(mx, curdep + root->mx);
    for (auto [u, w] : adj[v]) {
        root->add(in[u], in[u] + 1, -1);
    }
    for (auto [u, w] : adj[v]) if (u != pa) {
        curdep += w;
        dfs2(u, v);
        sz[v] += sz[u];
        curdep -= w;
    }
    root->add(in[v], out[v], -1);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 0, u, v, w; i < n - 1; ++i) {
        cin >> u >> v >> w, u--, v--;
        adj[u].eb(v, w);
        adj[v].eb(u, w);
    }
    dfs1(0, -1);
    bool re = (sz[n - 1] >= 3);
    vector <lli> tmp(n);
    for (int i = 0; i < n; ++i) tmp[in[i]] = dep[i];
    root = new Seg(0, n, tmp);
    dfs2(n - 1, -1);
    re |= sz[0] >= 3;
    while (q--) {
        int x;
        cin >> x;
        if (re) cout << dep[n - 1] << endl;
        else cout << min(dep[n - 1], x + mx) << endl;
    }
}