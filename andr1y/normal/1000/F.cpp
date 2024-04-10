// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 5e5+228;
const ll inf = 0x3fff3fff3fff3fff;
ll a[N], last[N];
pll t[4*N];
void build(ll v, ll tl, ll tr){
    t[v]={inf, tl};
    if(tl==tr){
        return;
    }
    ll tm=(tl+tr)>>1;
    build(v+v, tl, tm);
    build(v+v+1, tm+1, tr);
}
void upd(ll v, ll tl, ll tr, ll pos, ll val){
    if(tl==tr){
        t[v].x=val;
        return;
    }
    ll tm=(tl+tr)>>1;
    if(pos<=tm) upd(v+v, tl, tm, pos, val);
    else upd(v+v+1, tm+1, tr, pos, val);
    if(t[v+v+1].x<t[v+v].x) t[v]=t[v+v+1];
    else t[v]=t[v+v];
}
pll get(ll v, ll tl, ll tr, ll ql){
    if(tl>=ql) return t[v];
    ll tm = (tl+tr)>>1;
    pll e = get(v+v+1, tm+1, tr, ql);
    if(ql<=tm){
        pll u = get(v+v, tl, tm, ql);
        if(u.x<e.x) e=u;
    }
    return e;
}
ll qr[N];
vector<pll> qs[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    memset(last, 0xff, sizeof last);
    for(ll i = 0;i<n;i++) cin >> a[i];
    ll q;
    cin >> q;
    for(ll i = 0;i<q;i++){
        ll l, r;cin>>l>>r;
        --l, r--;
        qs[r].push_back({l, i});
    }
    build(1, 0, n-1);
    for(ll i = 0;i<n;i++){
        if(last[a[i]]==-1){
            upd(1, 0, n-1, i, -1);
        }else{
            upd(1, 0, n-1, i, last[a[i]]);
            upd(1, 0, n-1, last[a[i]], inf);
        }
        last[a[i]]=i;
        for(auto j : qs[i]){
            pll u = get(1, 0, n-1, j.x);
            qr[j.y]=(u.x>=j.x ? 0 : a[u.y]);
        }
    }
    for(ll i = 0;i<q;i++) cout<<qr[i]<<'\n';
}