//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll a[N];
ll t[N*4], w[N*4];
bool leaf[N*4];
void build(ll v, ll tl, ll tr){
    if(tl==tr){
        leaf[v]=1;
        return;
    }
    ll tm = (tl+tr)>>1;
    build(v+v, tl, tm);
    build(v+v+1, tm+1, tr);
//    t[v]=max(t[v+v], t[v+v+1]);
}
void push(ll v){
    if(leaf[v]){
        w[v]=0;
    }else{
        w[v+v]+=w[v];
        w[v+v+1]+=w[v];
        t[v+v]+=w[v];
        t[v+v+1]+=w[v];
        w[v]=0;
    }
}
void inc_seg(ll v, ll tl, ll tr, ll l, ll r, ll val){
    if(l<=tl&&r>=tr){
        t[v]+=val;
        w[v]+=val;
        return;
    }
    push(v);
    ll tm = (tl+tr)>>1;
    if(tm>=l&&r>=tl) inc_seg(v+v, tl, tm, l, r, val);
    if(tr>=l&&r>tm) inc_seg(v+v+1, tm+1, tr, l, r, val);
    t[v]=max(t[v+v], t[v+v+1]);
}
ll get_max(ll v, ll tl, ll tr, ll l, ll r){
    if(l<=tl&&r>=tr){
        return t[v];
    }
    push(v);
    ll dt=-31*(tr-tl+1);
    ll tm = (tl+tr)>>1;
    if(tm>=l&&r>=tl) dt=max(dt, get_max(v+v, tl, tm, l, r));
    if(tr>=l&&r>tm) dt=max(dt, get_max(v+v+1, tm+1, tr, l, r));
    return dt;
}
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    for(ll i =0;i<n;i++){
        cin >> a[i];
    }
    build(1, 0, n-1);
    stack<pair<ll, ll>> mxc;
    ll res=-31*n;
    for(ll i = 0;i<n;i++){
        while(!mxc.empty()&&mxc.top().first<=a[i]) mxc.pop();
        mxc.push({a[i], i});
        vector<pair<ll, ll>> dt;
        dt.reserve(mxc.size());
        while(!mxc.empty()){
            dt.push_back(mxc.top());
            mxc.pop();
        }
//        cout << i << ": ";
//        for(auto j : dt)cout<<j.first <<';'<<j.second<< ' ';
//        cout<<'\n';
        inc_seg(1, 0, n-1, 0, i, a[i]);
        for(ll j = 0;j<dt.size();j++){
            ll to = (j==dt.size()-1?0:dt[j+1].second+1);
            ll mx = dt[j].first;
            res=max(res, get_max(1, 0, n-1, to, dt[j].second)-mx);
        }
        for(ll j = dt.size()-1;j>=0;j--){
            mxc.push(dt[j]);
        }
    }
    cout<<res<<'\n';
}