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
const int mod = 1e9 + 7, N = 200001, logN = 20, K = 111, C = 7;

vector <int> adj[N];

pii dp[N][2];
int ans[N];

void add(pii &i, pii j) {
    i.X += j.X, i.Y += j.Y;
}

void dfs(int v, int pa) {
    dp[v][1].X++, dp[v][1].Y -= adj[v].size();
    dp[v][0].Y--;
    for (int u : adj[v]) if (u != pa) {
        dfs(u, v);
        add(dp[v][1], dp[u][0]);
        add(dp[v][0], max(dp[u][0], dp[u][1]));
    }
}

void dfs2(int v, int pa, int now) {
    if (now == 1)
        ans[v] = -1;
    for (int u : adj[v]) if (u != pa) {
        if (now == 1)
            dfs2(u, v, 0);
        else 
            dfs2(u, v, dp[u][0] > dp[u][1] ? 0 : 1);
    }
}

int main () {
    owo;
    int n;
    cin >> n;
    if (n == 2) {
        cout << "2 2\n1 1\n";
        return 0;
    }
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].pb(v), adj[v].pb(u);
    }
    dfs(0, -1);
    dfs2(0, -1, (dp[0][0] > dp[0][1] ? 0 : 1));
    for (int i = 0; i < n; ++i) if (!ans[i])
        ans[i] = 1;
    for (int i = 0; i < n; ++i) if (ans[i] == -1) {
        ans[i] = adj[i].size();
    }
    cout << max(dp[0][0], dp[0][1]).X << ' ' << accumulate(ans, ans + n, 0) << '\n';
    printv(ans, ans + n);
}