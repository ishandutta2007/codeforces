#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

const int mod = 1e9 + 7;

int bpow(int x, int n) {
	return n ? n % 2 ? x * bpow(x, n - 1) % mod : bpow(x * x % mod, n / 2) : 1;
}
int inv(int x) {
	return bpow(x, mod - 2);
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	int p[m];
	int ans = 0;
	int cur = 0;
	int cnt = 0;
	for(int i = 0; i < m; i++) {
		cin >> p[i];
		p[i]--;
		if(i == 0 || (p[i] - cnt) / k != (p[i - 1] - cnt) / k) {
			ans++;
			cnt += cur;
			cur = 1;
		} else {
			cur++;
		}
	}
	cout << ans << endl;
	return 0;
}