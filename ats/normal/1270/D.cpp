#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
	int N, K;
	cin >> N >> K;
	map<int, int> mp;
	for (int i = 0; i < K + 1; i++) {
		vector<int> X;
		for (int j = 0; j < K + 1; j++) {
			if (i != j) {
				X.push_back(j);
			}
		}
		cout << "?";
		for (int j : X) {
			cout << " " << j + 1;
		}
		cout << "\n";
		cout << flush;
		int pos, val;
		cin >> pos >> val;
		mp[val]++;
	}
	cout << "! " << K + 1 - (*mp.begin()).second << "\n";
	cout << flush;
	return 0;
}