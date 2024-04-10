#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 998244353; //1e9 + 9;

ll n , ans , pw2[MAXN] , sz[MAXN] , dp[MAXN][2];
vector<int> adj[MAXN];

void DFS(int v , int p = -1){
    sz[v] = 1;
    dp[v][0] = 1;
    for(int u : adj[v]){
        if(u == p)  continue;
        DFS(u , v);
        sz[v] += sz[u];
        dp[v][1] = (dp[v][1] * (dp[u][0] + dp[u][1]) * 2 + dp[v][0] * dp[u][0]) % MOD;
        dp[v][0] = (dp[v][0] * dp[u][1] * 2 + dp[v][0] * dp[u][0]) % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    pw2[0] = 1;
    for(int i = 1 ; i < MAXN ; i++){
        pw2[i] = pw2[i - 1] * 2 % MOD;
    }

    cin >> n;
    for(int i = 1 ; i < n ; i++){
        int v , u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    DFS(1);
    for(int i = 1 ; i <= n ; i++){
        ans = (ans + dp[i][1] * pw2[n - sz[i] + 1]) % MOD;
    }
    cout << ans << endl;

    return 0;
}
/*

*/