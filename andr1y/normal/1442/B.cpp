// -- //
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> yree;
const ll N = 2e5+228;
const ll M = 998244353;
ll a[N], b[N], c[N], p[N];
yree d;
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, m;
        cin >> n >> m;
        for(ll i =1;i<=n;i++) {
            cin >> a[i];
            p[a[i]]=i;
            d.insert(i);
        }
        for(ll i =1;i<=m;i++) cin >> b[i];
        for(ll i =1;i<=m;i++) c[p[b[i]]] = 1;
        ll t = 1;
        for(ll i = 1;i<=m;i++){
            ll pk = p[b[i]], can=0;
            if(pk>1&&!c[pk-1]) can++;
            if(pk+1<=n&&!c[pk+1]) can++;
            c[pk]=0;
            t*=can;
            t%=M;
        }
        cout<<t<<'\n';
    }
}