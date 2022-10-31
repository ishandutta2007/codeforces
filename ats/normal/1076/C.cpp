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
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cout << fixed << setprecision(15);
	for (int i = 0; i < N; i++) {
		if (A[i] * (A[i] - 4) < 0) {
			cout << "N" << endl;
		}
		else {
			cout << "Y ";
			double M = A[i] / 2.0;
			double D = sqrt(A[i] * (A[i] - 4)) / 2;
			cout << M + D << " " << M - D << endl;
		}
	}
	//cout << res << endl;
}