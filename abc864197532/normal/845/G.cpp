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
const int mod = 998244353, abc = 864197532, N = 100002, logN = 17, K = 333;

int mask[30];

void add(int x) {
    for (int i = 29; ~i; --i) if (x >> i & 1) {
        if (!mask[i]) {
            mask[i] = x;
            return;
        }
        x ^= mask[i];
    }
}

vector <pii> adj[N];
int dis[N];
bool vis[N];

void dfs(int v, int pa, int W) {
    dis[v] = ~pa ? dis[pa] ^ W : 0;
    vis[v] = true;
    for (auto [u, w] : adj[v]) if (u != pa) {
        if (vis[u]) {
            add(dis[v] ^ dis[u] ^ w);
        } else {
            dfs(u, v, w);
        }
    }
}


int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w, --u, --v;
        adj[u].eb(v, w);
        adj[v].eb(u, w);
    }
    dfs(0, -1, 0);
    int ans = dis[n - 1];
    for (int i = 29; ~i; --i) if (ans >> i & 1) {
        if (mask[i]) ans ^= mask[i];
    }
    cout << ans << endl;
}