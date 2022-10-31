// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
const ll M = 1e9+7;
ll cnt[2][N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, k, res=1;
        cin >> n >> k;
        ll fi=0, fe=1;
        memset(cnt[fe], 0, sizeof(ll)*(n+3));
        cnt[fe][1]=1;
        for(ll w = k;w>1;w--){
            memset(cnt[fi], 0, sizeof(cnt[fi]));
            if((w^k)&1){
                ll altk=0;
                for(ll i = n;i>0;i--){
                    altk+=cnt[fe][i];
                    altk%=M;
                    if(i<n) cnt[fi][i+1]=(cnt[fi][i+1]+altk)%M;
                    res+=altk;
                    res%=M;
                }
            }else{
                //right
                ll altk=0;
                for(ll i = 1;i<=n;i++){
                    altk+=cnt[fe][i];
                    altk%=M;
                    if(i>1) cnt[fi][i-1]=(cnt[fi][i-1]+altk)%M;
                    res+=altk;
                    res%=M;
                }
            }
            swap(fi, fe);
        }
        cout<<res<<'\n';;
    }
}