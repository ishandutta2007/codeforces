#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;
int cnt[26][26];
int C[26];
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string S;
	cin >> S;
	int N = S.size();
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		A[i] = S[i] - 'a';
	}
	int res = 0;
	for (int a = 0; a < 26; a++) {
		for (int b = 0; b < 26; b++) {
			int ans = 0;
			int tmp = 0;
			for (int i = 0; i < N; i++) {
				if (A[i] == b) {
					ans += tmp;
				}
				if (A[i] == a) {
					tmp++;
				}
			}
			res = max(res, ans);
			res = max(res, tmp);
		}
	}

	cout << res << endl;
}