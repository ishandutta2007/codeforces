#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string S;
	cin >> S;
	int N = S.size();
	int Q;
	cin >> Q;
	//cerr << Q<<endl;
	vector<vector<int> > X(26, vector<int>(N + 1, 0));
	for (int i = 0; i < N; i++) {
		X[S[i] - 'a'][i + 1] = 1;
	}
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < N; j++) {
			X[i][j + 1] += X[i][j];
		}
	}
	for (int i = 0; i < Q; i++) {
		int L, R;
		cin >> L >> R;
		L--;
		if (R - L == 1 || S[L] != S[R - 1]) {
			cout << "Yes\n";
		} else {
			int cnt = 0;
			for (int j = 0; j < 26; j++) {
				if (X[j][R] - X[j][L] > 0) cnt++;
			}
			if (cnt >= 3) {
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		}
	}
	return 0;
}