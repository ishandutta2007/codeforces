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
	string s;
	cin >> s;
	int a;
	a = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(')
			a += 1;
		else
			a -= 1;
	}
	if (a != 0)
		cout << -1;
	else {
		vector<int> v(n+1);
		v[0] = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '(')
				v[i + 1] = v[i] + 1;
			else
				v[i + 1] = v[i] - 1;
		}
		int l;
		l = -1;
		int ans;
		ans = 0;
		for (int i = 0; i < n; ++i) {
			if (v[i] == 0 && v[i + 1] < 0)
				if (l == -1)
					l = i;
			if (v[i] == 0 && v[i + 1] > 0)
				if (l != -1) {
					ans = ans + (i - l);
					l = -1;
			}
		}
		if (l != -1)
			ans = ans + (n - l);
		cout << ans;
	}
	return 0;
}