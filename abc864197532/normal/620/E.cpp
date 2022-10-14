#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
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
const int mod = 1e9 + 7, abc = 864197532, N = 400001, logN = 17;

vector <int> adj[N];
int in[N], out[N], c[N], _t = 0;

struct Seg {
    int l, r, m;
    lli val, lz;
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
        }
        val = lz = 0;
    }
    void pull() {val = ch[0]->val | ch[1]->val;}
    void push() {
        if (lz) {
            ch[0]->val = lz;
            ch[1]->val = lz;
            ch[0]->lz = lz;
            ch[1]->lz = lz;
        }
        lz = 0;
    }
    void set(int a, int b, lli v) {
        if (a <= l && r <= b) val = v, lz = v;
        else {
            push();
            if (a < m) ch[0]->set(a, b, v);
            if (m < b) ch[1]->set(a, b, v);
            pull();
        }
    }
    lli query(int a, int b) {
        if (a <= l && r <= b) return val;
        lli ans = 0;
        push();
        if (a < m) ans |= ch[0]->query(a, b);
        if (m < b) ans |= ch[1]->query(a, b);
        return ans;
    }
};

void dfs(int v, int pa) {
    in[v] = _t++;
    for (int u : adj[v]) if (u != pa) {
        dfs(u, v);
    }
    out[v] = _t++;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> c[i], c[i]--;
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0, -1);
    Seg root(0, 2 * n);
    for (int i = 0; i < n; ++i) {
        root.set(in[i], in[i] + 1, 1ll << c[i]);
        root.set(out[i], out[i] + 1, 1ll << c[i]);
    }
    while (q--) {
        int t, v, c;
        cin >> t >> v, v--;
        if (t == 1) {
            cin >> c, c--;
            root.set(in[v], out[v] + 1, 1ll << c);
        } else {
            cout << __builtin_popcountll(root.query(in[v], out[v] + 1)) << '\n';
        }
    }
}