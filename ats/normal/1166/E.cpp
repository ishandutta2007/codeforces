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
	int M, N;
	cin >> M >> N;
	vector<vector<int> > A(M, vector<int>(N, 0));
	for (int i = 0; i < M; i++) {
		int s;
		cin >> s;
		int t;
		for (int j = 0; j < s; j++) {
			cin >> t;
			t--;
			A[i][t] = 1;
		}
	}


	for (int i = 0; i < M; i++) {
		for (int j = 0; j < i; j++) {
			bool ok = false;
			for (int k = 0; k < N; k++) {
				if (A[i][k] & A[j][k]) {
					ok = true;
					break;
				}
			}
			if (!ok) {
				cout << "impossible" << endl;
				return 0;
			}
		}
	}

	cout <<  "possible" << endl;
}