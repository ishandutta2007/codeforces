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
const int mod = 1e9 + 7, N = 200010, logN = 17, M = N * 40;

vector <int> adj[N];

pair <lli, int> dp[N][2];

void add(pair <lli, int> &i, pair <lli, int> j) {
    i.X += j.X, i.Y += j.Y;
}

void dfs(int v, int pa, int cost) {
    bool leaf = true;
    pair <lli, int> mn = mp(1ll << 60, -1);
    bool has = false;
    for (int u : adj[v]) if (u != pa) {
        dfs(u, v, cost);
        leaf = false;
        add(dp[v][0], dp[u][0]);
        add(dp[v][1], min(dp[u][0], dp[u][1]));
        if (dp[u][1] <= dp[u][0])
            has = true;
        mn = min(mn, mp(dp[u][1].X - dp[u][0].X, dp[u][1].Y - dp[u][0].Y));
    }
    if (leaf) {
        dp[v][0] = mp(1, 0);
        dp[v][1] = mp(cost, -1);
    } else {
        if (!has)
            add(dp[v][1], mn);
        dp[v][0].X++;
    }
}

int main () {
    owo;
    int n, k;
    cin >> n >> k;
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].pb(v), adj[v].pb(u);
    }
    int cnt = 0;
    for (int i = 1; i < n; ++i) if (adj[i].size() == 1)
        cnt++;
    if (cnt <= k) {
        lli ans = 0;
        for (int i = cnt; i <= k; ++i) {
            ans = max(ans, 1ll * i * (n - i));
        }
        cout << ans << endl;
        return 0;
    }
    int l = 0, r = 1 << 20;
    while (r - l > 1) {
        int m = l + r >> 1;
        for (int i = 0; i < n; ++i)
            dp[i][0] = dp[i][1] = mp(0, 0);
        dfs(0, -1, m);
        auto res = min(dp[0][0], dp[0][1]);
        if (-res.Y > k)
            l = m;
        else
            r = m;
    }
    for (int i = 0; i < n; ++i)
        dp[i][0] = dp[i][1] = mp(0, 0);
    dfs(0, -1, l);
    int b = min(dp[0][0], dp[0][1]).X - 1ll * l * k;
    test(b);
    lli ans = 1ll << 60;
    for (int i = 0; i <= b; ++i)
        ans = min(ans, 1ll * (n - k - i) * (k - i));
    cout << ans << endl;
}