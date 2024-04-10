#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);

	for (int &x : a)
		cin >> x;
	int curr = 1, res = 1;
	for (int i = 1; i < n; ++i) {
		if (a[i - 1] <= a[i])
			res = max(res, ++curr);
		else
			curr = 1;
	}
	cout << res;
	return 0;
}