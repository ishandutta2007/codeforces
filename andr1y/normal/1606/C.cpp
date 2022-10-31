//ulala
//code by 255
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> yree;
const ld inf = 0x3fff3fff3fff3fff;
const ll N = 5e5+18;
ll a[N];
ll p10[15];

signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    p10[0]=1;
    for(ll i = 1;i<15;i++) p10[i]=p10[i-1]*10;
    ll q;
    cin >> q;
    while(q--){
        ll n, k;
        cin >> n >> k;
        for(ll i = 0;i<n;i++) cin >> a[i];
        ++k;
        string res;
        for(ll i = 0;i<n;i++){
            ll maxc = (i+1<n?p10[a[i+1]-a[i]]-1:k);
            ll th = min(maxc, k);
            k-=th;
            if(k){
                ll ont = a[i+1]-a[i];
                while(ont){
                    res.push_back('0'+(th%10));
                    th/=10;
                    ont--;
                }
            }else{
                while(th){
                    res.push_back('0'+(th%10));
                    th/=10;
                }
            }
        }
        reverse(begin(res), end(res));
        cout<<res<<'\n';
    }
}