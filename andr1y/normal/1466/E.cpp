// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5+228;
const ll M = 1e9+7;
ll a[N];
ll aand[64];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        memset(aand, 0, sizeof(aand));
        ll n, s=0;
        cin >> n;
        for(ll i = 0;i<n;i++){
            cin >> a[i];
            for(ll j=0;j<60;j++){
                if((a[i]>>j)&1){
                    aand[j]+=(1LL<<j);
                    aand[j]%=M;
                }
            }
            s+=a[i];
            s%=M;
        }
        ll sand=0;
        ll last=0;
        ll res=0;
        for(ll i = 0;i<n;i++){
            for(ll j = 0;j<60;j++){
                ll ol = (last>>j)&1, nw = (a[i]>>j)&1;
                if(ol==1&&nw==0){
                    sand+=M-(aand[j]);
                }else if(ol==0&&nw==1){
                    sand+=(aand[j]);
                }
                sand%=M;
            }
            ll sor=(M+s-sand+n*(a[i]%M))%M;
            res+=(sand*sor)%M;
            res%=M;

            last=a[i];
        }
        cout<<res<<'\n';
    }
}