// -- telegram @rentixous --
// -- keep calm and slava ukraini --
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+1488;
ll nsk(ll i, ll j){
    ll g = __gcd(i, j);
    return (i*j)/g;
}
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        if(n&1){
            ll a=LLONG_MAX, b=-1;
            for(ll i = 1;i*i<=n;i++){
                if(n%i) continue;
                ll v1 = i, v2 = n-i, v3= nsk(v1, v2);
                if(v3<a){
                    a=v3, b=i;
                }
                if(i==1) continue;
                v1 = n/i, v2 = n-v1, v3=nsk(v1, v2);
                if(v3<a){
                    a=v3, b=n/i;
                }
            }
            cout<<b<<' '<<n-b<<'\n';
        }else cout<<n/2<<' ' <<n/2<<'\n';
    }
}