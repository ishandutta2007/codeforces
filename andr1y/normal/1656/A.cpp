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

signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        ll minv = inf, minp = 0, maxv = 0, maxp = 0;
        for(ll a, i = 0;i<n;i++){
            cin >> a;
            if(a < minv) minv=a, minp=i;
            if(a > maxv) maxv=a, maxp=i;
        }
        cout<<maxp+1<<' '<<minp+1<<'\n';
    }
}