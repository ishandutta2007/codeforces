#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;

int T;
ll n;

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		ll ans = n;
		ll nowval = 1;
		for(ll i = 1; i <= n; i++){
			ll g = __gcd(i, nowval);
			nowval = nowval * i / g;
			ans += n / nowval;
			if(!(n / nowval))
				break;
		}
		cout << ans % Mod << endl;
	}
	return 0;
}