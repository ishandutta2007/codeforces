#include <bits/stdc++.h>

using namespace std;
typedef int ll;

const ll mod = (int) 2e5;
int a[2001];

ll f(ll x) {
	return (x % mod + mod) % mod;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];


	cout << n + 1 << '\n';
	ll lazy = 0;
	for (int i = n; i >= 1; --i) {
		a[i] += lazy;
		const ll curr = f(-(n + 1 - i) - a[i]);
		cout << "1 " << i << ' ' << curr << '\n';
		lazy += curr;
	}
	cout << "2 " << n << ' ' << mod << '\n';
	return 0;
}