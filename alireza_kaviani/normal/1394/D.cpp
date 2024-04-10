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
const ll INF = 1e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , sum , T[MAXN] , H[MAXN] , dp[MAXN][3]; // inDeg - outDeg
vector<int> adj[MAXN];

void DFS(int v , int p = -1){
    for(int u : adj[v]){
        if(u == p)  continue;
        DFS(u , v);
    }
    for(int i = 0 ; i <= 2 ; i++){
        dp[v][i] = INF;
        ll deg = i - 1 , cost = 0;
        vector<ll> vec;
        for(int u : adj[v]){
            if(u == p)  continue;
            if(H[v] < H[u]){
                deg++;
                cost += dp[u][0];
            }
            else if(H[u] < H[v]){
                deg--;
                cost += dp[u][2];
            }
            else{
                deg--;
                cost += dp[u][2];
                vec.push_back(dp[u][0] - dp[u][2]);
            }
        }
        sort(all(vec));
        for(int j = 0 ; j <= SZ(vec) ; j++){
            dp[v][i] = min(dp[v][i] , cost + abs(deg) * T[v]);
            deg += 2;
            if(j < SZ(vec)){
                cost += vec[j];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> T[i];
    }
    for(int i = 1 ; i <= n ; i++){
        cin >> H[i];
    }
    for(int i = 1 ; i < n ; i++){
        int v , u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
        sum += T[v] + T[u];
    }
    DFS(1);

    cout << (sum + dp[1][1]) / 2 << endl;

    return 0;
}
/*

*/