// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 528;
ll dp[2][N][N];
ll a[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        memset(dp, 0x3f, sizeof(dp));
        ll fi=0, fe=1, n, x;
        cin >> n >> x;
        for(ll i = 0;i<n;i++){
            cin >> a[i];
        }
        dp[fe][a[0]][x] = 0;
        if(x<a[0]) dp[fe][x][a[0]] = 1;
        for(ll i = 1;i<n;i++){
            memset(dp[fi], 0x3f, sizeof(dp[fi]));
            for(ll from=0;from<=a[i];from++){
                for(ll from_x=0;from_x<=500;from_x++){
                    dp[fi][a[i]][from_x] = min(dp[fi][a[i]][from_x], dp[fe][from][from_x]);
                    if(a[i]>from_x&&from_x>=from) dp[fi][from_x][a[i]]=min(dp[fi][from_x][a[i]], dp[fe][from][from_x]+1);
                }
            }
            fi^=1, fe^=1;
        }
        ll res=0x3f3f3f3f3f3f3f3f;
        ll inf=res;
        for(ll from=0;from<=500;from++){
            for(ll from_x=0;from_x<=500;from_x++){
                res=min(res, dp[fe][from][from_x]);
            }
        }
        if(res>=inf) cout<<"-1\n";
        else cout<<res<<'\n';
    }
}