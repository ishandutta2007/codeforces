// -- //
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> yree;
const ll N = 128;
const ll M = 11000;
ll a[N][N], b[N][N];
stack<pair<ll, ll>> dots[M];
yree sz;
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        sz.clear();
        ll n, m;
        cin >> n >> m;
        for(ll i = 0;i<n;i++){
            for(ll j = 0;j<m;j++){
                cin >> a[i][j];
                sz.insert(a[i][j]);
            }
        }
        for(ll i = 0;i<n;i++){
            for(ll j = 0;j<m;j++){
                dots[sz.order_of_key(a[i][j])].push({i, j});
            }
        }
        for(ll i=0;i<M;i++){
            while(!dots[i].empty()){
                pair<ll, ll> ps = dots[i].top(); dots[i].pop(); b[ps.first][ps.second] = a[ps.first][ps.second];
                if(((ps.first+ps.second)&1)^(i&1)) b[ps.first][ps.second]++;
            }
        }
        for(ll i = 0;i<n;i++){
            for(ll j = 0;j<m;j++){
                cout<<b[i][j]<<' ';
            }
            cout<<'\n';
        }
    }
}