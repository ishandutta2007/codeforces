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
	vector<pair<int, int> > A(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i].first;
		A[i].second = i;
	}

	sort(A.rbegin(), A.rend());
	vector<vector<int> > X(2 * N + 1);
	vector<int> T(2 * N, -1);
	int mx = A[0].first;
	int b = mx + 1;
	for (int ii = 0; ii < mx; ii++) {
		int i = A[ii].second;
		int r = A[ii].first;
		//cerr << "A " << i << " " << r << endl;
		T[ii] = 2 * i;
		//cerr << ii << " " << 2 * i << endl;
		if (ii + r >= mx && T[ii + r] == -1) {
			T[ii + r] = 2 * i + 1;
			b = max(b, ii + r + 1);
		}
		else {
			X[ii + r - 1].push_back(2 * i + 1);
		}
	}
	/*for (int i = 0; i < b; i++) {
		cerr << T[i] << " ";
	}
	cerr << endl;*/
	//cerr << "b = " << b << endl;
	for (int ii = mx; ii < N; ii++) {
		int i = A[ii].second;
		int r = A[ii].first;
		//cerr << "B " << i << " " << r << endl;
		if (r == 1) {
			T[b] = 2 * i;
			T[b + 1] = 2 * i + 1;
			b += 2;
		}
		else {
			X[0].push_back(2 * i);
			X[r - 2].push_back(2 * i + 1);
		}
	}

	for (int i = 0; i < b - 1; i++) {
		cout << T[i] + 1 << " " << T[i + 1] + 1 << endl;
	}

	for (int i = 0; i < b; i++) {
		for (int j = 0; j < X[i].size(); j++) {
			cout << T[i] + 1 << " " << X[i][j] + 1 << endl;
		}
	}


}