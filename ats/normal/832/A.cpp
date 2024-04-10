#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n,k;
	cin >> n >> k;
	if ((n % (2 * k)) < k) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
	}
	
	return 0;
	
}