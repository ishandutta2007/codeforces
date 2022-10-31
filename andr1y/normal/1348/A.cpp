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
        ll n;
        cin >> n;
        ll r = 2;
        for(ll i = 1;i<n/2;i++){
            r+=(1ll<<i)*2;
        }
        cout << r << '\n';
    }
}