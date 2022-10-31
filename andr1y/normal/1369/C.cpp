// -- telegram @rentixous --
// -- keep calm and slava ukraini --
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+1488;
ll a[N], b[N];
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, k, r=0;
        cin >> n >> k;
        for(ll i = 0;i<n;i++) cin >> a[i];
        for(ll i = 0;i<k;i++) cin >> b[i];
        sort(a, a+n, greater<ll>());
        sort(b, b+k);
        ll lf=0, ek=0;
        for(;ek<k;ek++){
            if(b[ek]==1){
                r+=a[lf]+a[lf++];
            }else break;
        }
        ll aa = k-ek;
        ll f2 = lf+aa-1;
        for(;ek<k;ek++){
            r+=a[lf++];
            f2+=b[ek]-1;
            r+=a[f2];
        }
        cout<<r<<'\n';
    }
}