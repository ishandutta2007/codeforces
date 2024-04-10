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
	int N, X;
	cin >> N >> X;
	vector<int> A(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		A[i]--;
	}
	vector<int> R(X, -1);
	vector<int> L(X, N);
	vector<int> Lmin(X, N);
	vector<int> Rmax(X, N);
	for (int i = 0; i < N; i++) {
		R[A[i]] = i;
		if (L[A[i]] == N) {
			L[A[i]] = i;
		}
	}

	Lmin.back() = N;
	for (int i = X - 2; i >= 0; i--) {
		if (i < X - 2 && R[i + 1] > Lmin[i + 1]) {
			Lmin[i] = -5;
		}
		else {
			Lmin[i] = min(Lmin[i + 1], L[i + 1]);
		}
	}

	/*for (int i = 0; i < Lmin.size(); i++) {
		cerr << Lmin[i] << " ";
	}
	cerr << endl;*/
	Rmax[0] = -1;
	for (int i = 1; i < X; i++) {
		if (i > 1 && Rmax[i - 1] > L[i - 1]) {
			Rmax[i] = N + 4;
		}
		else {
			Rmax[i] = max(Rmax[i - 1], R[i - 1]);
		}
	}



	int r = 0;
	for (int i = 0; i < X; i++) {
		while (r < X && Rmax[i] > Lmin[r])r++;
		r = max(i, r);
		//cerr << i + 1 << " " << r + 1 << endl;
		res += X - r;


	}


	cout << res << endl;
}