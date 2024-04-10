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
        ll ff = n;
        for(ll i = 2;i*i<=n;i++){
            if(n%i==0){
                ff=i;
                break;
            }
        }
        if(k == 1) cout << n+ff << '\n';
        else{
            ll u = k;
            if(ff == 2) u = k;
            else u = k-1, n+=ff;
            cout << n+u*2<<'\n';
        }
    }
}