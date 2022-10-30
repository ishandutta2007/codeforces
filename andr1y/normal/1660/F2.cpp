#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less_equal<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> yree;
const ll inf = 0x3fff3fff3fff3fff;
const ll N = 5e5+20;

signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        string s;
        cin >> n >> s;
        yree zz[3];
        zz[0].insert(0);
        ll dif = 0, res=0;
        for(auto i : s){
            if(i == '-') dif++;
            else dif--;
            ll fm = 0;
            if(dif >= 0) fm = dif%3;
            else fm = (3-(-dif)%3)%3;
            res+=zz[fm].order_of_key(dif+1);
            zz[fm].insert(dif);
        }
        cout<<res<<'\n';
    }
}