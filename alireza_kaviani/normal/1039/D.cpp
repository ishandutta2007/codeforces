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
const ll SQ = 1000;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , timer = 1 , dp[MAXN] , dp2[MAXN] , ans[MAXN] , fn[MAXN] , A[MAXN];
vector<int> adj[MAXN] , child[MAXN];

void PreDFS(int v , int p = -1){
    for(int u : adj[v]){
        if(u == p)  continue;
        PreDFS(u , v);
    }
    fn[v] = timer++;
    for(int u : adj[v]){
        if(u == p)  continue;
        child[fn[v]].push_back(fn[u]);
    }
}

void Solve(int k){
    fill(dp , dp + MAXN , 0);
    fill(dp2 , dp2 + MAXN , 0);
    for(int v = 1 ; v <= n ; v++){
        int flag = 0;
        for(int u : child[v]){
            dp[v] += dp[u];
            if(dp2[v] + dp2[u] + 1 >= k && flag == 0){
                dp[v]++;
                dp2[v] = -1;
                flag = 1;
            }
            if(flag == 0){
                dp2[v] = max(dp2[v] , dp2[u]);
            }
        }
        dp2[v]++;
    }
}

int getAns(int x){
    if(ans[x] != -1)    return ans[x];
    Solve(x);
    ans[x] = dp[n];
    return ans[x];
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    fill(ans , ans + MAXN , -1);

    cin >> n;
    for(int i = 1 ; i < n ; i++){
        int v , u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    PreDFS(1);
    ans[1] = n;
    for(int i = 2 ; i <= min(SQ , (ll)n) ; i++){
        ans[i] = getAns(i);
    }

    int last = SQ;
    for(int i = MAXN / SQ ; i >= 0 ; i--){
        int l = 0 , r = n + 1;
        while(r - l > 1){
            int mid = l + r >> 1;
            if(getAns(mid) >= i)    l = mid;
            else    r = mid;
        }
        while(last < l){
            ans[++last] = i;
        }
    }

    for(int i = 1 ; i <= n ; i++){
        cout << ans[i] << endl;
    }

    return 0;
}
/*

*/