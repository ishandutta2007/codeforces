#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

int mod;

int add(int a, int b) {
	return (a + b) % mod;
}
int sub(int a, int b) {
	return (a - b + mod) % mod;
}
int mul(int a, int b) {
	return a * b % mod;
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, p, k;
	cin >> n >> p >> k;
	mod = p;
	int a[n];
	map<int, int> cnt;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[sub(mul(a[i], mul(a[i], mul(a[i], a[i]))), mul(a[i], k))]++;
	}
	int ans = 0;
	for(auto it: cnt) {
		ans += it.second * (it.second - 1) / 2;
	}
	cout << ans << endl;
	return 0;
}