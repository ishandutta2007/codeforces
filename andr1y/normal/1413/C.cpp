// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll a[6];
ll e[N][6];
map<ll, vector<ll>> scl;
ll last[N];
ll t[4*N];
void upd(ll v, ll tl, ll tr, ll pos, ll val){
    if(tl==tr){
        t[v]=val;
        return;
    }
    ll tm= (tl+tr)>>1;
    if(pos<=tm) upd(v+v, tl, tm, pos, val);
    else upd(v+v+1, tm+1, tr, pos, val);
    t[v]=min(t[v+v], t[v+v+1]);
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    for(ll i =0;i<6;i++) cin >> a[i];
    ll n;
    cin >> n;
    for(ll k, i = 0;i<n;i++){
        cin >> k;
        for(ll j =0;j<6;j++){
            e[i][j] = k-a[j];
            scl[e[i][j]].push_back(i);
        }
    }
    ll mr = LLONG_MAX;
    for(auto &ps : scl){
        for(auto &i : ps.second){
            upd(1, 0, n-1, i, ps.first);
        }
        if(!t[1]) continue;
        mr=min(mr, ps.first-t[1]);
    }
    cout<<mr;
}