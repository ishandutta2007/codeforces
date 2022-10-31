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
//int MOD = 1000000007;

signed main() {
	int N, M, C;
	cin >> N >> M >> C;
	vector<int> A(N, -1);
	int c;
	bool f;
	for (int i = 0; i < M; i++) {
		cin >> c;
		f = false;
		if (c * 2 > C) {
			for (int j = N - 1; j >= 0; j--) {
				if (A[j] == -1 || A[j] < c) {
					A[j] = c;
					cout << j + 1 << endl << flush;
					f = true;
					break;
				}
			}
			if (!f) {
				cout << 1 << endl << flush;
			}
		}
		else {
			for (int j = 0; j < N; j++) {
				if (A[j] == -1 || A[j] > c) {
					A[j] = c;
					cout << j + 1 << endl << flush;
					f = true;
					break;
				}
			}
			if (!f) {
				cout << N << endl << flush;
			}
		}
		f = true;
		for (int i = 0; i < N; i++) {
			if (A[i] == -1) {
				f = false; 
				break;
			}
			if (i > 0) {
				if (A[i - 1] > A[i]) {
					f = false;
					break;
				}
			}
		}
		if (f)break;
	}
}