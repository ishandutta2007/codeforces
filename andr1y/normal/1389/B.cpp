// -- telegram @rentixous --
// -- keep calm and slava ukraini --
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+1488;
ll a[N], p[N];
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, k, z, r=0;
        cin >> n >> k >> z;
        for(ll i = 0;i<n;i++){
            cin >> a[i];
            p[i]=a[i];
            if(i)p[i]+=p[i-1];
        }
        r=p[k];
        for(ll l=1;l<=z;l++){
            for(ll i = 0;i<n;i++){
                ll u = i+l+l-1;
                if(u>k) break;
                ll s = p[i]+a[i-1]*l+a[i]*(l-1)+(i+k-u-1>=0?p[i+k-u-1]:0)-(i?p[i-1]:0);
                r=max(r, s);
            }
        }
        cout<<r<<'\n';
    }
}