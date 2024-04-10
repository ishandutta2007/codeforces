// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e7+228;
int lp[N], apc[N], prm[N], pc=0;
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	apc[1]=0;
    for(ll i = 2;i<N;i++){
        if(!lp[i]){
            lp[i]=i;
            prm[pc++]=i;
            apc[i]=1;
        }
        ll j =0;
        for(;j<pc&&prm[j]<=lp[i]&&prm[j]*i<N;j++){
            ll e = prm[j]*i;
            lp[e]=prm[j];
            apc[e] = apc[i]+1;
            if(prm[j]==lp[i]) apc[e]--;
        }
    }
    ll q;
    cin >> q;
    while(q--){
        ll c, d, x;
        cin >> c >> d >> x;
        ll res=0;
        for(ll i = 1;i*i<=x;i++){
            if(x%i) continue;
            ll c1 = (d + x/i);
            ll c2 = c;
            if(c1%c2==0) res+=(1LL<<apc[c1/c2]);
            if(i*i==x) continue;
            c1 = (d + i);
            if(c1%c2==0) res+=(1LL<<apc[c1/c2]);
        }
        cout<<res<<'\n';
    }
}