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
        ll n;
        cin >> n;
        ll l = 1, r = n;
        while(r-l>1){
            ll m  =(l+r)>>1;
            if(m*m>n) r=m;
            else l=m;
        }
        ll sq =l;
        ll res = (sq-1)+(sq-1);
        ll sum = sq*sq, blc = sq;
        ll need = n-sum;
        res+=(need+blc-1)/blc;
        cout<<res<<'\n';
	}
}