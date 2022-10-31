#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int n;
	cin >> n;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a & (int)1 == (int)1) {
			cout << "First" << endl;
			return 0;
		}
	}

	cout << "Second" << endl;
	return 0;
}