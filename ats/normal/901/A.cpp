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
	vector<int> A(N + 1);
	vector<int> B(N + 1, -1);
	vector<int> C(N + 1, -1);
	int res = 0;
	int M = 0;
	for (int i = 0; i < N + 1; i++) {
		cin >> A[i];
		if (A[i] == 1) {
			B[i] = M;
		}
		else {
			B[i] = M;
			C[i] = M + 1;
		}
		M += A[i];
	}
	bool f = false;
	for (int i = 0; i < N; i++) {
		if (A[i] != 1 && A[i + 1] != 1) {
			f = true;
		}
		
	}
	if (f) {
		cout << "ambiguous" << endl;
		cout << 0;
		for (int i = 1; i < N + 1; i++) {
			for (int j = 0; j < A[i]; j++) {
				cout << " " << B[i - 1] + 1;
			}
		}
		cout << endl;
		cout << 0;
		for (int i = 1; i < N + 1; i++) {
			for (int j = 0; j < A[i]; j++) {
				if (j == 0 || A[i - 1] == 1) {
					cout << " " << B[i - 1] + 1;
				}
				else {
					cout << " " << C[i - 1] + 1;
				}
			}
		}
		cout << endl;
	}
	else {
		cout << "perfect" << endl;
	}

	//cout << res << endl;
}