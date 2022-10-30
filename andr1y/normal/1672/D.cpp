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
const ll N = 2e5+20;
priority_queue<ll, vector<ll>, greater<ll>> pos[N];
ll a[N], b[N];
bool sk[N];
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        for(ll i = 0;i<n;i++){
            while(pos[i].size()) pos[i].pop();
            sk[i]=false;
        }
        for(ll i = 0;i<n;i++){
            cin >> a[i];
            --a[i];
        }
        for(ll i = 0;i<n;i++){
            cin >> b[i];
            --b[i];
            if(i && b[i]==b[i-1]) pos[b[i]].push(i);
        }
        ll j = 0,ok=1;
        sk[n]=false; 
        for(ll i = 0;i<n;i++){
            while(sk[j]) ++j;
            assert(j<n);
            if(a[i] == b[j]){
                j++;
                continue;
            }
            if(pos[a[i]].size()){
                ll z = pos[a[i]].top();pos[a[i]].pop();
                while(pos[a[i]].size() && z < j) {z = pos[a[i]].top();pos[a[i]].pop();}
                if(z < j) {ok=0;break;}
                sk[z]=1;
                continue;
            }else{
                ok=0;
                break;
            }
        }
        if(ok)cout<<"YES\n";
        else cout<<"NO\n";
    }
}