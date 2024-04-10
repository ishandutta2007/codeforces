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
	int N, L;
	cin >> N >> L;
	vector<int> A(N);
	vector<int> B(N, 0);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (A[i] >= A[j]) {
				B[i] = 1;
			}
			if (A[i] * (1 << (j - i)) <= A[j]) {
				B[j] = 1;
			}
		}
	}
	int k;
	for (int i = N - 1; i >= 0; i--) {
		if (B[i] == 0) {
			k = i;
			break;
		}
	}
	res = A[k] * (L / (1 << k));
	if (L % (1 << k) != 0) {
		res += A[k];
	}

	//cerr << res << endl;
	int tmp = 0;
	bool f = true;
	for (int j = 0; j < N + 10; j++) {
		//cerr << L << endl;
		for (int i = N - 1; i >= 0; i--) {
			if (B[i] == 0 && L > (1 << i)) {
				tmp += A[i] * (L / (1 << i));
				L = L % (1 << i);
				res = min(res, tmp + A[i]);
				break;
			}
			if (L <= (1 << i)) {
				res = min(res, tmp + A[i]);
			}
		}
	}

	//cerr << res << endl;
	if (L == 0) {
		res = min(res, tmp);
	}
	cout << res << endl;
}