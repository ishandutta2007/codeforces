//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;

signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll a, b;
        cin >> a >> b;
        if(a>b)swap(a, b);
        ll l = 0, r = b;
        while(r-l>1){
            ll m = (l+r)>>1;
            ll va = m, vb = m+m;
            ll df = max(0ll, vb-b);
            if(m+df>a) r=m;
            else l = m;
        }
        cout<<l<<'\n';
    }
}