// -- //
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> yree;
const ll N = 50028;
ll lp[N], prm[N], pc=0;
yree ps;
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    for(ll i = 2;i<N;i++){
        if(!lp[i]){
            lp[i]=i;
            prm[pc++]=i;
            ps.insert(i);
        }
        for(ll j = 0;j<pc&&prm[j]<=lp[i]&&prm[j]*i<N;j++) lp[prm[j]*i]=prm[j];
    }
    ll q;
    cin >> q;
    while(q--){
        ll d;
        cin >> d;
        ll e = *ps.find_by_order(ps.order_of_key(d+1));
        ll u = *ps.find_by_order(ps.order_of_key(e+d));
        cout<<min(e*e*e, e*u)<<'\n';
    }
}