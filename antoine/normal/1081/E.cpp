#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void No() {
	cout << "No\n";
	exit(0);
}

ll fSqrt(const ll x) {
	ll y = (ll) sqrt(x);
	while (y * y > x)
		--y;
	while ((y + 1) * (y + 1) <= x)
		++y;
	return y;
}

bool f(const ll x) {
	const ll y = fSqrt(x);
	return y * y == x;
}

const int MaxN = (int) 1e5 + 9;
ll a[MaxN + 9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	for (int i = 2; i <= n; i += 2)
		cin >> a[i];

	ll x = 0;

	for (int i = 1; i <= n; i++) {
		if (i & 1) {
			const ll prev = x * x;
			do
				++x;
			while (x <= MaxN && !f(x * x + a[i + 1]));
			if (x > MaxN)
				No();
			a[i] = x * x - prev;
		} else
			x = fSqrt(x * x + a[i]);
	}

	cout << "Yes\n";
	for (int i = 1; i <= n; ++i)
		cout << a[i] << ' ';
	return 0;
}