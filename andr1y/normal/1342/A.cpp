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
	    ll x, y, a, b;
	    cin >> x >> y >> a >> b;
	    if(a*2>b){
	        cout << b*min(x, y)+abs(x-y)*a;
	    }else cout << a*(x+y);
	    cout << '\n';
	}
}