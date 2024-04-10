#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> l(m);
	for (int i = 0; i < m; ++i)
		cin >> l[i];
	for(int i = 0; i < m; ++i)
		if (l[i] > n - i) {
			cout << -1;
			return 0;
		}
	vector<int> s(m+1);
	s[m] = 0;
	for (int i = m - 1; i >= 0; --i)
		s[i] = s[i + 1] + l[i];
	if (s[0] < n) {
		cout << -1 << endl;
		return 0;
	}
	vector<int> ans(m);
	int a = n - m;
	for (int i = 0; i < m; ++i) {
		ans[i] = n - i - l[i] + 1;
		if (s[i + 1] < ans[i]-1) {
			ans[i] = s[i + 1] + 1;
			for (int j = i + 1; j < m; ++j)
				ans[j] = ans[j - 1] - l[j];
			break;
		}
	}
	for (int i = 0; i < m; ++i)
		cout << ans[i] << ' ';
	return 0;
}