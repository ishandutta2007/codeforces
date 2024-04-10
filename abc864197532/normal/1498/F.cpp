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
const int mod = 1e9 + 7, abc = 864197532, N = 100001, K = 111;

vector <int> adj[N];
int dp[N][41], ans[N][41], a[N], k;

void dfs1(int v, int pa, int d = 0) {
    dp[v][0] ^= a[v];
    for (int u : adj[v]) if (u != pa) {
        dfs1(u, v, (d + 1) % (k + k));
        for (int i = 0; i < k + k; ++i) {
            dp[v][(i + 1) % (k + k)] ^= dp[u][i];
        }
    }
}

void dfs2(int v, int pa) {
    for (int i = 0; i < k + k; ++i) ans[v][i] = dp[v][i];
    if (~pa) {
        for (int i = 0; i < k + k; ++i) {
            ans[pa][(i + 1) % (k + k)] ^= dp[v][i];
        }
        for (int i = 0; i < k + k; ++i) {
            ans[v][(i + 1) % (k + k)] ^= ans[pa][i];
        }
        for (int i = 0; i < k + k; ++i) {
            ans[pa][(i + 1) % (k + k)] ^= dp[v][i];
        }
    }
    for (int u : adj[v]) if (u != pa) {
        dfs2(u, v);
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n >> k;
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int i = 0; i < n; ++i) cin >> a[i];
    dfs1(0, -1);
    dfs2(0, -1);
    for (int i = 0; i < n; ++i) {
        int xorr = 0;
        for (int j = k; j < k + k; ++j) xorr ^= ans[i][j];
        cout << (xorr ? 1 : 0) << ' ';
    }
    cout << endl;
}