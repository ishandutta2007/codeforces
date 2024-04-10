#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int &x : a)
		cin >> x;

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int res = 0;
		for (int j = 0; j < n; ++j)
			if ((j - i) % k)
				res += a[j];
		ans = max(ans, abs(res));
	}
	cout << ans;
	return 0;
}