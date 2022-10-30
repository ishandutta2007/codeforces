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
    ll q;cin >> q;
    while(q--){
        string s;
        ll n;
        cin >> n;
        cin >> s;
        ll bls=0, b=0,w=0;
        bool ok = 1;
        for(auto i : s){
            if(i=='W'){
                if(bls == 0) continue;
                if(b==0||w==0) ok =0;
                b=0,w=0,bls=0;
            }else{
                if(i=='B') b++;
                else w++;
                bls++;
            }
        }
        if(bls > 0 && (b==0||w==0)) ok=0;
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
}