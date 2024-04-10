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
	map<int, int> mpX;
	map<int, int> mpY;
	map<pair<int, int>, int> mpXY;
	int res = 0;
	int X , Y;
	for (int i = 0; i < N; i++) {
		cin >> X >> Y;
		mpX[X]++;
		mpY[Y]++;
		mpXY[make_pair(X, Y)]++;
	}
	for (auto &x : mpX) {
		res += (x.second * (x.second - 1)) / 2;
	}
	for (auto &x : mpY) {
		res += (x.second * (x.second - 1)) / 2;
	}
	for (auto &x : mpXY) {
		res -= (x.second * (x.second - 1)) / 2;
	}


	cout << res << endl;
}