// keep calm and eat pizza.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll q;
	cin >> q;
	while(q--){
        ll x, y, k;
        cin >> x >> y >> k;
        --x;
        ll l = -1, r = 1e9;
        while(r-l>1){
            ll m = (l+r)>>1;
            ll v = x*m+1;
            if(v/y>=k) r=m;
            else l = m;
        }
        ll e = x*r+1-y*k;
        ll res=r+k;
        ll lf = e-k;
        if(lf<0){
            res+=(-lf+x-1)/x;
        }
        cout<<res<<'\n';
	}
}