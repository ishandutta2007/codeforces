#include <bits/stdc++.h>

const int N = 200005, P = 1000000007;

int n;
int a[N];

void inc(int &a, int b) {
	a + b >= P ? a += b - P : a += b;
}

void dec(int &a, int b) {
	a < b ? a += P - b : a -= b;
}

void solve() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	std::map<long long, int> f;
	f[0] = 1;
	long long d = 0;
	int sum = 1;
	for (int i = 1; i <= n; ++i) {
		int f0 = f[-d];
		d += a[i];
		inc(f[a[i] - d], sum);
		dec(f[a[i] - d], f0);
		inc(sum, sum);
		dec(sum, f0);
	}
	std::cout << sum << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T = 1;
	std::cin >> T;
	while (T--) {
		solve();
	}
}