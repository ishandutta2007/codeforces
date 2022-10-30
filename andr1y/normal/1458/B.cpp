// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 101;
ll dp[N][N*N];
ll a[N], b[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    ll sai=0, sbi=0;
    for(ll i = 0;i<n;i++){
        cin >> a[i] >> b[i];
        sai+=a[i];
        sbi+=b[i];
    }
    memset(dp, 0xcf, sizeof(dp));
    dp[0][0]=0;
    for(ll i = 0;i<n;i++){
        /*for(ll pick=0;pick<=n;pick++){
            for(ll suma=0;suma<=sai;suma++){
                dp[fi][pick][suma]=dp[fe][pick][suma];
            }
        }*/
        for(ll pick=n;pick;pick--){
            for(ll suma=sai;suma>=a[i];suma--){
                dp[pick][suma]=max(dp[pick][suma], dp[pick-1][suma-a[i]]+b[i]);
            }
        }
    }
    for(ll k = 1;k<=n;k++){
        ll mv2=0;
        for(ll j = 0;j<=sai;j++){
            mv2=max(mv2, min(j+j, sbi+dp[k][j]));
        }
        if(mv2&1) cout<<(mv2/2)<<".500000000 ";
        else cout<<(mv2/2)<<".000000000 ";
    }
}