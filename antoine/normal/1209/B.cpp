#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

void f() {
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	string s;
	cin >> n >> s;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i] >> b[i];

	int ans = 0;
	for (int t = 1; t < (int) 1e5; ++t) {

		ans = max(ans, count(s.begin(), s.end(), '1'));
		for (int i = 0; i < n; ++i)
			if (t >= b[i] && (t - b[i]) % a[i] == 0)
				s[i] = s[i] == '0' ? '1' : '0';
	}
	cout << ans;
	return 0;
}