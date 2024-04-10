// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
vector<ll> d[N];
ll a[2][N];
ll dp[N][2];
void dfs(ll v, ll mk=0, ll p=-1){
    for(auto i : d[v]){
        if(i==p) continue;
        dfs(i, 1-mk, v);
        dp[v][0]+=max(dp[i][0]+abs(a[0][v]-a[0][i]), dp[i][1]+abs(a[0][v]-a[1][i]));
        dp[v][1]+=max(dp[i][0]+abs(a[1][v]-a[0][i]), dp[i][1]+abs(a[1][v]-a[1][i]));
    }
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin>>q;
    while(q--){
        ll n;
        cin>>n;for(ll i =1;i<=n;i++) d[i].clear(), dp[i][0]=0, dp[i][1]=0;;
        for(ll i = 1;i<=n;i++) cin>>a[0][i]>>a[1][i];
        for(ll a, b, i=1;i<n;i++){cin>>a>>b;d[a].push_back(b);d[b].push_back(a);}
        dfs(1);
        cout<<max(dp[1][0], dp[1][1])<<'\n';
    }
}