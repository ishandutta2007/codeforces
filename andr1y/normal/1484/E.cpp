// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 3e5+228;
const ll inf = 0x3fff3fff3fff3fff;
ll a[N], b[N], dp[N];
ll t[4*N];
void upd(ll v, ll tl, ll tr, ll pos, ll val){
    if(tl==tr){
        t[v]=val;
        return;
    }
    ll tm=(tl+tr)>>1;
    if(pos<=tm) upd(v+v, tl, tm, pos, val);
    else upd(v+v+1, tm+1, tr, pos, val);
    t[v]=max(t[v+v], t[v+v+1]);
}
ll gm(ll v, ll tl, ll tr, ll ql, ll qr){
    if(tl>=ql&&tr<=qr) return t[v];
    ll tm = (tl+tr)>>1, e=-inf;
    if(tl<=qr&&ql<=tm) e=gm(v+v, tl, tm, ql, qr);
    if(tm+1<=qr&&ql<=tr) e=max(e, gm(v+v+1, tm+1, tr, ql, qr));
    return e;
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    for(ll i = 1;i<=n;i++) cin >> a[i];
    for(ll i = 1;i<=n;i++) cin >> b[i];
    stack<ll> st;
    dp[0]=-inf;
    for(ll i = 1;i<=n;i++){
        while(!st.empty()&&a[st.top()] > a[i]) st.pop();
        if(i==1){
            dp[i]=b[i];
        }else{
            ll fl = (st.empty()?0:st.top());
            dp[i]=max(dp[fl], gm(1, 0, n, fl, i-1)+b[i]);
        }
        upd(1, 0, n, i, dp[i]);
        st.push(i);
    }
    cout<<dp[n];
}