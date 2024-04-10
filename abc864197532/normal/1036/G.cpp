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
const int mod = 1e9 + 7, N = 1000005, logN = 20, M = 1000010;

vector <int> adj[N];
int in[N], out[N], source[N], sink[N], _t;
bool vis[N];

void dfs(int v) {
    vis[v] = true;
    for (int u : adj[v]) if (!vis[u]) {
        dfs(u);
    }
}

int main () {
    owo;
    int n, m;
    cin >> n >> m;
    fill(source, source + n, -1);
    fill(sink, sink + n, -1);
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v, --u, --v;
        out[u]++, in[v]++;
        adj[v].pb(u);
    }
    for (int i = 0; i < n; ++i) if (!in[i]) {
        source[i] = _t++;
    }
    _t = 0;
    for (int i = 0; i < n; ++i) if (!out[i]) {
        sink[i] = _t++;
    }
    for (int i = 0; i < n; ++i) if (~source[i] && ~sink[i]) {
        cout << "NO\n";
        return 0;
    }
    vector <int> dp(1 << _t, 0);
    for (int i = 0; i < n; ++i) if (~sink[i]) {
        fill(vis, vis + n, false);
        dfs(i);
        for (int j = 0; j < n; ++j) if (~source[j] && vis[j]) {
            dp[1 << sink[i]] |= 1 << source[j];
        }
    }
    for (int s = 1; s < 1 << _t; ++s) {
        int b = s & (-s);
        dp[s] = dp[s ^ b] | dp[b];
    }
    for (int s = 1; s < (1 << _t) - 1; ++s) {
        if (__builtin_popcount(s) >= __builtin_popcount(dp[s])) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}