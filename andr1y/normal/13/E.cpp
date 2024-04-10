//ulala
//code by 255
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> yree;
const ll inf = 0x3fff3fff3fff3fff;
const ll N = 1e5+18;
const ll C = 316;
ll a[N];
ll next_out[N], next_cost[N], next_bef[N];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    for(ll i =0;i<n;i++) cin >> a[i];
    for(ll i = n-1;i>=0;i--){
        ll nxt = i+a[i];
        if(nxt>=n) nxt = -1;
        ll b = i/C;
        ll nb = (b+1)*C;
        if(nxt==-1){
            next_out[i] = -1;
            next_cost[i] = 1;
            next_bef[i] = i;
        }else{
            if(nxt >= nb){
                next_out[i] = nxt;
                next_cost[i] = 1;
                next_bef[i] = i;
            }else{
                next_out[i] = next_out[nxt];
                next_cost[i] = next_cost[nxt]+1;
                next_bef[i] = next_bef[nxt];
            }
        }
    }
    while(m--){
        ll t;
        cin >> t;
        if(t==0){
            ll ai, v;
            cin >> ai >> v;
            --ai; a[ai]=v;
            ll b = ai/C, bs = b*C, nb = min(n, (b+1)*C);
            for(ll i = nb-1;i>=bs;i--){
                ll nxt = i+a[i];
                if(nxt>=n) nxt = -1;
                if(nxt==-1){
                    next_out[i] = -1;
                    next_cost[i] = 1;
                    next_bef[i] = i;
                }else{
                    if(nxt >= nb){
                        next_out[i] = nxt;
                        next_cost[i] = 1;
                        next_bef[i] = i;
                    }else{
                        next_out[i] = next_out[nxt];
                        next_cost[i] = next_cost[nxt]+1;
                        next_bef[i] = next_bef[nxt];
                    }
                }
            }
        }else{
            ll ai;cin >> ai;--ai;
            ll did=0, bai = ai;
            while(ai!=-1){
                did+=next_cost[ai];
                bai=next_bef[ai];
                ai=next_out[ai];
            }
            cout<<bai+1<<' '<<did<<'\n';
        }
    }
}