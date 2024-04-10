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
const ll N = 1024;
vector<pair<pll, ll>> ops;
ll a[N][N];
bool isin[N][N];
queue<pll> woc;
ll n, m, rdel=0;
inline void checkb(ll i, ll j){
    if(i<0 ||j<0||i+1>=n || j+1>=m || isin[i][j]) return;
    ll c = max({a[i][j], a[i+1][j], a[i][j+1], a[i+1][j+1]});
    if(!c) return;
    if((a[i][j] == 0 || a[i][j] == c) && (a[i][j+1] == 0 || a[i][j+1] == c) && (a[i+1][j] == 0 || a[i+1][j] == c) && (a[i+1][j+1] == 0 || a[i+1][j+1] == c)){
        woc.push({i, j});
        isin[i][j]=1;
    }
}
inline void revb(ll i, ll j){
    if(a[i][j]) rdel++;
    if(a[i][j+1]) rdel++;
    if(a[i+1][j]) rdel++;
    if(a[i+1][j+1]) rdel++;
    a[i][j]=0;
    a[i][j+1]=0;
    a[i+1][j]=0;
    a[i+1][j+1]=0;
    checkb(i-1, j-1);
    checkb(i-1, j);
    checkb(i-1, j+1);
    checkb(i, j-1);
    checkb(i, j+1);
    checkb(i+1, j-1);
    checkb(i+1, j);
    checkb(i+1, j+1);
}
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(ll i = 0;i<n;i++){
        for(ll j = 0;j<m;j++){
            cin >> a[i][j];
        }
    }
    for(ll i =0;i+1<n;i++){
        for(ll j =0;j+1<m;j++) checkb(i, j);
    }
    while(!woc.empty()){
        pll v=woc.front(); woc.pop();
        ll i=v.x, j=v.y;
        ll c = max({a[i][j], a[i+1][j], a[i][j+1], a[i+1][j+1]});
        if(!c) continue;
        ops.push_back({{i, j}, c});
        revb(i, j);
    }
    if(rdel == n*m){
        cout<<ops.size()<<'\n';
        reverse(ops.begin(), ops.end());
        for(auto i :ops){
            cout<<i.x.x+1<<' '<<i.x.y+1<<' '<<i.y<<'\n';
        }
    }else{
        cout<<-1;
    }
}