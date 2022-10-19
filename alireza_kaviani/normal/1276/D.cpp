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

ll n , dp[MAXN][6]; // 1 : khodesh , 2 : parentesh
vector<int> adj[MAXN];

void DFS(int v , int p = -1){
    dp[v][0] = dp[v][2] = 1;
    for(int u : adj[v]){
        if(u == p){
            dp[v][3] = (dp[v][3] + dp[v][2]) % MOD;
            dp[v][4] = (dp[v][4] + dp[v][2]) % MOD;
            dp[v][2] = 0;
            continue;
        }
        DFS(u , v);
        ll A = dp[u][0] + dp[u][1] , B = dp[u][2] + dp[u][3] , C = dp[u][4] + dp[u][5];
        for(int i = 2 ; i >= 0 ; i--){
            dp[v][i * 2 + 1] = (dp[v][i * 2 + 1] * A + dp[v][i * 2] * C) % MOD;
            dp[v][i * 2] = (dp[v][i * 2] * B) % MOD;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    for(int i = 1 ; i < n ; i++){
        int v , u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    DFS(1);
    cout << (dp[1][0] + dp[1][1]) % MOD << endl;

    return 0;
}
/*

*/