#include<bits/stdc++.h>
using namespace std;

#define int long long

main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int ntest;
	cin >> ntest;

	while (ntest--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int &e : a)
			cin >> e;
		sort(a.begin(), a.end());
		for (int i = n - 2; i >= n - k - 1; i--) {
			a[n - 1] += a[i];
		}

		cout << a[n - 1] << '\n';
	}

	return 0;
}