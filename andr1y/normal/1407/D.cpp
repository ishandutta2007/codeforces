// keep calm and eat pizza.
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 3e5+228;
const ll MAI = 1e9;
const ll inf = 0x3f3f3f3f3f3f3f3f;
ll a[N], ra[N], dp[N];
ll fgr[N], fgl[N], rfgr[N], rfgl[N];
ll t[2][4*N];
void upd(ll e, ll v, ll tl, ll tr, ll pos, ll val){
    if(tl==tr){
        t[e][v] = val;
        return;
    }
    ll tm = (tl+tr)>>1;
    if(pos<=tm) upd(e, v+v, tl, tm, pos, val);
    else upd(e, v+v+1, tm+1, tr, pos, val);
    t[e][v]=min(t[e][v+v], t[e][v+v+1]);
}
ll mn(ll e, ll v, ll tl, ll tr, ll l, ll r){
    if(l<=tl&&r>=tr) return t[e][v];
    ll tm = (tl+tr)>>1;
    ll u = LLONG_MAX;
    if(l<=tm&&tl<=r) u=mn(e, v+v, tl, tm, l, r);
    if(l<=tr&&tm+1<=r) u=min(u, mn(e, v+v+1, tm+1, tr, l, r));
    return u;
}
vector<ll> ddl[N], ddl2[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    dp[0]=0;
    memset(t, 0x3f, sizeof(t));
    ll n;
    cin >> n;
    for(ll i = 0;i<n;i++){
        cin >> a[i];
        ra[i]=MAI-a[i];
    }
    stack<pll> st;
    for(ll i =0;i<n;i++){
        while(!st.empty()&&st.top().x<a[i]) st.pop();
        fgl[i] = (st.empty()?-1:st.top().y);
        st.push({a[i], i});
    }
    while(!st.empty()) st.pop();
    for(ll i =n-1;i>=0;i--){
        while(!st.empty()&&st.top().x<a[i]) st.pop();
        fgr[i] = (st.empty()?n:st.top().y);
        st.push({a[i], i});
    }

    while(!st.empty()) st.pop();
    for(ll i =0;i<n;i++){
        while(!st.empty()&&st.top().x<ra[i]) st.pop();
        rfgl[i] = (st.empty()?-1:st.top().y);
        st.push({ra[i], i});
    }
    while(!st.empty()) st.pop();
    for(ll i =n-1;i>=0;i--){
        while(!st.empty()&&st.top().x<ra[i]) st.pop();
        rfgr[i] = (st.empty()?n:st.top().y);
        st.push({ra[i], i});
    }

    upd(0, 1, 0, n-1, 0, dp[0]+1);
    upd(1, 1, 0, n-1, 0, dp[0]+1);
    ddl[fgr[0]].push_back(0);
    ddl2[rfgr[0]].push_back(0);


    for(ll i = 1;i<n;i++){
        dp[i]=dp[i-1]+1;
        //t1
        ll k = fgl[i];
        if(k>=0) dp[i]=min(dp[i], dp[k]+1);
        dp[i]=min(dp[i], mn(0, 1, 0, n-1, k+1, i));
        for(auto j : ddl[i]){
            upd(0, 1, 0, n-1, j, inf);
        }
        //tr
        k = rfgl[i];
        if(k>=0) dp[i]=min(dp[i], dp[k]+1);
        dp[i]=min(dp[i], mn(1, 1, 0, n-1, k+1, i));
        for(auto j : ddl2[i]){
            upd(1, 1, 0, n-1, j, inf);
        }
        upd(0, 1, 0, n-1, i, dp[i]+1);
        upd(1, 1, 0, n-1, i, dp[i]+1);
        ddl[fgr[i]].push_back(i);
        ddl2[rfgr[i]].push_back(i);
    }
    cout<<dp[n-1];
}