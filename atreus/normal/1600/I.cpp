#include <bits/stdc++.h>

using namespace std;

int C(int n, int r) {
	if (r > n)
		return 0;
	int ret = 1;
	for (int i = n; i > n - r; i--)
		ret *= i;
	for (int i = 2; i <= r; i++)
		ret /= i;
	return ret;
}

long double prob(int n, int x) {
	int fi = C(x, 3) * C(n - x, 0);
	int se = C(x, 2) * C(n - x, 1);
	int th = C(x, 1) * C(n - x, 2);
	int tot = C(n, 3);
	return 1. * (fi + se + (3.0/6.0)*th) / tot;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	long double P;
	cin >> n >> P;
	for (int x = 0; x <= n; x++)
		if (prob(n, x) >= P) {
			cout << x << endl;
			return 0;
		}
}