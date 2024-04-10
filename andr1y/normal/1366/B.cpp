//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;

signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, x, m;
        cin >> n >> x >> m;
        ll l = x, r = x;
        while(m--){
            ll li, ri;
            cin >> li >> ri;
            if(l <= ri && li <= r) l = min(l, li), r=max(r, ri);
        }
        cout<<r-l+1<<'\n';
    }
}