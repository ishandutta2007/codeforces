#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int mod = 998244353;
	vector<int> st(n+1);
	st[0] = 1;
	for (int i = 0; i < n; ++i)
		st[i + 1] = st[i] * 10 % mod;
	for (int i = 0; i < n; ++i) {
		int ans;
		if (n - i > 2) {
			ans = (n - i - 2) * 10 * 81 * st[n - i - 3] % mod;
			ans = (ans+10*2*9*st[n - i - 2] % mod)%mod;
			cout << ans << ' ';
		}if (n - i == 2) {
			ans = 2 * 9 *10 % mod;
			cout << ans << ' ';
		}if (n - i == 1) {
			ans = 10;
			cout << ans << ' ';
		}
	}
}