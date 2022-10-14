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
const int mod = 1e9 + 7, abc = 864197532, N = 1000087, K = 111;

int adj[N][26];
bool choose[N];
int id[N], in[N], out[N], order[N], t, _t;

void dfs(int v) {
    in[v] = t++;
    id[v] = _t;
    if (choose[v]) id[v]++, _t++;
    for (int c = 0; c < 26; ++c) if (adj[v][c]) {
        dfs(adj[v][c]);
    }
    out[v] = t;
}

struct Seg {
    int l, r, m, val;
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), val(1 << 30) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
        }
    }
    void modify(int a, int b, int v) {
        if (a <= l && r <= b) val = min(val, v);
        else {
            if (a < m) ch[0]->modify(a, b, v);
            if (m < b) ch[1]->modify(a, b, v);
        }
    }
    int query(int p) {
        if (r - l == 1) return val;
        return min(val, ch[p >= m]->query(p));
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, p, m;
    cin >> n;
    char ch;
    for (int i = 1; i <= n; ++i) {
        cin >> p >> ch;
        adj[p][ch - 'a'] = i;
    }
    cin >> m;
    for (int i = 1, x; i <= m; ++i) cin >> x, choose[x] = true, order[x] = i;
    dfs(0);
    /*
     * from i to j
     * dis[j] = dis[i] + id[j] - id[i];
     * store dis[i] - id[i] min
     * dis[j] = id[j] + mn
     */
    Seg root(0, n + 1);
    queue <int> q;
    vector <int> dis(n + 1, 1 << 30);
    q.push(0);
    dis[0] = 0;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        root.modify(in[v], out[v], dis[v] - id[v] + choose[v]);
        for (int c = 0; c < 26; ++c) if (adj[v][c]) {
            int u = adj[v][c];
            dis[u] = min(dis[u], dis[v] + 1);
            if (choose[u]) {
                dis[u] = min(dis[u], root.query(in[u]) + id[u]);
            }
            q.push(u);
        }
    }
    int ans[m + 1];
    for (int i = 1; i <= n; ++i) ans[order[i]] = dis[i];
    for (int i = 1; i <= m; ++i) cout << ans[i] << " \n"[i == m];
}