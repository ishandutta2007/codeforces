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
	int N;
	cin >> N;
	vector<int> A(N);
	int res = 0;
	vector<pair<int, int> > vp(N);
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> vp[i].first >> vp[i].second;
		sum += vp[i].first;
	}

	if (sum < 0) {
		for (int i = 0; i < N; i++) {
			vp[i].first = -vp[i].first;
		}
		sum = -sum;
	}

	int INF = (int)1 << 60;
	vector<int> L(62);
	for (int i = 0; i < 62; i++) {
		L[i] = i;
	}
	while (true) {
		int mx = -INF;
		int mxi = 0;
		if ((int)L.size() == 0)break;
		for (int i = 0; i < L.size(); i++) {
			int bit = ((int)1 << L[i]);
			int t = 0;
			for (int j = 0; j < N; j++) {
				if (vp[j].second & bit) {
					t += vp[j].first;
				}
			}
			if (mx < t) {
				mx = t;
				mxi = L[i];
			}
		}
		for (int i = 0; i < L.size(); i++) {
			if (mxi == L[i]) {
				swap(L[i], L.back());
				L.pop_back();
				break;
			}
		}
		{
			int bit = ((int)1 << mxi);
			res ^= bit;
			int sum = 0;
			for (int j = 0; j < N; j++) {
				if (vp[j].second & bit) {
					vp[j].first = -vp[j].first;
				}
				sum += vp[j].first;
			}
			if (sum < 0) {
				//cerr << sum << endl;
				break;
			}
		}
	}

	cout << res << endl;
}