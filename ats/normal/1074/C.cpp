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
inline int dist(pair<int, int> &a, pair<int, int> &b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<pair<int, int> > A(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i].first >> A[i].second;
	}
	int mnx = A[0].first;
	int mxx = A[0].first;
	int mny = A[0].second;
	int mxy = A[0].second;
	for (int i = 0; i < N; i++) {
		mnx = min(mnx, A[i].first);
		mxx = max(mxx, A[i].first);
		mny = min(mny, A[i].second);
		mxy = max(mxy, A[i].second);
	}
	res = 2 * ((mxx - mnx) + (mxy - mny));
	set <pair<int, int> > st;

	int val;
	for (int x = -1; x <= 1; x++) {
		for (int y = -1; y <= 1; y++) {
			if (x != 0 || y != 0) {
				vector<int> v;
				int mx = (int)(-1e9);
				for (int i = 0; i < N; i++) {
					val = A[i].first * x + A[i].second * y;
					if (mx <= val) {
						if (mx < val) {
							mx = val;
							v.clear();
						}
						v.push_back(i);
					}
				}
				for (auto p : v) {
					st.insert(A[p]);
				}
			}
		}
	}
	//cerr << res << endl;
	vector<pair<int, int> > X;
	for (auto s : st)X.push_back(s);
	int M = X.size();
	vector<pair<int, int> > z;
	int res3 = 0;
	for (int i = 0; i < (1 << M); i++) {
		z.clear();
		for (int j = 0; j < M; j++) {
			if (i & (1 << j)) {
				z.push_back(X[j]);
			}
		}
		if ((int)z.size() == 2) {
			res3 = max(res3, 2 * dist(z[0], z[1]));
		}
		else if ((int)z.size() == 3) {
			res3 = max(res3, dist(z[0], z[1]) + dist(z[1], z[2]) + dist(z[2], z[0]));
		}
	}
	cout << res3;
	for (int i = 4; i <= N; i++) {
		cout << " " << res;
	}
	cout << endl;
}