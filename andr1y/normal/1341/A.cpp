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
        ll n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        ll l1 = n*(a-b);
        ll r1 = n*(a+b);
        ll l2 = c-d, r2 = c+d;
        if(l1 <= r2 && r1 >= l2) cout << "Yes\n";
        else cout << "No\n";
    }
}