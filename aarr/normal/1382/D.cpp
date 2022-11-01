#include <bits/stdc++.h>
using namespace std;

const int N = 4005;

int a[N];
bitset <N> dp;
vector <int> vec;

int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		vec.clear();
		int n;
		cin >> n;
		int lt = 1;
		for (int i = 1; i <= 2 * n; i++) {
			cin >> a[i];
			if (a[i] > a[lt]) {
				vec.push_back(i - lt);
				lt = i;
			}
		}
		vec.push_back(2 * n + 1 - lt);
		dp = 1;
		for (auto x : vec) {
			dp |= (dp << x);
		//	cout << "73 " << x << " " << dp << endl;
		}
		if (dp[n]) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
		vec.clear();
	}
	
	return 0;
}