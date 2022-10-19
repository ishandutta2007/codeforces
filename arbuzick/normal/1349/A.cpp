#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	vector<int> k(200001);
	for (int i = 0; i < n; ++i) 
		for (int j = 1; j * j <= a[i]; ++j) 
			if (a[i] % j == 0) {
				if (j * j < a[i]) {
					k[j] += 1;
					k[a[i] / j] += 1;
				}
				else
					k[j] += 1;
			}
	int ans = 1;
	for (int i = 200000; i > 1; --i) {
		if (k[i] >= n - 1) {
			int a = max(ans, i), b = min(ans, i);
			while (b > 0) {
				a = a % b;
				int c = a;
				a = b;
				b = c;
			}
			ans *= i / a;
		}
	}
	cout << ans;
	return 0;
}