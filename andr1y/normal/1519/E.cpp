// -- //
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<pll, null_type, less<pll>, rb_tree_tag, tree_order_statistics_node_update> yree;
const ll N = 2e5+228;
void skor(ll &a, ll &b){
    ll g = __gcd(a, b);
    a/=g, b/=g;
}
pair<pll, pll> oaa[N];
yree sz;
pll a[N];
bool ban[N];
vector<pll> d[2*N];
vector<pll> kidd[2*N];
vector<pll> pairs;
ll tin[2*N], tout[2*N], timer=0;
void dfs1(ll v){
    tin[v]=++timer;
    for(auto i : d[v]){
        if(tin[i.x]==0){
            dfs1(i.x);
            kidd[v].push_back(i);
        }
    }
    tout[v]=++timer;
}
bool edgeban[2*N];
void dfs(ll v, ll p=-1, ll pc=-1){
    vector<ll> avb;
    ban[v]=1;
    for(auto i : kidd[v]){
        dfs(i.x, v, i.y);
    }
    for(auto i : d[v]){
        if(tin[i.x]>tin[v]&&tout[i.x]<tout[v]){
            if(!edgeban[i.y]) avb.push_back(i.y);
        }
    }
    ll qq=-1;
    for(auto i : avb){
        if(qq==-1){
            qq=i;
        }else{
            pairs.push_back({qq, i});
            edgeban[qq]=edgeban[i]=1;
            qq=-1;
        }
    }
    if(qq!=-1){
        if(p!=-1){
            pairs.push_back({pc, qq});
            edgeban[qq]=edgeban[pc]=1;
        }
    }
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    for(ll i = 0;i<n;i++){
        pll x, y;
        cin >> x.x >> x.y >> y.x >> y.y;
        oaa[i].x = {(x.x+x.y)*(y.y), (x.y)*(y.x)};
        oaa[i].y = {(x.x)*(y.y), (x.y)*(y.x+y.y)};
        skor(oaa[i].x.x, oaa[i].x.y);
        skor(oaa[i].y.x, oaa[i].y.y);
        sz.insert(oaa[i].x);
        sz.insert(oaa[i].y);
    }
    for(ll i = 0;i<n;i++){
        a[i].x = sz.order_of_key(oaa[i].x);
        a[i].y = sz.order_of_key(oaa[i].y);
        d[a[i].x].push_back({a[i].y, i});
        d[a[i].y].push_back({a[i].x, i});
        //cerr<<a[i].x<<' '<<a[i].y<<'\n';
    }
    for(ll i = 0;i<sz.size();i++){
        if(tin[i]==0) dfs1(i);
    }
    for(ll i = 0;i<sz.size();i++){
        if(!ban[i]) dfs(i);
    }
    cout<<pairs.size()<<'\n';
    for(auto i : pairs){
        cout<<i.x+1<<' '<<i.y+1<<'\n';
    }
}