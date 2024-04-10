// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
const ll C = 31622;
//const ll C = 10000;
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll x, y;
        cin >> x >> y;
        y=min(y, x+1);
        ll res=0;
        for(ll i = 1;i<=y&&i<C;i++){
            res+=min(x/(i+1), i-1);
        }
        for(ll i = C;i<=y;i++){
            ll l=i, r=y+1;
            ll th = min(x/(i+1), i-1);
            while(r-l>1){
                ll m = (l+r)>>1;
                ll cs = min(x/(m+1), m-1);
                if(cs==th) l=m;
                else r=m;
            }
            res+=(l-i+1)*th;
            i=l;
        }
        cout<<res<<'\n';
    }
}