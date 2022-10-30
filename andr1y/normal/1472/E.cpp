// -- //
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> yree;
const ll N = 2e5+228;
yree sz;
ll h[N], w[N];
pll mvf[N+N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        sz.clear();
        memset(mvf, 0x3f, sizeof(ll)*(n+n+n+n+20));
        sz.insert(0);
        for(ll i = 0;i<n;i++){
            cin >> h[i] >> w[i];
            sz.insert(h[i]);
            sz.insert(w[i]);
        }
        for(ll i = 0;i<n;i++){
            h[i]=sz.order_of_key(h[i]);
            w[i]=sz.order_of_key(w[i]);
        }
        for(ll i = 0;i<n;i++){
            if(w[i]<mvf[h[i]].x) mvf[h[i]]={w[i], i};
            if(h[i]<mvf[w[i]].x) mvf[w[i]]={h[i], i};
        }
        for(ll i = 1;i<n+n+10;i++){
            if(mvf[i].x>=mvf[i-1].x) mvf[i]=mvf[i-1];
        }
        for(ll i = 0;i<n;i++){
            if(mvf[h[i]-1].x<w[i]){
                cout<<mvf[h[i]-1].y+1<<' ';
            }else if(mvf[w[i]-1].x<h[i]){
                cout<<mvf[w[i]-1].y+1<<' ';
            }else cout<<"-1 ";
        }
        cout<<'\n';
    }
}