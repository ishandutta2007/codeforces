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
    while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    if (a.empty())
        return o << "{}";
    bool is = false;
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
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 200005, logN = 18;

vector <int> adj[N];
int jump[N][logN], in[N], out[N], sz[N], _t;

void dfs(int v, int pa) {
    jump[v][0] = pa;
    in[v] = _t++;
    sz[v] = 1;
    for (int u : adj[v]) if (u != pa) {
        dfs(u, v);
        sz[v] += sz[u]; 
    }
    out[v] = _t++;
}

void build(int n) {
    for (int i = 0; i < n; ++i) for (int j = 0; j < logN; ++j)
        jump[i][j] = -1;
    _t = 0;
    dfs(0, -1);
    for (int j = 1; j < logN; ++j) {
        for (int i = 0; i < n; ++i) {
            int k = jump[i][j - 1];
            if (~k)
                jump[i][j] = jump[k][j - 1];
        }
    }
}

bool anc(int u, int v) {
    return in[u] <= in[v] && out[u] >= out[v];
}

int lca(int u, int v) {
    if (anc(u, v))
        return u;
    if (anc(v, u))
        return v;
    for (int i = logN - 1; ~i; --i) {
        int k = jump[u][i];
        if (~k && !anc(k, v))
            u = k;
    }
    return jump[u][0];
}

int to(int v) {
    for (int i = logN - 1; ~i; --i) {
        int k = jump[v][i];
        if (~k && k)
            v = k;
    }
    return v;
}

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0, u, v; i < n - 1; ++i) {
            cin >> u >> v;
            adj[u].pb(v), adj[v].pb(u);
        }
        build(n);
        vector <lli> cnt(n + 1, 0);
        cnt[0] = 1ll * n * (n - 1) / 2;
        {
            int tmp = 0;
            for (int u : adj[0]) {
                cnt[1] += 1ll * tmp * sz[u];
                tmp += sz[u];
            }
            cnt[1] += n - 1;
        }
        int a = -1, b = -1;
        auto add = [&](int v) {
            if (a == -1 && b == -1) {
                a = v;
                return true;
            }
            if (~a && anc(a, v)) {
                a = v;
                return true;
            }
            if (~a && anc(v, a))
                return true;
            if (~b && anc(b, v)) {
                b = v;
                return true;
            }
            if (~b && anc(v, b))
                return true;
            if (~a && ~b)
                return false;
            if (lca(a, v) == 0) {
                b = v;
                return true;
            }
            return false;
        };
        auto calc = [&]() {
            if (b == -1) {
                return 1ll * (n - sz[to(a)]) * sz[a];
            }
            return 1ll * sz[a] * sz[b];
        };
        bool is = true;
        for (int i = 1; i < n; ++i) {
            is &= add(i);
            if (is)
                cnt[i + 1] = calc();
        }
        for (int i = 0; i < n; ++i)
            cnt[i] -= cnt[i + 1];
        printv(all(cnt));
        for (int i = 0; i < n; ++i)
            adj[i].clear();
    }
}