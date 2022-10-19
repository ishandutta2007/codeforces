#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int j = 0; j < t; ++j) {
		int n;
		cin >> n;
		if (n % 4 != 0)
			cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			vector<int> a(n);
			for (int i = 0; i < n/2; ++i) {
				a[i] = i * 2 + 1;
				if (i == n / 2 - 1)
					a[i] += n / 2;
			}
			for (int i = n / 2; i < n; ++i) {
				a[i] = (i - n / 2) * 2 + 2;
			}
			for (int i = n-1; i >= 0; --i)
				cout << a[i] << ' ';
			cout << endl;
		}
	}
	return 0;
}