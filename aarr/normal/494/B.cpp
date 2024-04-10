#include <iostream>
using namespace std;

const int N = 100 * 1000 + 5, mod = 1000 * 1000 * 1000 + 7, C = 29;


string s, t;
bool mark[N];
long long dp[N];
long long ps[N];
long long ps2[N];
int main() {
	cin >> s >> t;
	if (t.size() > s.size()) {
		cout << 0;
		return 0;
	}
	long long p = 1, x = 0, y = 0;
	for (int i = 0; i < t.size(); i++) {
		p *= C;
		p %= mod;
		x *= C;
		x += t[i] - 'a' + 1;
		x %= mod;
		y *= C;
		y += s[i] - 'a' + 1;
		y %= mod;
	}
//	cout << "48 " << p << " " << x << " " << y << endl;
	if (x == y) {
		mark[t.size()] = true;
	}
	for (int i = 0; i < s.size() - t.size(); i++) {
		y *= C;
		y -= 1ll * p * (s[i] - 'a' + 1);
		y += 1ll * mod * C;
		y %= mod;
		y += (s[i + t.size()] - 'a' + 1);
		y %= mod;
	//	cout << "38 " << i << " " << y << endl;
		if (x == y) {
			mark[i + 1 + t.size()] = true;
		}
	}
	dp[0] = 1;
	ps[0] = 1;
	ps2[0] = 1;
	int lt = -1, ans = 0;
	for (int i = 1; i <= s.size(); i++) {
		if (mark[i]) {
			lt = i;
		}
	//	if (lt != -1) {
	//		dp[i] = dp[i - 1];
	//	}
		if (lt != -1) {
			dp[i] += ps2[lt - t.size()];
			ans += dp[lt - s.size()];
			ans %= mod;
			dp[i] %= mod;
		}
		ps[i] = ps[i - 1] + dp[i];
		ps[i] %= mod;
		ps2[i] = ps2[i - 1] + ps[i];
		ps2[i] %= mod;
	//	cout << "73 " << mark[i] << " " << dp[i] << " " << ps[i] << " " << ps2[i] << endl;
	}
	
	cout << (ps[s.size()] - 1 + mod) % mod << endl;
	return 0;
}