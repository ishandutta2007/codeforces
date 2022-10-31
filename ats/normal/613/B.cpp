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
	int N, MX, C, D, M;
	cin >> N >> MX >> C >> D >> M;
	vector<int> A(N);
	vector<pair<int,int> > T(N);
	int res = -1;
	int ri = -1;
	int rp = -1;
	for (int i = 0; i < N; i++) {
		cin >> T[i].first;
		T[i].second = i;
	}
	sort(T.begin(), T.end());
	for (int i = 0; i < N; i++)A[i] = T[i].first;
	vector<int> sum(N + 1);
	sum[0] = 0;
	for (int i = 0; i < N; i++) {
		sum[i + 1] = sum[i] + A[i];
	}
	for (int i = 0; i < N; i++) {
		int ng = MX + 1;
		int ok = 0;

		while (ng - ok > 1) {
			int m = (ng + ok) / 2;

			int pos = lower_bound(A.begin(), A.begin() + (N - i), m) - A.begin();

			if (pos * m - sum[pos] <= M) {
				ok = m;
			}
			else {
				ng = m;
			}
		}
		//cerr << i << " " << ok << endl;
		int score = i * C + ok * D;
		if (res < score) {
			res = score;
			ri = i;
			rp = ok;
		}

		M -= MX - A[N - 1 - i];
		if (M < 0)break;
	}
	if (M >= 0) {
		res = N * C + MX * D;
		ri = N;
		rp = MX;
	}
	cout << res << endl;

	for (int i = 0; i < ri; i++) {
		T[N - 1 - i].first = MX;
	}
	for (int i = 0; i < N; i++) {
		T[i].first = max(T[i].first, rp);
	}

	for (int i = 0; i < N; i++) A[T[i].second] = T[i].first;

	for (int i = 0; i < N; i++) {
		if (i > 0)cout << " ";
		cout << A[i];
	}
	cout << endl;

}