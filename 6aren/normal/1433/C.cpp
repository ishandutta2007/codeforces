#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int ntest;
	cin >> ntest;

	while (ntest--) {
		int n;
		cin >> n;
		vector<int> a(n + 2);
		a[0] = a[n + 1] = 1e9;

		for (int i = 1; i <= n; i++)
			cin >> a[i];
		int id = -1;
		int mx = 0;
		for (int i = 1; i <= n; i++)
			mx = max(mx, a[i]);
		for (int i = 1; i <= n; i++) {
			if (a[i] == mx && (a[i] > a[i - 1] || a[i] > a[i + 1]))
				id = i;
		}

		cout << id << '\n';

	}

	return 0;
}