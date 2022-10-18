#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

const int mod = 998244353;

const int maxn = 1e5 + 42;

int add(int a, int b) {
	return (a + b) % mod;
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int b[n];
	adjacent_difference(a, a + n, b);
	sort(b, b + n);
	int d = maxn / (k - 1);
	int ans = 0;
	for(int z = 0; z <= d; z++) {
		int d[n + 1][k + 1];
		int s[n + 1][k + 1];
		memset(d, 0, sizeof(d));
		memset(s, 0, sizeof(s));
		d[0][0] = s[0][0] = 1;
		int p = 0;
		for(int i = 1; i <= n; i++) {
			while(a[i - 1] - a[p] >= z) {
				p++;
			}
			for(int j = 1; j <= k; j++) {
				d[i][j] = s[p][j - 1];
				s[i][j] = add(d[i][j], s[i - 1][j]);
			}
			s[i][0] = 1;
		}
		ans = add(ans, s[n][k]);
	}
	cout << ans << endl;
	return 0;
}