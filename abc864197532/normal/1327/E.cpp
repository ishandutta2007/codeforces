#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;

int main () {
	int n;
	cin >> n;
	vector <long long> anss;
	long long ans = 0, pre = 0, now = 1;
	for (int i = 1; i <= n; ++i) {
		long long tmp = now * i * 10 % mod;
		ans = tmp - pre - ((i - 1) * now) % mod;
		now = (now * 10) % mod;
		while (ans < 0) ans += mod;
		anss.push_back(ans);
		pre = (pre + ans) % mod;
	}
	for (int i = n - 1; i >= 0; --i) cout << anss[i] << " \n"[i == 0];
}