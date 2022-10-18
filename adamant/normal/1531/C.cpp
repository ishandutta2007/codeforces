#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int mod = 998244353;
const int maxn = 1e5 + 42;

int add(int a, int b) {
	return (a + b) % mod;
}
int mul(int a, int b) {
	return a * b % mod;
}
int bpow(int x, int n) {
	return n ? n % 2 ? mul(x, bpow(x, n - 1)) : bpow(mul(x, x), n / 2)  : 1;
}
int inv(int x) {
	return bpow(x, mod - 2);
}

void solve() {
	int n;
	cin >> n;
	int nn = n;
	if(n == 2) {
		cout << -1 << "\n";
		return;
	}
	int m = ceil(sqrt(n));
	vector<string> ans(m + 1, string(m, '.'));
	for(int i = 0; i < m - 1; i++) {
		for(int j = 0; j < m - 1; j++) {
			ans[i][j] = 'o';
			n--;
		}
	}
	for(int i = 0; i < m - 1; i++) {
		if(n == 1) {
			ans[m - 2][m - 2] = '.';
			n++;
		}
		if(n >= 2) {
			ans[i][m - 1] = ans[m - 1][i] = 'o';
			n -= 2;
		}
	}
	if(m * m == nn + 2) {
		m++;
		for(int i = 0; i < m; i++) {
			ans[i] += ".";
		}
		ans[m - 2][m - 3] = ans[m - 3][m - 2] = '.';
		ans[0][m - 1] = ans[m - 1][0] = 'o';
	}
	if(n) {
		ans[m - 1][m - 1] = 'o';
	}
	cout << m << "\n";
	for(int i = 0; i < m; i++) {
		cout << ans[m - i - 1] << "\n";
	}
}

signed main() {
	//ignore = freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	t = 1;//cin >> t;
	while(t--) {
		solve();
	}
}