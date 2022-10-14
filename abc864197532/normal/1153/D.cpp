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
const int mod = 1e9 + 7, abc = 864197532, N = 300001, K = 111;

int a[N];
vector <int> adj[N];
int dp[N], cntleaf;

void dfs(int v) {
    bool isleaf = true;
    if (a[v] == 1) dp[v] = 1 << 30;
    for (int u : adj[v]) {
        isleaf = false;
        dfs(u);
        if (a[v] == 1) {
            dp[v] = min(dp[v], dp[u]);
        } else {
            dp[v] += dp[u];
        }
    }
    if (isleaf) {
        dp[v] = 1;
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 1, v; i < n; ++i) {
        cin >> v, --v;
        adj[v].pb(i);
    }
    for (int i = 0; i < n; ++i) if (adj[i].empty()) cntleaf++;
    dfs(0);
    cout << cntleaf - dp[0] + 1 << endl;
}