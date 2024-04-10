#include <bits/stdc++.h>
using namespace std;
#define ll long long int
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
    vv (int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv (int n, int m) : vector <vector <T>> (n, vector <T>(m)) {}
    vv () {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv (int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv (int n, int m, int k) : vector <vv <T>> (n, vv <T>(m, k)) {}
    vvv () {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 1 << 20;

template <typename T>
struct SparseTableMin {
    // 0-indexed, [l, r)
    int table[N << 1][22];
    SparseTableMin () = default;
    SparseTableMin (vector <T> a) {
        int n = a.size();
        int m = __lg(n) + 1;
        for (int i = 0; i < n; ++i)
            table[i][0] = a[i];
        for (int j = 1; j < m; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                table[i][j] = min(table[i][j - 1], table[i + (1 << j - 1)][j - 1]);
            }
        }
    }
    T query(int l, int r) {
        if (l >= r)
            return 1 << 30;
        int g = __lg(r - l);
        return min(table[l][g], table[r - (1 << g)][g]);
    }
};

vector <int> adj[N];
int ord[N << 1], in[N], out[N], dep[N], _t;

void dfs(int v, int pa) {
    in[v] = _t;
    ord[_t++] = v;
    for (int u : adj[v]) if (u != pa) {
        dep[u] = dep[v] + 1;
        dfs(u, v);
        ord[_t++] = v;
    }
    out[v] = _t;
}

void solve() {
    int n, q;
    cin >> n;
    for (int i = 1, x; i < n; ++i) {
        cin >> x, --x;
        adj[x].pb(i), adj[i].pb(x);
    }
    dfs(0, -1);
    vector <int> val;
    for (int i = 0; i < _t; ++i) {
        val.pb(dep[ord[i]]);
    }
    SparseTableMin <int> ST(val);
    auto dis = [&](int u, int v) {
        if (in[u] > in[v])
            swap(u, v);
        return dep[u] + dep[v] - ST.query(in[u], out[v]) * 2;
    };
    vector <int> f(n, -1);
    vector <vector <int>> block;
    vector <pii> dia;
    {
        queue <int> q;
        for (int i = 0; i < n; ++i) if (adj[i].size() == 1) {
            q.push(i), f[i] = 0;
        }
        while (!q.empty()) {
            int v = q.front(); q.pop();
            if (f[v] == block.size())
                block.pb({});
            block[f[v]].pb(v);
            for (int u : adj[v]) if (f[u] == -1) {
                q.push(u), f[u] = f[v] + 1;
            }
        }
    }
    int mx = block.size();
    dia.resize(mx, mp(-1, -1));
    auto upd = [&](pii a, int v) {
        if (a.first == -1)
            return mp(v, -1);
        if (a.second == -1)
            return mp(a.first, v);
        int val[3] = {dis(a.first, a.second), dis(a.first, v), dis(v, a.second)};
        int p = max_element(val, val + 3) - val;
        if (p == 1)
            a.second = v;
        if (p == 2)
            a.first = v;
        return a;
    };
    for (int i = mx - 1; ~i; --i) {
        if (i + 1 < mx)
            dia[i] = dia[i + 1];
        for (int v : block[i])
            dia[i] = upd(dia[i], v);
    }
    auto get = [&](int i, int v) {
        if (dia[i].second == -1)
            return dis(dia[i].first, v);
        return max(dis(dia[i].first, v), dis(dia[i].second, v));
    };
    cin >> q;
    while (q--) {
        int x; cin >> x;
        int ans = 0;
        for (int i = 0; i < mx; ++i) {
            // i + j + x >= ans
            // j >= ans - i - x
            for (int v : block[i]) {
                while (true) {
                    int j = max(ans + 1 - i - x, 0);
                    if (j >= mx)
                        break;
                    if (get(j, v) >= ans + 1) {
                        ans++;
                    } else
                        break;
                }
            }
        }
        cout << ans << " \n"[q == -1];
    }
}

int main () {
    owo;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}