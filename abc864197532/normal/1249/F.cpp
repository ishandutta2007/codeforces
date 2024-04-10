#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a){
    return o << a.X << ' ' << a.Y;
}
template<typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a){
    return o >> a.X >> a.Y;
}
const int mod = 1e9 + 7, abc = 864197532, N = 201, K = 111;

vector <int> adj[N];
int dp[N][N], a[N], k;

void dfs(int v, int pa) {
    bool leaf = true;
    for (int u : adj[v]) if (u != pa) {
        dfs(u, v);
        leaf = false;
    }
    if (leaf) {
        dp[v][0] = a[v];
    } else {
        dp[v][0] = a[v];
        for (int u : adj[v]) if (u != pa) {
            dp[v][0] += dp[u][k - 1];
        }
        for (int i = 1; i < N; ++i) {
            for (int u : adj[v]) if (u != pa) {
                int re = dp[u][i - 1];
                for (int t : adj[v]) if (t != pa && t != u) {
                    re += dp[t][max(i - 1, k - i - 1)];
                }
                dp[v][i] = max(dp[v][i], re);
            }
        }
    }
    for (int i = N - 1; i > 0; --i) dp[v][i - 1] = max(dp[v][i - 1], dp[v][i]);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n >> k;
    k++;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0, -1);
    int ans = 0;
    for (int i = 0; i < N; ++i) ans = max(ans, dp[0][i]);
    cout << ans << endl;
}