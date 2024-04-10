#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> p(n);
	int pr;
	pr = -1;
	int ans1, ans2;
	ans2 = 1;
	int mod;
	mod = 998244353;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		if (p[i] > n - k) {
			if (pr == -1)
				pr = i;
			else {
				ans2 = ans2 * (i - pr) % mod;
				pr = i;
			}
		}
	}
	ans1 = (n + n - k + 1) * k / 2;
	cout << ans1 << ' ' << ans2;
}