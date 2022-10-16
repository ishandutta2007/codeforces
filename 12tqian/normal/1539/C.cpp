#include <bits/stdc++.h>

using namespace std;

const int A = 26; 

void solve_case(int tc = 0) {
	int n;
	long long k, x;
	cin >> n >> k >> x;
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	if (n == 1) {
		cout << 1 << '\n';
		return;
	}
	sort(a.begin(), a.end());
	vector<long long> b(n - 1);
	for (int i = 0; i < n - 1; ++i) {
		long long g = a[i + 1] - a[i];
		if (g % x == 0) {
			b[i] = max(g / x - 1, 0LL);
		} else {
			b[i] = g / x;
		}
	}
	sort(b.begin(), b.end());
	__int128_t sum = 0;
	for (int i = 0; i < n - 1; ++i) {
		sum += b[i];
	}
	int ans = 0;
	while (sum > k) {
		sum -= b.back();
		b.pop_back();
		++ans;
	}
	cout << ans + 1 << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1; 
	// cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}