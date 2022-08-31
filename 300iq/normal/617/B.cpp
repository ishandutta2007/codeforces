
#include <bits/stdc++.h>
#define int long long
using namespace std;

main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int a[n];
	int j = n + 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i]) {
			j = min(j, i);
		}
	}
	int x = 0;
	vector <int> p;
	for (int i = j + 1; i < n; i++) {
		if (a[i] == 0) {
			x++;
		} 
		else {
			p.push_back(x);
			x = 0;
		}
	}
	int ans = 1;
	for (int i = 0; i < p.size(); i++) 
		ans *= (p[i] + 1);
	cout << (j == n + 1 ? 0 : ans) << endl;
}