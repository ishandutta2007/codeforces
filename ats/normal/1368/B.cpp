#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> X(10, 1);
	int p = 1;
	int x = 0;
	while (true) {
		if (p >= N) break;
		p /= X[x];
		X[x]++;
		p *= X[x];
		x++;
		if (x == 10) x = 0;
	}
	string S = "codeforces";
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < X[i]; j++) {
			cout << S[i];
		}
	}
	cout << endl;
}