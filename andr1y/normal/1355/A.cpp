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
        ll n, k;
        cin >> n >> k;
        --k;
        while(k--){
            ll mn = 9, mx = 0;
            ll j=n;
            while(j) mn=min(mn, j%10), mx=max(mx, j%10), j/=10;
            if(mn==0) break;
            n+=mn*mx;
        }
        cout << n << '\n';
    }
}