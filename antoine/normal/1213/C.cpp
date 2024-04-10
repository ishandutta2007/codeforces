#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		ll n, m, ans = 0;
		cin >> n >> m;
		n = n / m + 1;
		for(int i = 0; i < 10; ++i)
			ans += i*m % 10;
		ans *= n/10;
		for(int i = 0; i < n%10; ++i)
			ans += i * m % 10;
		cout << ans << '\n';

	}
	return 0;
}