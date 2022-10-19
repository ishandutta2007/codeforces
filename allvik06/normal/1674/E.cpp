#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
#define int long long
const int INF = 1e15;

signed main(){
	int t = 1;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n);
		for (int& i : a) cin >> i;
		int ans = INF, minn = INF;
		for (int i = 0; i < n; ++i) {
			if (i) {
				ans = min(ans, minn + (a[i] + 1) / 2);
				ans = min(ans, max({(a[i] + a[i - 1] + 2) / 3, (a[i] + 1) / 2, (a[i - 1] + 1) / 2}));
				if (i < n - 1) ans = min(ans, (a[i - 1] + a[i + 1] + 1) / 2);
			}
			minn = min(minn, (a[i] + 1) / 2);
		}
		cout << ans << "\n";
	}
}