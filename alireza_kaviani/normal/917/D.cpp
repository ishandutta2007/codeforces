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

const ll MAXN = 110;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , C[MAXN][MAXN] , sz[MAXN] , dp[MAXN][MAXN][MAXN] , dp2[MAXN][MAXN] , ans[MAXN];
vector<int> adj[MAXN];

void DFS(int v , int p = -1){
    dp[v][0][1] = sz[v] = 1;
    for(int u : adj[v]){
        if(u == p)  continue;
        DFS(u , v);
        memset(dp2 , 0 , sizeof(dp2));
        for(int i = 0 ; i <= sz[v] ; i++){ // Edge
            for(int j = 0 ; j <= sz[u] ; j++){ // Edge
                for(int k = 0 ; k <= sz[v] ; k++){ // Size
                    for(int l = 0 ; l <= sz[u] ; l++){ // Size
                        dp2[i + j][k] = (dp2[i + j][k] + 1ll * dp[v][i][k] * dp[u][j][l] % MOD * l) % MOD;
                        dp2[i + j + 1][k + l] = (dp2[i + j + 1][k + l] + 1ll * dp[v][i][k] * dp[u][j][l]) % MOD; 
                    }                
                }
            }
        }
        for(int i = 0 ; i < MAXN ; i++){
            for(int j = 0 ; j < MAXN ; j++){
                dp[v][i][j] = dp2[i][j];
            }
        }
        sz[v] += sz[u];
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    for(int i = 0 ; i < MAXN ; i++){
        C[i][0] = 1;
        for(int j = 1 ; j <= i ; j++){
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }

    cin >> n;
    for(int i = 1 ; i < n ; i++){
        int v , u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    DFS(1);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j <= n ; j++){
            ans[i] += dp[1][i][j] * j;
        }
        ans[i] %= MOD;
    }
    ans[n - 1] = 1;
    ll cur = 1;
    for(int i = n - 2 ; i >= 0 ; i--){
        ans[i] = ans[i] * cur % MOD;
        for(int j = i + 1 ; j < n ; j++){
            ans[i] = (ans[i] + MOD - C[j][i] * ans[j] % MOD) % MOD;
        }
        cur = cur * n % MOD;
    }
    for(int i = 0 ; i < n ; i++){
        cout << ans[i] << sep;
    }

    return 0;
}
/*

*/