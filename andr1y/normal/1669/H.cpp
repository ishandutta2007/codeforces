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
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        copy_n(istream_iterator<ll>(cin), n, a.begin());
        ll r=0;
        for(ll j = 30;j>=0;j--){
            ll cos=0;
            for(ll i = 0 ;i<n;i++){
                if(((a[i]>>j)&1) == 0) cos++;
            }
            if(cos <= k) r^=(1LL<<j), k-=cos;

        }
        cout<<r<<'\n';
    }
}