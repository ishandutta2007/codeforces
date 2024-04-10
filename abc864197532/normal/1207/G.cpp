#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 400100, logN = 20, M = 6e6;

vector <pair <int, char>> adj[N];

struct AC {
    int ch[N][26], to[N][26], sz, fail[N], in[N], out[N], _t;
    vector <int> g[N];
    AC () {sz = 0, _t = 0, extend();}
    void extend() {
        fill(ch[sz], ch[sz] + 26, 0), sz++;
    }
    int nxt(int u, int v) {
        if (!ch[u][v]) {
            ch[u][v] = sz, extend();
        }
        return ch[u][v];
    }
    int insert(string s) {
        int now = 0;
        for (char c : s)
            now = nxt(now, c - 'a');
        return now;
    }
    void build_fail() {
        queue <int> q;
        for (int i = 0; i < 26; ++i) if (ch[0][i])
            q.push(ch[0][i]), g[0].pb(ch[0][i]);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int j = 0; j < 26; ++j) {
                if (ch[v][j])
                    to[v][j] = v;
                else
                    to[v][j] = to[fail[v]][j];
            }
            for (int i = 0; i < 26; ++i) if (ch[v][i]) {
                int u = ch[v][i], k = fail[v];
                while (k && !ch[k][i])
                    k = fail[k];
                if (ch[k][i])
                    k = ch[k][i];
                fail[u] = k;
                // cnt[u] += cnt[k]
                g[k].pb(u);
                q.push(u);
            }
        }
    }
    void dfs(int v) {
        in[v] = _t++;
        for (int u : g[v])
            dfs(u);
        out[v] = _t++;
    }
} ac;

vector <pii> Q[N];
int ans[N];

template <typename T>
struct BIT {
    // single point add, prefix query sum
    vector <T> val;
    int n, offset;
    BIT () = default;
    BIT (int _n, int _offset = 3) : n(_n + _offset * 2), offset(_offset) {
        val.assign(n, 0);
    }
    void add(int p, T v) {
        for (p += offset; p < n; p += p & (-p))
            val[p] += v;
    }
    T query(int p) {
        T ans = 0;
        for (p += offset; p > 0; p -= p & (-p))
            ans += val[p];
        return ans;
    }
    T query(int l, int r) {
        // query [l, r)
        return query(r - 1) - query(l - 1);
    }
    int kth (int k) {
        // 1-index, return kth smallest number
        // 1 <= k && k <= current size
        int ans = 0;
        for (int i = 1 << __lg(n); i > 0; i >>= 1) {
            if (ans + i < n && val[ans + i] < k) k -= val[ans += i];
        }
        return ans - offset + 1;
    }
};

BIT <int> root(N * 2);

void dfs(int v, int now) {
    for (auto [pos, id] : Q[v]) {
        ans[id] = root.query(ac.in[pos], ac.out[pos] + 1);
    }
    for (auto [u, c] : adj[v]) {
        int nxt = ac.to[now][c - 'a'];
        if (ac.ch[nxt][c - 'a'])
            nxt = ac.ch[nxt][c - 'a'];
        root.add(ac.in[nxt], 1);
        dfs(u, nxt);
        root.add(ac.in[nxt], -1);
    }
}

int main () {
    owo;
    int n;
    cin >> n;
    for (int i = 1, ty, p; i <= n; ++i) {
        char c; cin >> ty;
        if (ty == 1)
            p = 0;
        else
            cin >> p;
        cin >> c;
        adj[p].eb(i, c);
    }
    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        int p; string s; cin >> p >> s;
        int now = ac.insert(s);
        Q[p].eb(now, i);
    }
    ac.build_fail();
    ac.dfs(0);
    dfs(0, 0);
    for (int i = 0; i < q; ++i)
        cout << ans[i] << '\n';
}