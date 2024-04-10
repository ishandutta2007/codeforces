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
		map<int, int> mpL;
		map<int, int> mpR;

		for (int i = 0; i < N; i++) {
			mpR[A[i]] = i;
		}
		for (int i = N - 1; i >= 0; i--) {
			mpL[A[i]] = i;
		}
		int mx = 0;
		int INF = (int)1 << 60;
		int lR = -INF;
		int cnt = 0;
		for (auto x : mpL) {
			if (x.second > lR) {
				cnt++;
				mx = max(mx, cnt);
			}
			else {
				cnt = 1;
			}
			lR = mpR[x.first];
		}

		cout << (mpL.size() - mx) << '\n';
	}
	return 0;
}