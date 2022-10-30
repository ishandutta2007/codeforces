// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll a[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, q, k;
    cin >> n >> q >> k;
    for(ll i = 0; i<n;i++) cin >> a[i];
    while(q--){
        ll l, r;
        cin >> l >> r;
        --l, r--;
        ll s = k-(r-l+1) + (a[r]-a[l]+1-(r-l+1));
        cout<<s<<'\n';
    }
}