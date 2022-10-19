#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int j = 0; j < t; ++j) {
		int n, l, r;
		cin >> n >> l >> r;
		vector<int> ans(r - l + 1);
		int ind = 0;
		int p = 0;
		for (int i = 1; i < n; ++i) {
			p += (n - i) * 2;
			if (p >= l) {
				for (int a = p - (n - i) * 2+1; a <= p; ++a) {
					if (l <= a&&r >= a) {
						if (a % 2 == 1)
							ans[ind] = i;
						else
							ans[ind] = (a - (p - (n - i) * 2))/2 + i;
						ind += 1;
					}
				}
			}
			if (ind == r - l + 1) 
				break;
		}
		if (r == n * (n - 1) + 1)
			ans.back() = 1;
		for (int i = 0; i < r - l + 1; ++i)
			cout << ans[i] << ' ';
		cout << endl;
	}
	return 0;
}