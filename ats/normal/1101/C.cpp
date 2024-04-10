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
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<pair<pair<int, int>, int> > A(N);
		for (int i = 0; i < N; i++) {
			cin >> A[i].first.first >> A[i].first.second;
			A[i].second = i;
		}
		sort(A.begin(), A.end());
		int mxR = 0;
		vector<int> res(N, 2);
		bool ok = false;
		for (int i = 0; i < N; i++) {
			int l = A[i].first.first;
			int r = A[i].first.second;
			if (i > 0 && mxR < l) {
				for (int j = 0; j < i; j++) {
					res[A[j].second] = 1;
				}
				ok = true;
				break;
			}
			mxR = max(mxR, r);
		}
		if (ok) {
			for (int i = 0; i < N; i++) {
				if (i > 0)cout << " ";
				cout << res[i];
			}
			cout << '\n';
		}
		else {
			cout << -1 << '\n';
		}
	}
}