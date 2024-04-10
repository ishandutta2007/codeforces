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
        ll n, r, b;
        cin >> n >> r >> b;
        for(ll wm = 1;wm<=n;wm++){
            ll g = (r+wm-1)/wm;
            if(b >= g-1 && g*wm >= b){
                string res = "";
                for(ll i = 0;i<g;i++){
                    for(ll j = 0;r>0&&j<wm;j++,r--) res.push_back('R');
                    ll tp = min({wm, b-max(0ll, g-i-2)});
                    while(tp){
                        res.push_back('B');
                        --tp;
                        --b;
                    }
                }
                cout<<res<<'\n';
                break;
            }
        }
    }
}