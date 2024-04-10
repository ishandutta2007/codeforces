// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, s;
    cin >> n >> s;
    ll ans=-1;
    for(ll x, y, i = 0;i<n;i++){
        cin >>x >> y;
        if(x>s||(x==s&&y)) continue;
        if(y==0) ans=max(ans, 0ll);
        else ans=max(ans, 100-y);
    }
    cout<<ans;
}