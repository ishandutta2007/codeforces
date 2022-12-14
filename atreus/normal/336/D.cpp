#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 2e5 + 50;
const int mod = 1e9 + 7;

int fac[maxn];

int power(int a, int b){
	if (b == 0)
		return 1;
	int ret = power(a, b/2);
	ret = 1ll * ret * ret % mod;
	if (b & 1)
		ret = 1ll * ret * a % mod;
	return ret;
}

int Choose(int n, int r){
	return 1ll * fac[n] * power(fac[r], mod-2) % mod * power(fac[n-r], mod-2) % mod;
}

int f(int n, int m, int g){
	if (n + m == 1)
		return n ^ g;
	if (g == 0){
		int ret = 0;
		if (m > 0)
			ret += Choose(n+m-1, n);
		if (n > 0)
			ret += f(n-1, m, 1); 
		if (ret >= mod)
			ret -= mod;
		return ret;
	}
	else{
		if (n == 0)
			return 0;
		return f(n-1, m, 0);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, g;
	cin >> n >> m >> g;
	fac[0] = 1;
	for (int i = 1; i <= n+m; i++)
		fac[i] = 1ll * fac[i-1] * i % mod;
	cout << f(n, m, g) << endl;
}