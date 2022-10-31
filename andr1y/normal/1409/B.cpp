// keep calm and eat pizza.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll q;
	cin >> q;
	while(q--){
        ll a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        if(a>b){
            swap(a, b);
            swap(x, y);
        }
        if(a==b&&x>y){
            swap(a, b);
            swap(x, y);
        }
        ll k = min(n, a-x);
        ll v1 = (a-k)*(b-min(n-k, b-y));
        k = min(n, b-y);
        ll v2 = (b-k)*(a-min(n-k, a-x));
        cout<<min(v1, v2)<<'\n';
	}
}