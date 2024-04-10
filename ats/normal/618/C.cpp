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
	vector<pair<pair<int, int>, int> > A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i].first.first >> A[i].first.second;
		A[i].second = i;
	}

	sort(A.begin(), A.end());
	vector<pair<int, int> >res;
	for (int i = 0; i < N; i++) {
		if ((int)res.size() < 2) {
			res.emplace_back(i, A[i].second);
		}
		else {
			int x1 = A[res[0].first].first.first;
			int y1 = A[res[0].first].first.second;
			int x2 = A[res[1].first].first.first;
			int y2 = A[res[1].first].first.second;
			int x3 = A[i].first.first;
			int y3 = A[i].first.second;
			if ((y2 - y1) * (x3 - x1) == (y3 - y1) * (x2 - x1)) {
				res[0] = res[1];
				res[1] = pair<int, int>(i, A[i].second);
			}
			else {
				res.emplace_back(i, A[i].second);
				break;
			}
		}

	}


	cout << res[0].second + 1 << " " << res[1].second + 1 << " " << res[2].second + 1 << endl;
}