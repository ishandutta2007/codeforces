// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll fit(ll l, ll r, ll m, ll k){
    if(r<=m) return r*(k-r);
    if(r>m&&l<=m) return m*(k-m);
    if(l>m) return l*(k-l);
}
ll fit2(ll l, ll r, ll m, ll k){
    if(l>=m) return l*(k-l);
    if(r>=m&&l<=m) return m*(k-m);
    if(r<m) return r*(k-r);
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll l, r, rs=0;
    cin >> l >> r;
    for(ll i=10;i<=r*10;i*=10){
        ll el = max(l, i/10);
        ll er = min(r, i-1);
        ll mid = (i-1)/2;
        rs=max(rs, fit(l, r, mid, i-1));
        rs=max(rs, fit2(l, r, mid+1, i-1));
    }
    cout<<rs;
}