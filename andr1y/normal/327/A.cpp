// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    ll mb = 0, r=-n, tb=0, kb=0;
    for(ll a, i=0;i<n;i++){
        cin >> a;
        if(a==0) tb++;
        else tb--, kb++;
        r=max(r, tb-mb);
        mb=min(mb, tb);
    }
    cout<<kb+r;
}