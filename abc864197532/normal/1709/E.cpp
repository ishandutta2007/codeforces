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
const int mod = 998244353, N = 200005, logN = 18, G = 3;

struct DS {
    int xorr = 0;
    set <int> S;
} dp[N];

vector <int> adj[N];
int a[N], ans;

void mySwap(int u, int v) {
    swap(dp[u].xorr, dp[v].xorr), swap(dp[u].S, dp[v].S);
}

void dfs(int v, int pa) {
    bool need = false;
    for (int u : adj[v]) if (u != pa) {
        dfs(u, v);
        if (dp[u].S.size() > dp[v].S.size())
            mySwap(u, v);
        for (int x : dp[u].S) {
            need |= dp[v].S.count(x ^ dp[u].xorr ^ dp[v].xorr ^ a[v]);
        }
        for (int x : dp[u].S) {
            dp[v].S.insert(x ^ dp[v].xorr ^ dp[u].xorr);
        }
        dp[u].S.clear(), dp[u].xorr = 0;
    }
    need |= dp[v].S.count(dp[v].xorr ^ a[v]);
    if (need) {
        ans++;
        dp[v].S.clear(), dp[v].xorr = 0;
    } else {
        dp[v].S.insert(dp[v].xorr), dp[v].xorr ^= a[v];
    }
} 

int main () {
    owo;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].pb(v), adj[v].pb(u);
    }
    dfs(0, -1);
    cout << ans << '\n';
}