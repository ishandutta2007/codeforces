#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i = (m); i < (n); ++i)
#define FOP(i,m,n) for (int i = (m) - 1; i >= (n); --i)
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
const int mod = 1e9 + 7, x = 864197532, N = 100087, logN = 20;

vector <pair <int, lli>> adj[N];
lli dep[N];
vector <int> tree;
int in[N], out[N];

struct Seg {
    int l, r, m;
    lli dp[5] = {0, 0, 0, 0, 0}, lz;
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
        }
        lz = 0;
    }
    void add(lli v) {
        dp[0] += v;
        dp[1] -= v * 2;
        dp[2] -= v;
        dp[3] -= v;
    }
    void pull() {
        fop (i,0,5) dp[i] = max(ch[0]->dp[i], ch[1]->dp[i]);
        dp[2] = max(dp[2], ch[0]->dp[0] + ch[1]->dp[1]);
        dp[3] = max(dp[3], ch[0]->dp[1] + ch[1]->dp[0]);
        dp[4] = max({dp[4], ch[0]->dp[2] + ch[1]->dp[0], ch[0]->dp[0] + ch[1]->dp[3]});
    }
    void push() {
        if (r - l > 1 && lz) {
            ch[0]->add(lz);
            ch[0]->lz += lz;
            ch[1]->add(lz);
            ch[1]->lz += lz;
        }
        lz = 0;
    }
    void modify(int a, int b, lli v) {
        if (a <= l && r <= b) {
            add(v); lz += v;
        } else {
            push();
            if (a < m) ch[0]->modify(a, b, v);
            if (m < b) ch[1]->modify(a, b, v);
            pull();
        }
    }
};

void dfs(int v, int pa, lli w = 0) {
    in[v] = tree.size();
    tree.pb(v);
    dep[v] = ~pa ? dep[pa] + w : 0;
    for (pair <int, lli> A : adj[v]) if (A.X != pa) {
        dfs(A.X, v, A.Y);
        tree.pb(v);
    }
    out[v] = tree.size();
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q, u, v;
    lli w, ww;
    cin >> n >> q >> w;
    vector <pii> E;
    vector <lli> V;
    fop (i,0,n - 1) {
        cin >> u >> v >> ww, u--, v--;
        adj[u].eb(v, ww);
        adj[v].eb(u, ww);
        E.eb(u, v);
        V.eb(ww);
    }
    dfs(0, -1);
    for (pii &A : E) {
        if (in[A.X] > in[A.Y]) swap(A.X, A.Y);
    }
    Seg root(0, tree.size());
    fop (i,0,tree.size()) {
        root.modify(i, i + 1, dep[tree[i]]);
    }
    lli last = 0;
    while (q--) {
        cin >> v >> ww;
        v = (last + v) % (n - 1);
        ww = (last + ww) % w;
        root.modify(in[E[v].Y], out[E[v].Y], ww - V[v]);
        V[v] = ww;
        last = root.dp[4];
        cout << last << '\n';
    }
}