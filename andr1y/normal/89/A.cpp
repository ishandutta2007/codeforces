// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, m, k;
    cin >> n >> m >> k;
    ll mo = LLONG_MAX;
    for(ll a, i = 0;i<n;i++){
        cin >> a;
        if((~i)&1) mo=min(mo, a);
    }
    if(n&1){
        ll x = 1+(n-1)/2;
        cout<<min((m/x)*k, mo);
    }else cout<<0;
}