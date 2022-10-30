// -- //
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> yree;
const ll N = 2e5+228;
pll a[N], b[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        for(ll i =0;i<n;i++){
            cin >> a[i].x >> a[i].y;
            b[i]=a[i];
        }
        sort(a, a+n);
        sort(b, b+n, [](pll a, pll b){
            return a.y < b.y;
        });
        ll lp = 0, mr=0;
        yree rs;
        rs.insert(a[0].y);
        for(ll i = 0;i<n;i++){
            while(lp+1<n&&a[lp+1].x<=b[i].y){
                lp++;
                rs.insert(a[lp].y);
            }
            ll k = rs.size()-rs.order_of_key(b[i].x);
            mr=max(mr, k);
        }
        cout<<n-mr<<'\n';
    }
}