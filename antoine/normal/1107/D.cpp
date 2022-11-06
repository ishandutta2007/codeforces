#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MaxN = 5201;
int n;
int a[MaxN + 2][MaxN + 2];

bool f(const int d) {
	assert(n % d == 0);
	for (int i = d; i <= n; i += d)
		for (int j = d; j <= n; j += d) {
			const int sum = a[i][j] - a[i - d][j] - a[i][j - d] + a[i - d][j - d];
			assert(0 <= sum && sum <= d * d);
			if (sum != 0 && sum != d * d)
				return false;
		}
	return true;
}

int f(char c) {
	if ('0' <= c && c <= '9')
		return c - '0';
	if ('A' <= c && c <= 'F')
		return c - 'A' + 10;
	assert(false);
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < n; ++j)
			a[i][j + 1] = (f(s[j >> 2]) & (1 << (3 - (j & 3)))) != 0;
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];

	for (int d = n; d >= 1; --d)
		if (n % d == 0 && f(d)) {
			cout << d;
			return 0;
		}
	assert(false);
	return 0;
}