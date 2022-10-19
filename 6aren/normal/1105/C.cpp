#include<bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

long long n, l, r, f[200005][3];

int calc(int x, int y) {
	return (x + 3 - y) / 3;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n >> l >> r;
	int cnt0, cnt1, cnt2;
	f[1][0] = calc(r, 0) - calc(l - 1, 0);
	f[1][1] = calc(r, 1) - calc(l - 1, 1);
	f[1][2] = calc(r, 2) - calc(l - 1, 2);
	for (int i = 2; i <= n; i++) {
		f[i][0] = (f[1][0] * f[i - 1][0] + f[1][1] * f[i - 1][2] + f[1][2] * f[i - 1][1]) % MOD;
		f[i][1] = (f[1][0] * f[i - 1][1] + f[1][1] * f[i - 1][0] + f[1][2] * f[i - 1][2]) % MOD;
		f[i][2] = (f[1][0] * f[i - 1][2] + f[1][1] * f[i - 1][1] + f[1][2] * f[i - 1][0]) % MOD;
	}
	cout << f[n][0];
	return 0;
}