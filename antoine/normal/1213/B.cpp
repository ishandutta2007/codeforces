#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int n, a[2];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {

		int n;
		cin >> n;
		vector<int> a(n);
		for (int &x : a)
			cin >> x;
		int mn = (int) 1e9, ans = n;
		for (int i = n - 1; i >= 0; --i)
			if (a[i] <= mn) {
				mn = a[i];
				ans--;
			}

		cout << ans << '\n';
	}
	return 0;
}