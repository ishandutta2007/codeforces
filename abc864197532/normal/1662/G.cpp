#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")  
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx2")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 1000087, logN = 19, K = 111, M = 1000006;

vector <int> adj[N];
int sz[N], par[N];

void dfs1(int v, int pa) {
    sz[v] = 1, par[v] = pa;
    for (int u : adj[v]) if (u != pa) {
        dfs1(u, v);
        sz[v] += sz[u];
    }
}

void dfs2(int v, int pa) {
    sz[v] = 1;
    for (int u : adj[v]) if (u != pa)
        dfs2(u, v), sz[v] += sz[u];
}

int main () {
    owo;
    int n;
    cin >> n;
    for (int i = 1, p; i < n; ++i) {
        cin >> p, --p;
        adj[p].pb(i), adj[i].pb(p);
    }
    dfs1(0, -1);
    vector <int> cen;
    for (int i = 0; i < n; ++i) {
        bool is = true;
        if (n - sz[i] > n / 2)
            is = false;
        for (int j : adj[i]) if (j != par[i] && sz[j] > n / 2)
            is = false;
        if (is)
            cen.pb(i);
    }
    lli ans = 0;
    for (int c : cen) {
        lli cur = 0;
        sz[c] = 0;
        for (int v : adj[c]) {
            dfs2(v, c);
        }
        cur = accumulate(sz, sz + n, 0ll);
        vector <int> cnt(n + 1, 0);
        for (int v : adj[c]) 
            cnt[sz[v]]++;
        int bound = n / 2 + 5;
        vector <bool> dp(bound, false);
        vector <int> t;
        dp[0] = true;
        for (int i = 1; i <= n; ++i) if (cnt[i]) {
            t.assign(bound, 0);
            for (int j = 0; j + i < bound; ++j) {
                if (t[j] < cnt[i] && !dp[j + i] && dp[j])
                    dp[j + i] = true, t[j + i] = t[j] + 1;
            }
        }
        for (int i = 0; i < bound; ++i) if (dp[i])
            ans = max(ans, cur + 1ll * i * (n - i - 1));
    }
    cout << ans + n << '\n';
}