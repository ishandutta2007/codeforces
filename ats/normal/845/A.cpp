#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(2 * n);
	
	for (int i = 0; i < 2*n; i++) {
		cin >> a[i];
		
	}
	sort(a.begin(), a.end());

	if (a[n-1]<a[n]) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}