#include<bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

using ll = long long;

int n, k, h[1000005], t[1000005], m[1000005];

ll add(ll x, ll y) {
	return (x + y) % MOD;
}

ll muli(ll x, ll y) {
	return (x * y) % MOD;
}

ll power(ll x, ll y) {
	if (y == 0) return 1;
	ll temp = power(x, y / 2);
	if (y % 2) {
		return muli(temp, muli(temp, x));
	} else {
		return muli(temp, temp);
	}
}

ll inv(ll x) {
	return power(x, MOD - 2);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n >> k;
	h[1] = 1;
	for (int i = 2; i <= k + 2; i++) {
		h[i] = add(h[i - 1], power(i, k));
	}	
	if (n <= k + 2) return cout << (h[n] + MOD) % MOD, 0;
	t[1] = 1;
	for (int i = 2; i <= k + 2; i++) {
		t[1] = muli(t[1], n - i);
		t[1] = muli(t[1], inv(1 - i));
	}
	for (int i = 2; i <= k + 2; i++) {
		t[i] = muli(t[i - 1], muli(n - i + 1, i - 3 - k));
		t[i] = muli(t[i], inv(muli(n - i, i - 1)));
	}
	long long ans = 0;
	for (int i = 1; i <= k + 2; i++) {
		ans = add(ans, muli(t[i], h[i]));
	}
	cout << (ans + MOD) % MOD;
	return 0;
}