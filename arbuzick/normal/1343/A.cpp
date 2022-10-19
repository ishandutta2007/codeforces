#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int j = 0; j < t; ++j) {
		int n;
		cin >> n;
		for (int i = 2; i < 60; ++i) {
			if (n % ((1 << i)-1) == 0) {
				cout << n/((1 << i)-1) << endl;
				break;
			}
		}
	}
	return 0;
}