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

const ll MAXN = 1e5 + 10;
const ll MAXK = 210;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , k , sz[MAXN] , dp[MAXN][MAXK] , dp2[MAXK] , res[MAXK] , S[MAXK][MAXK];
vector<int> adj[MAXN];

void DFS(int v , int p = -1){
    sz[v] = 1;
    dp[v][0] = 2;
    for(int u : adj[v]){
        if(u == p)  continue;
        DFS(u , v);
        fill(dp2 , dp2 + MAXK , 0);
        for(int i = 0 ; i <= min(sz[v] , k) ; i++){
            for(int j = 0 ; j <= min(sz[u] , k) ; j++){
                if(i + j > k)   continue;
                dp2[i + j] = (dp2[i + j] + dp[v][i] * (dp[u][j] + (j == 0))) % MOD;
                dp2[i + j + 1] = (dp2[i + j + 1] + dp[v][i] * dp[u][j]) % MOD;
            }
        }
        for(int i = 0 ; i < MAXK ; i++){
            dp[v][i] = dp2[i];
        }
        sz[v] += sz[u];
    }
    dp[v][0] = (dp[v][0] + MOD - 1) % MOD;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    S[0][0] = 1;
    for(int i = 1 ; i < MAXK ; i++){
        for(int j = 1 ; j <= i ; j++){
            S[i][j] = j * (S[i - 1][j] + S[i - 1][j - 1]) % MOD;
        }
    }

    cin >> n >> k;
    for(int i = 1 ; i < n ; i++){
        int v , u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    DFS(1);
    for(int i = 1 ; i <= k ; i++){
        res[i] = dp[1][i];
    }
    for(int i = 2 ; i <= n ; i++){
        for(int j = 0 ; j < k ; j++){
            res[j + 1] = (res[j + 1] + MOD - dp[i][j]) % MOD;
        }
    }

    ll ans = 0;
    for(int i = 1 ; i <= k ; i++){
        ans = (ans + res[i] * S[k][i]) % MOD;
    }
    cout << ans << endl;

    return 0;
}
/*

*/