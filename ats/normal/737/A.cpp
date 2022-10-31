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
	int N, K, S, T;
	cin >> N >> K >> S >> T;
	vector<int> C(N);
	vector<int> V(N);
	int INF = (int)1 << 60;
	int res = INF;
	for (int i = 0; i < N; i++) {
		cin >> C[i] >> V[i];
	}
	vector<int> X(K);
	for (int i = 0; i < K; i++) {
		cin >> X[i];
	}

	sort(X.begin(), X.end());

	int mxX = X[0];
	vector<int> seg;
	seg.push_back(X[0]);
	for (int i = 1; i < K; i++) {
		mxX = max(mxX, X[i] - X[i - 1]);
		seg.push_back(X[i] - X[i - 1]);
	}
	mxX = max(mxX, S - X.back());
	seg.push_back(S - X.back());
	sort(seg.begin(), seg.end());


	vector<int> sum((int)seg.size() + 1, 0);
	for (int i = 0; i < seg.size(); i++) {
		sum[i + 1] = sum[i] + seg[i];
	}

	for (int i = 0; i < N; i++) {
		if (mxX <= V[i]) {

			int idx = upper_bound(seg.begin(), seg.end(), V[i] / 2) - seg.begin();
			int tot = sum[idx];
			//cerr << idx << " " << tot << endl;
			int t = 3 * (S - tot) - (K + 1 - idx) * V[i] + tot;
			//cerr << i << " " << t << endl;
			if (t <= T) {
				res = min(res, C[i]);
			}
		}
	}
	if (res == INF)res = -1;
	cout << res << endl;
}