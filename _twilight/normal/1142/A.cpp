#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

ll gcd(ll a, ll b) {
	return (b) ? (gcd(b, a % b)) : (a);
}

template <typename T>
T __abs(T x) {
	return (x < 0) ? (-x) : (x);
}

ll n, k, M;
ll a, b;
ll x = 1e18, y;

int main() {
	cin >> n >> k;
	cin >> a >> b;
	M = n * k;

	ll s = a, t, T;
	for (int i = 0; i < n; i++) {
		t = k * i + b;
		x = min(x, T = M / gcd(M, __abs(t - s)));
		y = max(y, T);

		t = k * (i + 1) - b;
		x = min(x, T = M / gcd(M, __abs(t - s)));
		y = max(y, T);
	}

	s = k - a;
	for (int i = 0; i < n; i++) {
		t = k * i + b;
		x = min(x, T = M / gcd(M, __abs(t - s)));
		y = max(y, T);

		t = k * (i + 1) - b;
		x = min(x, T = M / gcd(M, __abs(t - s)));
		y = max(y, T);
	}

	cout << x << " " << y << '\n';
	return 0;
}