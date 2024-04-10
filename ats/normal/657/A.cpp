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
	int N, D, H;
	cin >> N >> D >> H;

	if (N <= D) {
		cout << -1 << endl;
		return 0;
	}
	if (H > D) {
		cout << -1 << endl;
		return 0;
	}
	if (2 * H < D) {
		cout << -1 << endl;
		return 0;
	}
	if (D == 1) {
		if (N >= 3) {
			cout << -1 << endl;
			return 0;
		}
	}

	vector<int> X;
	X.push_back(0);
	int cur = 1;
	for (int i = 0; i < H; i++) {
		X.push_back(cur);
		cur++;
	}
	reverse(X.begin(), X.end());

	for (int i = 0; i < D - H; i++) {
		X.push_back(cur);
		cur++;
	}
	vector<pair<int, int> > res;

	int t = X[X.size() / 2];

	for (int i = 1; i < X.size(); i++) {
		res.emplace_back(X[i - 1], X[i]);
	}

	for (int i = cur; i < N; i++) {
		res.emplace_back(i, t);
	}


	for (int i = 0; i < res.size(); i++) {
		cout << res[i].first + 1 << " " << res[i].second + 1 << endl;
	}
}