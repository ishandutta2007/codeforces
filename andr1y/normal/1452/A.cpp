// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll x, y;
        cin >> x >> y;
        ll a1 = min(x, y);
        ll r = a1*2+max(0ll, (x-a1)*2-1)+max(0ll, (y-a1)*2-1);
        cout<<r<<'\n';
    }
}