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
ll ask(ll z){
    cout<<"? "<<z<<'\n';
    cout.flush();
    ll r;
    cin >> r;
    return r;
}
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    ll l = 0, r = 3001*3001;
    while(r-l>1){
        ll m = (l+r)>>1;
        ll z = ask(m);
        if(z == 0 || z > 1) l = m;
        else r=m;
    }
    ll w = r+1;
    for(ll i = 2;i<=n;i++){
        ll z = (w+i-1)/i;
        if(z==1) break;
        ll f = ask(z-1);
        if(f==0) break;
        r = min(r, f*z-f);
    }
    cout<<"! "<<r<<'\n';
}