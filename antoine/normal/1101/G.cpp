#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = 1; i < n; ++i)
		a[i] ^= a[i - 1];

	if (!a.back()) {
		cout << -1;
		return 0;
	}

	vector<int> res = { a.back() };
	for (int i = 0; i < n - 1; ++i) {
		// sort(res.begin(), res.end());
		int x = a[i];
		for (const int &y : res)
			x = min(x, x ^ y);
		if (x)
			res.push_back(x);
	}

	cout << res.size();

	return 0;
}