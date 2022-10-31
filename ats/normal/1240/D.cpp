#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int N;
		cin >> N;
		vector<int> A(N);
		int res = 0;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		vector<int> ne(N, -1);
		vector<int> X(N + 1, 0);
		vector<map<int, int> > mp(2);
		X[N - 1] = 1;
		mp[1][A[N - 1]] = N - 1;
		vector<int> cnt(N + 1, 0);
		for (int i = N - 2; i >= 0; i--) {
			int p = -1;
			if (A[i] == A[i + 1]) {
				p = i + 1;
			}
			else {
				auto a = mp[X[i + 1]].find(A[i]);
				if (a != mp[X[i + 1]].end()) {
					p = (*a).second;
				}
			}
			if (p != -1) {
				cnt[i] = cnt[p + 1] + 1;
				ne[i] = p + 1;
				X[i] = X[p + 1];
				mp[X[i]][A[i]] = i;
			}
			else {
				X[i] = mp.size();
				mp.push_back(map<int, int>());
				mp.back()[A[i]] = i;
			}
		}
		res = 0;
		for (int i = 0; i < N; i++) {
			res += cnt[i];
		}
		cout << res << '\n';
	}
        return 0;
}