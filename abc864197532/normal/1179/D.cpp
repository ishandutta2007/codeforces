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
const int mod = 998244353, N = 1 << 19, logN = 20;

struct line {
    long long m, k;
    line (long long _m, long long _k) : m(_m), k(_k) {}
    long long f(long long x) {return m * x + k;}
};

struct Seg {
    // query min
    // 0-indexed, [l, r)
    int l, r, m;
    line best;
    Seg* ch[2];
    Seg () = default;
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), best(line(0, 1ll << 60)), ch{NULL, NULL} {}
    void add(line cur) {
        if (r - l == 1) {
            if (cur.f(l) < best.f(l)) {
                best = cur;
            }
        } else {
            if (cur.m < best.m)
                swap(cur, best);
            if (cur.f(m) < best.f(m)) {
                swap(cur, best);
                if (!ch[1])
                    ch[1] = new Seg(m, r);
                ch[1]->add(cur);
            } else {
                if (!ch[0])
                    ch[0] = new Seg(l, m);
                ch[0]->add(cur);
            }
        }
    }
    long long query(int x) {
        if (r - l == 1)
            return best.f(x);
        return min(best.f(x), (ch[x >= m] ? ch[x >= m]->query(x) : 1ll << 60));
    }
    void reset() {
        if (ch[0])
            ch[0]->reset(), delete ch[0], ch[0] = NULL;
        if (ch[1])
            ch[1]->reset(), delete ch[1], ch[1] = NULL;
        best = line(0, 1ll << 60);
    }
} root(0, N);

vector <int> adj[N];
lli dp[N], ans = 1ll << 60;
int sz[N], n;

lli C2(int x) {
    return 1ll * x * (x - 1) / 2;
}

void dfs(int v, int pa) {
    dp[v] = 1ll << 60, sz[v] = 1;
    bool ch = false;
    for (int u : adj[v]) if (u != pa) {
        dfs(u, v);
        ch = true;
        sz[v] += sz[u];
    }
    if (!ch) {
        dp[v] = 0;
        return;
    }
    // choose two child v, u minimize C2(n - sz[v] - sz[u]) + dp[v] + dp[u]
    // (n - sz[v] - sz[u]) * (n - sz[v] - sz[u] - 1) / 2 + dp[v] + dp[u]
    // (n - sz[v])^2 + dp[v] - (2 sz[u] + 1) * (n - sz[v]) + sz[u] * (sz[u] + 1) + dp[u]
    for (int u : adj[v]) if (u != pa) {
        dp[v] = min(dp[v], C2(sz[v] - sz[u]) + dp[u]);
        ans = min(ans, root.query(n - sz[u]) + dp[u] * 2 + 1ll * (n - sz[u]) * (n - sz[u]));
        root.add({-2 * sz[u] - 1, 1ll * sz[u] * (sz[u] + 1) + dp[u] * 2});
    }
    root.reset();
}

int main () {
    owo;
    cin >> n;
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].pb(v), adj[v].pb(u);
    }
    dfs(0, -1);
    ans = min(ans, dp[0] * 2);
    cout << 1ll * n * (n - 1) - ans / 2 << endl;
}