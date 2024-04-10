// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll p, q;
        cin >> p >> q;
        if(p%q) cout<<p<<'\n';
        else{
            ll r = 1;
            ll oq = q;
            for(ll j = 2;j*j<=q;j++){
                if(oq%j) continue;
                ll c = 0, bq=1;
                while(oq%j==0){
                    oq/=j, c++, bq*=j;
                }
                ll ok = p;
                while(ok%j==0) ok/=j;
                r=max(r, (bq*ok)/j);
            }
            if(oq!=1){
                ll ok = p;
                while(ok%oq==0) ok/=oq;
                r=max(r, ok);
            }
            cout<<r<<'\n';
        }
    }
}