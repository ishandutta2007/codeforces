#include<bits/stdc++.h>
using namespace std;

int a[100], n;


int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n), b(n), c(n);
		for (int &e : a) 
			cin >> e;
		for (int &e : b) 
			cin >> e;
		for (int &e : c) 
			cin >> e;
		int cur = 0;

		vector<int> p(n);

		for (int i = 0; i < n; i++) {
			if (a[i] != cur) cur = a[i];
			else if (b[i] != cur) cur = b[i];
			else if (c[i] != cur) cur = c[i];
			p[i] = cur;
		}
		if (a[0] != p[1] && a[0] != p[n - 1]) p[0] = a[0];
		if (b[0] != p[1] && b[0] != p[n - 1]) p[0] = b[0];
		if (c[0] != p[1] && c[0] != p[n - 1]) p[0] = c[0];
		for (int e : p) 
			cout << e << ' ';
		cout << '\n';
	}

	return 0;
}