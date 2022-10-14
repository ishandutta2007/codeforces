#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod =998244353, x = 864197532, N = 100008, logN = 18, K = 500, C = 100;

int dep[N];
vector <int> adj[N];

void dfs(int v, int pa) {
    dep[v] = ~pa ? (dep[pa] ^ 1) : 0;
    for (int u : adj[v]) if (u != pa) {
        dfs(u, v);
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, u, v;
    cin >> n;
    fop (i,0,n - 1) {
        cin >> u >> v, u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0, -1);
    int cnt[2] = {0, 0};
    fop (i,0,n) cnt[dep[i]]++;
    cout << 1ll * cnt[0] * cnt[1] - (n - 1) << endl;
}