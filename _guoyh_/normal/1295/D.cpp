# include <cstdio>
# include <cstring>
# include <iostream>
# include <algorithm>
# define ll long long
using namespace std;
int t;
ll a, m;
ll gcd(ll x, ll y){
	if (y == 0) return x;
	return gcd(y, x % y);
}
ll phi(ll x){
	ll ans = x;
	for (ll i = 2; i * i <= x; i++){
		if (x % i == 0){
			while (x % i == 0) x /= i;
			ans = ans / i * (i - 1);
		}
	}
	if (x != 1) ans = ans / x * (x - 1);
	return ans;
}
int main(){
	cin >> t;
	while (t--){
		cin >> a >> m;
		cout << phi(m / gcd(a, m)) << endl;
	}
	return 0;
}