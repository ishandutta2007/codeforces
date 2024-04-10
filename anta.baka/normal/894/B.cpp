#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

ll pw(ll a, ll b) {
	if(!b) return 1;
	if(b & 1) return a * pw(a, b - 1) % mod;
	a = pw(a, b / 2);
	return a * a % mod;
}

int main() {
	ll n, m, k; cin >> n >> m >> k;
	if(n % 2 != m % 2 && k == -1) return cout << 0, 0;
	cout << pw(pw(2, n - 1), m - 1);
}