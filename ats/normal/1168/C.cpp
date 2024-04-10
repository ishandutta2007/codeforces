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
	int N, Q;
	cin >> N >> Q;
	vector<int> A(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	vector<vector<int> > R(N, vector<int>(20, N));
	vector<vector<int> > X(20, vector<int>(20, N));
	for (int i = N - 1; i >= 0; i--) {
		vector<int> T;
		for (int j = 0; j < 20; j++) {
			if (A[i] & (1 << j)) {
				T.push_back(j);
			}
		}
		for (const int &j : T) {
			for (int k = 0; k < 20; k++) {
				R[i][k] = min(R[i][k], X[j][k]);
			}
		}
		for (const int &j : T) {
			R[i][j] = i;
		}
		for (const int &j : T) {
			for (int k = 0; k < 20; k++) {
				X[j][k] = R[i][k];
			}
		}

	}
	for (int i = 0; i < Q; i++) {
		int a, b;
		cin >> a >> b; a--; b--;
		bool ok = false;
		for (int j = 0; j < 20; j++) {
			if (A[b] & (1 << j)) {
				if (R[a][j] <= b) {
					ok = true;
				}
			}
		}
		if (ok) {
			cout << "Shi" << '\n';
		}
		else {
			cout << "Fou" << '\n';
		}
	}
	return 0;
}