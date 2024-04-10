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
const ll N = 2020;

ll toc[N][N];

ll oc[N];

signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        for(ll i = 0;i<n;i++) oc[i]=0;
        for(ll j = 0;j<n;j++){
            ll px = j;
            for(ll i = 0;i<n;i++){
                toc[i][px] = j;
                px ++;
                if(px == n) px=0;
            }
        }
        ll so = 0;
        for(ll i = 0;i<n;i++){
            for(ll j = 0;j<n;j++){
                char x;cin>>x;
                ll y=x-'0';
                oc[toc[i][j]]+=y;
                so += y;
            }
        }
        ll res = n*n;
        for(ll i = 0;i<n;i++){
            ll t = n-oc[i] + (so - oc[i]);
            res=min(res, t);
        }
        cout<<res<<'\n';
    }
}