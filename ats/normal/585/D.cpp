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
void ma(int &a, const int &b) {
	a = max(a, b);
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<vector<int> > A(N, vector<int>(3));
	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> A[i][j];
		}
	}
	int K = N / 2;
	int p3[20];
	p3[0] = 1;
	for (int i = 1; i < 20; i++) {
		p3[i] = p3[i - 1] * 3;
	}
	int d;
	int X[3];
	map<pair<int, int>, int> mp;
	int m[3][2] = { {0,1},{0,2},{1,2} };
	pair<int, int> p;
	for (int i = 0; i < p3[K]; i++) {
		int t = i;
		X[0] = X[1] = X[2] = 0;
		for (int j = 0; j < K; j++) {
			d = t % 3;
			X[m[d][0]] += A[j][m[d][0]];
			X[m[d][1]] += A[j][m[d][1]];
			t /= 3;
		}
		p = make_pair(X[1] - X[0], X[2] - X[0]);
		if (mp.count(p) == 1) {
			ma(mp[p], X[0]);
		}
		else {
			mp[p] = X[0];
		}
	}
	int K2 = N - K;
	int res1[3];
	int res2[3];
	int INF = (int)1 << 60;
	int mx = -INF;
	for (int i = 0; i < p3[K2]; i++) {
		int t = i;
		X[0] = X[1] = X[2] = 0;
		for (int j = 0; j < K2; j++) {
			d = t % 3;
			X[m[d][0]] += A[j + K][m[d][0]];
			X[m[d][1]] += A[j + K ][m[d][1]];
			t /= 3;
		}
		p = make_pair(-(X[1] - X[0]), -(X[2] - X[0]));
		auto mm = mp.find(p);
		if (mm != mp.end()) {
			if ((*mm).second + X[0] > mx) {
				mx = (*mm).second + X[0];
				res1[0] = (*mm).second;
				res1[1] = (*mm).second + p.first;
				res1[2] = (*mm).second + p.second;
				res2[0] = X[0];
				res2[1] = X[1];
				res2[2] = X[2];
			}
		}
	}
	if (mx == -INF) {
		cout << "Impossible" << endl;
		return 0;
	}
	int i1 = 0;
	for (int i = 0; i < p3[K]; i++) {
		int t = i;
		X[0] = X[1] = X[2] = 0;
		for (int j = 0; j < K; j++) {
			d = t % 3;
			X[m[d][0]] += A[j][m[d][0]];
			X[m[d][1]] += A[j][m[d][1]];
			t /= 3;
		}
		if (X[0] == res1[0] && X[1] == res1[1] && X[2] == res1[2]) {
			i1 = i;
			break;
		}
	}
	int i2 = 0;
	for (int i = 0; i < p3[K2]; i++) {
		int t = i;
		X[0] = X[1] = X[2] = 0;
		for (int j = 0; j < K2; j++) {
			d = t % 3;
			X[m[d][0]] += A[j + K][m[d][0]];
			X[m[d][1]] += A[j + K][m[d][1]];
			t /= 3;
		}
		if (X[0] == res2[0] && X[1] == res2[1] && X[2] == res2[2]) {
			i2 = i;
			break;
		}
	}
	//cerr << mx << endl;
	string R = "LMW";
	for (int j = 0; j < K; j++) {
		d = i1 % 3;
		//cerr << d << endl;
		cout << R[m[d][0]] << R[m[d][1]] << endl;
		i1 /= 3;
	}
	for (int j = 0; j < K2; j++) {
		d = i2 % 3;
		//cerr << d << endl;
		cout << R[m[d][0]] << R[m[d][1]] << endl;
		i2 /= 3;
	}


}