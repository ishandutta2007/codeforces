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
	int D, N, M;
	cin >> D >> N >> M;
	vector<pair<int, int> > A(M);
	int res = 0;
	for (int i = 0; i < M; i++) {
		cin >> A[i].first >> A[i].second;
	}
	sort(A.begin(), A.end());

	vector < pair<int, int> > vp;
	vp.emplace_back(0, 0);
	vp.emplace_back(N, 1e7);
	int cur = 0;
	int sum = 0;
	for (int i = 0; i <= M; i++) {
		int pos;
		if (i == M) {
			pos = D;
		}
		else {
			pos = A[i].first;
		}

		while (cur < (int)vp.size() - 1) {
			if (vp[cur + 1].first >= pos)break;
			sum += (vp[cur + 1].first - vp[cur].first) * vp[cur].second;
			cur++;
		}
		if (cur == (int)vp.size() - 1) {
			cout << -1 << endl;
			return 0;
		}
		if (i < M) {
			int la = 0;
			while ((int)vp.size() > cur && vp.back().second > A[i].second) {
				la = vp.back().first;
				if (vp.size() - 1 == cur) {
					la = A[i].first;
					break;
				}
				vp.pop_back();
			}
			vp.emplace_back(la, A[i].second);
			vp.emplace_back(A[i].first + N, 1e7);
		}
		/*cerr << cur << endl;
		for (int j = 0; j < vp.size(); j++) {
			cerr << vp[j].first << " ";
		}
		cerr << endl;
		for (int j = 0; j < vp.size(); j++) {
			cerr << vp[j].second << " ";
		}
		cerr << endl;*/


	}

	res = sum + (D - vp[cur].first) * vp[cur].second;

	cout << res << endl;
}