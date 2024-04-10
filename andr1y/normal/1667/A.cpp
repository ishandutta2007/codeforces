#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> yree;
const ll inf = 0x3fff3fff3fff3fff;
const ll N = 5e5+20;
ll a[N];
ll sf[N], pf[N];
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q=1;
    while(q--){
        ll n;
        cin >> n;
        for(ll i = 0;i<n;i++) cin >> a[i];
        pf[0] = 1;
        for(ll i = 1;i<n;i++){
            ll r = 1, l = a[i];
            for(ll j = i-1;j>=0;j--){
                ll z = (l+a[j])/a[j];
                r+=z;
                l=z*a[j];
            }
            pf[i]=r;
        }
        sf[n-1] = 1;
        for(ll i = n-2;i>=0;i--){
            ll r = 1, l = a[i];
            for(ll j = i+1;j<n;j++){
                ll z = (l+a[j])/a[j];
                r+=z;
                l=z*a[j];
            }
            sf[i]=r;
        }
        ll r = min(pf[n-1], sf[0]);
        for(ll i = 0;i+1<n;i++){
            r=min(r, pf[i]+sf[i+1]);
            if(i+2 < n) r=min(r, pf[i]+sf[i+2]);
        }
        r=min(r, sf[1]);
        cout<<r<<'\n';
    }
}