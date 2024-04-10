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
const ll N =2e5+20;
ll a[N];
ll res[N];
pll of[N];
pll cnt[N];
vector<ll> pos[N];
ll dq[N*7], dqs=0, dqz=0;
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        for(ll i = 0;i<n;i++){
            cnt[i]={0, i};
            pos[i].clear();
        }
        for(ll i = 0;i<n;i++){
            cin >> a[i];
            --a[i];
            cnt[a[i]].x++;
            pos[a[i]].push_back(i);
        }
        sort(cnt, cnt+n, greater<pll>());
        while(cnt[0].x*2 > n){
            cnt[0].x--;
            res[pos[cnt[0].y].back()] = cnt[0].y;
            pos[cnt[0].y].pop_back();
        }
        assert(n == 1 || cnt[0].x >= cnt[1].x);
        ll xn = 0;
        while(cnt[xn].x) xn++;
        dqs=0,dqz=xn;
        for(ll i = 0;i<xn;i++) {dq[i]=i;of[i]=cnt[i];}
        for(ll i = 0;i<xn;i++){
            while(of[dq[dqs]].x == 0) dqs++;
            if(dq[dqs] == i){
                dq[dqz++]=i;
                dqs++;
            }
            while(cnt[i].x){
                cnt[i].x--;
                pll &tk = of[dq[dqs]];
                res[pos[tk.y].back()] = cnt[i].y;
                pos[tk.y].pop_back();
                tk.x--;
                if(tk.x == 0) dqs++;
            }
        }
        for(ll i = 0;i<n;i++) cout<<res[i]+1<<' ';
        cout<<'\n';
    }
}