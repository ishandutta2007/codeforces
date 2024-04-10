# include <cstdio>
# include <cstring>
# include <algorithm>
# include <iostream>
# define ll long long
using namespace std;
const ll PR = 1000000007;
ll m, n, tmp;
ll fnl = 1;
ll pwr(ll x, ll y){
	ll ans = 1;
	y %= PR - 1;
	while (y){
		if (y & 1) ans = ans * x % PR;
		x = x * x % PR;
		y >>= 1;
	}
	return ans % PR;
}
ll count(ll x){
	ll num = 1, ans = 0;
	while (num <= n / x){
		num *= x;
		ans += n / num;
	}
	return ans;
}
int main(){
	cin >> m >> n;
	tmp = m;
	for (int i = 2; i <= tmp && i * i <= m; i++){
		if (tmp % i == 0){
			while (tmp % i == 0) tmp /= i;
			fnl = fnl * pwr(i, count(i)) % PR;
		}
	}
	if (tmp != 1) fnl = fnl * pwr(tmp, count(tmp)) % PR;
	cout << fnl << endl;
	return 0;
}