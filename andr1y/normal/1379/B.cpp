// -- telegram @rentixous --
// -- keep calm and slava ukraini --
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+1488;

signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll l, r, m;
        cin >> l >> r >> m;
        bool f=0;
        for(ll a = l;a<=r&&!f;a++){
            ll mnm = max(1ll, m-r+l);
            ll mxm = m+r-l;
            ll v1 = (mnm-1)/a, v2 = mxm/a;
            if(v1<v2){
                f=1;
                ll vv = (mnm/a)*a;
                if(vv<mnm) vv+=a;
                ll df = m-vv;
                if(df>=0)cout<<a<<' '<<df+l<<' '<<l<<'\n';
                else cout<<a<<' '<<l<<' '<<l-df<<'\n';

            }
        }
    }
}