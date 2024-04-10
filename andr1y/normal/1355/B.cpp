//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
ll a[N];
ll fwt[N];
void fwset(ll pos, ll del){
    ++pos;
    for(;pos<N;pos+=pos&-pos) fwt[pos]=max(fwt[pos], del);
}
ll fwmax(ll r, ll s=0){
    ++r;
    for(;r>0;r-=r&-r) s=max(s, fwt[r]);
    return s;
}
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	ll q, n;
	cin >> q;
	while(q--){
        cin >> n;
        for(ll i = 0;i<n;i++){
            cin >> a[i];
            fwt[i+1] = 0;
        }
        sort(a, a+n, greater<ll>());
        for(ll i = 0;i<n;i++){
            ll val = (i?fwmax(i-1):0);
            if(i+a[i]-1>=n) continue;
            ll pp = i+a[i]-1;
            fwset(pp, val+1);
        }
        cout << fwmax(n-1) << '\n';
	}
}