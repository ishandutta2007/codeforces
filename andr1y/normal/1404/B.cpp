// keep calm and eat pizza.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
vector<ll> d[N];
ll b, da;
ll dist_a[N];
ll dist_b[N];
ll max_path[N];
ll bot[N];
ll tin[N], tout[N], timer=0;
void cd(ll v, ll h=0, ll p=-1){
    dist_a[v] = h;
    tin[v]=++timer;
    for(auto i : d[v]) if(i!=p) cd(i, h+1, v);
    tout[v]=++timer;
}
void cb(ll v, ll h=0, ll p=-1){
    dist_b[v] = h;
    for(auto i : d[v]) if(i!=p) cb(i, h+1, v);
}
ll ctwo(ll v, ll p=-1){
    bot[v]=0;
    ll mx1=0, mx2=0;
    for(auto i : d[v]){
        if(i==p) continue;
        ll k =ctwo(i, v)+1;
        bot[v]=max(bot[v], k);
        if(k>=mx1){
            mx2=mx1;
            mx1=k;
        }else if(k>mx2){
            mx2=k;
        }
    }
    max_path[v]=max(max_path[v], mx1+mx2);
    return bot[v];
}
void ctr(ll v, ll top=0, ll p=-1){
    ll mx1=0, mx2=0;
    max_path[v]=max(max_path[v], top+bot[v]);
    for(auto i : d[v]){
        if(i==p) continue;
        ll k =bot[i]+1;
        if(k>=mx1){
            mx2=mx1;
            mx1=k;
        }else if(k>mx2){
            mx2=k;
        }
    }
    for(auto i : d[v]){
        if(i==p) continue;
        ll k =bot[i]+1;
        ll vl = (k==mx1?mx2:mx1);
        ctr(i, max(top, vl)+1, v);
    }
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll q;
	cin >> q;
	while(q--){
        ll n, a, db;
        cin >> n >> a >> b >> da >> db;
        for(ll i = 1;i<=n;i++){
            d[i].clear();
            max_path[i] = 0;
        }
        for(ll i = 1, w, e;i<n;i++){
            cin >> w >> e;
            d[w].push_back(e);
            d[e].push_back(w);
        }
        cd(a);
        cb(b);
        ctwo(1);
        ctr(1);
        ll can = 0;
        for(ll  i =1;i<=n;i++){
            can=max(can, max_path[i]);
        }
        if(dist_a[b]<=da||da+da>=can||da+da>=db){
            cout<<"Alice\n";
        }else{
            cout<<"Bob\n";
        }

	}
}