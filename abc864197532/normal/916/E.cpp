#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, abc = 864197532, N = 100008, logN = 18, K = 500, C = 100;

struct Seg {
    int l, r, m;
    lli val, lz;
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), lz(0), val(0) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
        }
    }
    void pull() {val = ch[0]->val + ch[1]->val;}
    void push() {
        if (r - l > 1 && lz) {
            ch[0]->val += lz * (m - l);
            ch[1]->val += lz * (r - m);
            ch[0]->lz += lz;
            ch[1]->lz += lz;
        }
        lz = 0;
    }
    void add(int a, int b, lli v) {
        if (a <= l && r <= b) val += v * (r - l), lz += v;
        else {
            push();
            if (a < m) ch[0]->add(a, b, v);
            if (m < b) ch[1]->add(a, b, v);
            pull();
        }
    }
    lli query(int a, int b) {
        if (a <= l && r <= b) return val;
        push();
        lli ans = 0;
        if (a < m) ans += ch[0]->query(a, b);
        if (m < b) ans += ch[1]->query(a, b);
        return ans;
    }
};

vector <int> adj[N];
int in[N], out[N], a[N], _t = 0, jump[N][logN];

void dfs(int v, int pa) {
    in[v] = _t++;
    jump[v][0] = pa;
    for (int u : adj[v]) if (u != pa) {
        dfs(u, v);
    }
    out[v] = _t++;
}

bool anc(int u, int v) {
    return in[u] <= in[v] && out[u] >= out[v];
}

int lca(int u, int v) {
    if (anc(u, v)) return u;
    if (anc(v, u)) return v;
    for (int i = logN - 1; ~i; --i) {
        int k = jump[u][i];
        if (k == -1) continue;
        if (!anc(k, v)) u = k;
    }
    return jump[u][0];
}

void build() {
    for (int i = 0; i < N; ++i) jump[i][0] = -1;
    dfs(0, -1);
    for (int j = 1; j < logN; ++j) {
        for (int i = 0; i < N; ++i) {
            if (jump[i][j - 1] == -1) continue;
            jump[i][j] = jump[jump[i][j - 1]][j - 1];
        }
    }
}

int get(int u, int v) {
    for (int i = logN - 1; ~i; --i) {
        int k = jump[u][i];
        if (k != -1 && anc(v, k) && v != k) u = k;
    }
    return u;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    build();
    Seg root(0, n * 2);
    for (int i = 0; i < n; ++i) root.add(in[i], in[i] + 1, a[i]), root.add(out[i], out[i] + 1, a[i]);
    int rt = 0;
    while (q--) {
        int t, u, v, x;
        cin >> t;
        if (t == 1) {
            cin >> rt, rt--;
        } else if (t == 2) {
            cin >> u >> v >> x, --u, --v;
            if (anc(rt, u) && anc(rt, v)) {
                int k = lca(u, v);
                if (rt == k) root.add(0, n * 2, x);
                else root.add(in[k], out[k] + 1, x);
            } else if (anc(rt, u) || anc(rt, v)) {
                root.add(0, n * 2, x);
            } else {
                int k = lca(u, v);
                if (anc(k, rt)) {
                    int lu = lca(rt, u), lv = lca(rt, v);
                    if (anc(lv, lu)) swap(lv, lu);
                    if (lv == rt) {
                        root.add(0, n * 2, x);
                    } else {
                        lv = get(rt, lv);
                        root.add(0, n * 2, x);
                        root.add(in[lv], out[lv] + 1, -x);
                    }
                } else {
                    root.add(in[k], out[k] + 1, x);
                }
            }
        } else {
            cin >> v, --v;
            if (v == rt) cout << root.query(0, n * 2) / 2 << endl;
            else if (anc(v, rt)) {
                int k = get(rt, v);
                cout << (root.query(0, n * 2) - root.query(in[k], out[k] + 1)) / 2 << endl;
            } else {
                cout << root.query(in[v], out[v] + 1) / 2 << endl;
            }
        }
    }
}