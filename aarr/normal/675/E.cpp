#include <iostream>
using namespace std;

const int N = 1000 * 1000 + 5, LG = 19;

int a[N];
pair <int, int> mx[N][LG];
long long dp[N];

int get(int l, int r) {
	r++;
	int d = 31 - __builtin_clz(r - l);
	pair <int, int> p = max(mx[l][d], mx[r - (1 << d)][d]);
	return p.second;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a[i];
		mx[i][0] = {a[i], i};
	}
	mx[n][0] = {n, n};
	for (int j = 1; j < LG; j++) {
		for (int i = 1; i <= n; i++) {
			mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
		}
	}
	long long ans = 0;
	for (int i = n - 1; i; i--) {
		int x = get(i + 1, a[i]);
	//	cout << "73 " << i << " " << x << endl;
		dp[i] = dp[x] + n - i - a[i] + x;
		ans += dp[i];
	}
	cout << ans;
	return 0;
}