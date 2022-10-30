// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 5005;
ll a[N][15];
ll mlog2[N];
ll solve(ll l, ll r, ll off){
    if(l==r) return 1;
    ll lg = mlog2[r-l+1];
    ll mv = min(a[l][lg], a[r-(1<<lg)+1][lg]);
    ll v2=(mv-off);
    ll bs=0;
    for(ll i = l;i<=r;i++){
        if(a[i][0]>mv) bs++;
        else{
            if(bs) v2+=solve(i-bs, i-1, mv);
            bs=0;
        }
    }
    if(bs) v2+=solve(r+1-bs, r, mv);
    return min(v2, r-l+1);
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	for(ll i = 2;i<N;i++) mlog2[i]=mlog2[i>>1]+1;
    ll n;
    cin >> n;
    for(ll i = 0;i<n;i++){
        cin >> a[i][0];
    }
    for(ll L = 1;(1<<L)<=n;L++){
        for(ll i = 0;i+(1<<L)-1<n;i++){
            a[i][L]=min(a[i][L-1], a[i+(1<<(L-1))][L-1]);
        }
    }
    cout<<solve(0, n-1, 0);
}