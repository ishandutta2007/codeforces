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

const ll MAXN = 1010;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 998244353; //1e9 + 9;

ll q , n , m , inDeg[MAXN] , mark[MAXN] , A[MAXN] , mx[MAXN] , dp[MAXN] , dp2[MAXN][MAXN];
vector<int> ord , adj[MAXN];

void DFS(int v){
    mark[v] = 1;
    for(int u : adj[v]){
        if(!mark[u]){
            DFS(u);
        }
    }
    ord.push_back(v);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n >> m;
        ord.clear();
        for(int i = 0 ; i < n + 5 ; i++){
            inDeg[i] = dp[i] = mark[i] = 0;
            mx[i] = -MOD;
            adj[i].clear();
            fill(dp2[i] , dp2[i] + MAXN , 0);
        }
        for(int i = 1 ; i <= n ; i++){
            cin >> A[i];
        }
        for(int i = 0 ; i < m ; i++){
            int u , v;
            cin >> u >> v;
            adj[v].push_back(u);
            inDeg[u]++;
        }
        int root = -1;
        for(int i = 1 ; i <= n ; i++){
            if(inDeg[i] == 0){
                root = i;
            }
        }
        DFS(root);
        for(int i : ord){
            dp[i] = A[i];
            dp2[i][0] = A[i];
            if(A[i] > 0){
                mx[i] = 0;
            }
            for(int j : adj[i]){
                mx[i] = max(mx[i] , mx[j] + 1);
                dp[i] = (dp[i] + dp[j]) % MOD;
                for(int k = 1 ; k < MAXN ; k++){
                    dp2[i][k] = min(MOD , dp2[i][k] + dp2[j][k - 1]);
                }
            }
        }
        ll sum = 0 , ans = dp[root];
        for(int i = 0 ; i <= mx[root] ; i++){
            sum += dp2[root][i];
            if(sum == 0){
                ans++;
            }
            sum = max(0ll , sum - 1);
        }
        cout << ans % MOD << endl;
    }

    return 0;
}
/*

*/