#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;
int B = 150;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string S;
	cin >> S;
	int N = S.size();
	int res = 0;
	// for (int x = 0; x < B; x++) {
	// 	unordered_map<int, int> mp;
	// 	int c = 0;
	// 	mp[c]++;
	// 	for (int i = 0; i < N; i++) {
	// 		if (S[i] == '1') {
	// 			c += x;
	// 		} else {
	// 			c -= 1;
	// 		}
	// 		res += (mp[c]++);
	// 	}
	// }
	for (int x = 0; x < B; x++) {
		int c = 0;
		vector<int> X(N + 1);
		X[N] = 0;
		for (int i = 0; i < N; i++) {
			if (S[i] == '1') {
				c += x;
			} else {
				c -= 1;
			}
			X[i] = c;
			//res += (mp[c]++);
		}
		sort(X.begin(), X.end());
		int cur = 1;
		for (int j = 1; j <= N + 1; j++) {
			if (j < N + 1 && X[j] == X[j - 1]) {
				cur++;
			} else {
				res += cur * (cur - 1) / 2;
				cur = 1;
			}
		}
	}
	//return 0;
	vector<int> ne(N + 1);
	ne[N] = N;
	for (int i = N - 1; i >= 0; i--) {
		if (S[i] == '1') {
			ne[i] = i;
		} else {
			ne[i] = ne[i + 1];
		}
	}
	for (int i = 0; i < N; i++) {
		int cur = 1;
		int pos = ne[i];
		while (true) {
			if (pos == N) break;
			if (i + cur * B > N) break;
			int npos = ne[pos + 1];
			int mn = max(B + 1, (pos - i + cur) / cur);
			int mx = (npos - i) / cur;
			res += max((int)0, mx - mn + 1);
			//cerr << i << " " << cur << " " << mn << " " << mx << endl;
			cur++;
			pos = ne[pos + 1];
		}
	}
	cout << res << endl;
}