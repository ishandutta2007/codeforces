#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		string A, B;
		cin >> A >> B;
		vector<int> res;
		bool rev = false;
		int a = 0;
		int b = N - 1;
		for (int i = 0; i < N; i++) {
			int len = N - i;
			if (rev) {
				if (A[b] != B[N - i - 1]) {
					res.push_back(1);
				}
				b--;
			} else {
				if (A[a] == B[N - i - 1]) {
					res.push_back(1);
				}
				a++;
			}

			res.push_back(len);
			rev = !rev;
		}
		cout << res.size();
		for (int i = 0; i < res.size(); i++) {
			cout << " " << res[i];
		}
		cout << "\n";
	}
	return 0;
}