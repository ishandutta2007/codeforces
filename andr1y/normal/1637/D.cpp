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
const ll N = 12000;

bitset<N> bts;

signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        vector<ll> a(n), b(n), c(n);
        copy_n(istream_iterator<ll>(cin), n, a.begin());
        copy_n(istream_iterator<ll>(cin), n, b.begin());
        ll S=0, Sa=0, Sk=0;
        for(ll i = 0;i<n;i++){
            if(a[i] > b[i]) swap(a[i], b[i]);
            S+=a[i]+b[i];
            Sk+=a[i]*a[i] + b[i]*b[i];
            Sa+=a[i];
            c[i] = b[i]-a[i];
        }
        ll Sh = S/2;
        bts.reset();
        bts[0]=1;
        for(ll i = 0;i<n;i++) bts |= (bts<<c[i]);
        ll res = Sa;
        for(ll i = Sa;i<=S-Sa;i++){
            if(bts[i-Sa]){
                if(abs(Sh-res) > abs(Sh - i)) res=i;
            }
        }
        cout<<(n-2)*Sk + res*res + (S-res)*(S-res)<<'\n';
    }
}