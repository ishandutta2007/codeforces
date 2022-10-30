#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
signed main() {
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<vector<int> > A(N);
	for (int i = 0; i < N; i++) {
		A[i].resize(5);
		for (int j = 0; j < 5; j++) {
			cin >> A[i][j];
		}
	}

	vector<int> res;
	if (N >= 33) {
		cout << 0 << endl;
		return 0;
	}
	else {


		for (int i = 0; i < N; i++) {
			bool f = true;
			for (int j = 0; j < N; j++) {
				if (i != j) {
					for (int k = 0; k < N; k++) {
						if (j != k && i != k) {
							int p = 0;
							for (int l = 0; l < 5; l++) {
								p += (A[j][l] - A[i][l])*(A[k][l] - A[i][l]);
							}
							if (p > 0) {
								f = false;
								break;
							}
						}
					}
				}
				if (!f) break;
			}
			if (f) {
				res.push_back(i);
			}
		}
	}

	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		if (i > 0)cout << " ";
		cout << (res[i] + 1);
	}
	cout << endl;
}