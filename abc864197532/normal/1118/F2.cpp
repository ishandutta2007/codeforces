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
const int mod = 998244353, N = 300005, logN = 20, K = 111;

vector <int> adj[N], adj2[N];
int cnt[N], c[N], k;
bool fail;

void dfs1(int v, int pa) {
    for (int u : adj[v]) if (u != pa) {
        dfs1(u, v);
        if (c[u] && cnt[c[u]]) {
            if (c[v] && c[u] != c[v]) {
                fail = true;
            } else {
                cnt[c[v]]--, c[v] = c[u], cnt[c[v]]++;
            }
        }
    }
    cnt[c[v]]--;
}

lli modpow(lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1)
            ans = ans * a % mod;
    }
    return ans;
}

lli dp[N][2];

void dfs2(int v, int pa) {
    bool ch = true;
    dp[v][1] = dp[v][0] = 1;
    if (v <= k)
        dp[v][0] = 0;
    lli res = 0;
    for (int u : adj2[v]) if (u != pa) {
        dfs2(u, v);
        ch = false;
        if (v <= k) {
            dp[v][1] = dp[v][1] * (dp[u][0] + dp[u][1]) % mod;
        } else {
            dp[v][0] = dp[v][0] * (dp[u][0] + dp[u][1]) % mod;
            (res += dp[u][1] * modpow(dp[u][0] + dp[u][1], mod - 2)) %= mod;
        }
    }
    if (v > k)
        dp[v][1] = dp[v][0] * res % mod;
    if (ch && v > k) {
        dp[v][1] = 0;
    }
}

int main () {
    owo;
    int n;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> c[i], cnt[c[i]]++;
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].pb(v), adj[v].pb(u);
    }
    dfs1(0, -1);
    if (fail) {
        cout << 0 << endl;
        return 0;
    }
    int now = k + 1;
    for (int i = 0; i < n; ++i) for (int j : adj[i]) {
        if (!c[i])
            c[i] = now++;
        if (!c[j])
            c[j] = now++;
        if (c[i] != c[j])
            adj2[c[i]].pb(c[j]);
    }
    dfs2(1, -1);
    cout << dp[1][1] << endl;
}