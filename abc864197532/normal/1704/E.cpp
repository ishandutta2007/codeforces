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
const int mod = 998244353, N = 52, logN = 18, G = 3;

void solve() {
    int n, m;
    cin >> n >> m;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector <vector <int>> adj(n);
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].pb(v);
    }
    // brute 2n times
    int ans = 0;
    for (int t = 0; t < 2 * n; ++t) {
        vector <int> in(n, 0), out(n, 0);
        for (int i = 0; i < n; ++i) if (a[i]) {
            in[i] = 1;
            for (int j : adj[i])
                out[j]++;
        }
        if (!count(all(in), 1)) {
            break;
        }
        for (int i = 0; i < n; ++i) 
            a[i] -= in[i], a[i] += out[i];
        ans++;
    }
    vector <int> out(n, 0);
    for (int i = 0; i < n; ++i) for (int j : adj[i])
        out[j]++;
    int s = -1;
    for (int i = 0; i < n; ++i) if (adj[i].empty())
        s = i;
    assert(s != -1);
    vector <lli> dp(n, 0);
    queue <int> q;
    for (int i = 0; i < n; ++i) if (!out[i])
        q.push(i);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        dp[v] += a[v];
        for (int u : adj[v]) {
            out[u]--;
            (dp[u] += dp[v]) %= mod;
            if (!out[u])
                q.push(u);
        }
    }
    cout << (ans + dp[s]) % mod << '\n';
}

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}