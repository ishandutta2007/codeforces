// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e7+228;
const ll N2 = 700000;
ll lp[N], prm[N2], pc=0;
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	for(ll i = 2;i<N;i++){
        if(!lp[i]){
            lp[i]=i;
            prm[pc++]=i;
        }
        for(ll j = 0;j<pc&&prm[j]<=lp[i]&&prm[j]*i<N;j++) lp[i*prm[j]] = prm[j];
	}
    ll q;
    cin >> q;
    while(q--){
        ll n, k, tr=1;
        cin >> n >> k;
        map<ll, bool> lst;
        for(ll a,  i = 0;i<n;i++){
            cin >> a;
            ll last=0, lc=0, b=a;
            ll k2 = 1;
            while(b>1){
                if(lp[b]==last){
                    if(lc) lc=0, k2/=lp[b];
                    else lc=1, k2*=lp[b];
                }else{
                    last=lp[b];
                    lc=1;
                    k2*=lp[b];
                }
                b/=lp[b];
            }
            if(lst[k2]){
                tr++;
                lst.clear();
            }
            lst[k2]=1;
        }
        cout<<tr<<'\n';
    }
}