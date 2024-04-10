// keep calm and eat pizza.
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> yree;
const ll N = 2e5+228;
ll a[N], pf[N], xs[N], rm[N];
yree sz;
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll q;
	cin >> q;
	while(q--){
        sz.clear();
        ll n, k;
        cin >> n >> k;
        for(ll i = 0;i<n;i++){
            cin >> xs[i];
            sz.insert(xs[i]);
            a[i]=0;
        }
        for(ll R, j = 0;j<n;j++){
            cin >> R;
            a[sz.order_of_key(xs[j])]++;
        }
        ll sn = sz.size();
        pf[0]=a[0];
        for(ll i = 1;i<sn;i++) pf[i]=a[i]+pf[i-1];
        ll rs=0;
        rm[sn]=0;
        for(ll i = sn-1;i>=0;i--){
            ll l = *sz.find_by_order(i);
            ll rp = sz.order_of_key(l+k+1);
            ll v = pf[rp-1]-(i?pf[i-1]:0);
            rm[i] = max(rm[i+1], v);
            rs=max(rs, v+rm[rp]);
        }
        cout<<rs<<'\n';
	}
}