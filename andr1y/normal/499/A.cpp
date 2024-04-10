// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, x, t=1, skip=0, res=0;
    cin>>n>>x;
    for(ll l, r, i = 0;i<n;i++){
        cin >> l >> r;
        ll ns = l-t;
        ll e = ns/x;
        skip+=e, t+=e*x;
        res+=r-t+1;
        t=r+1;
    }
    cout<<res;
}