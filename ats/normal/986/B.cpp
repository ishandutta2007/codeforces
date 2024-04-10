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
	vector<int> B(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		A[i]--;
		B[A[i]] = i;
	}

	int c = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] != i) {
			int p = B[i];
			swap(A[i], A[p]);
			swap(B[A[i]], B[A[p]]);
			c ^= 1;
		}
	}

	/*for (int i = 0; i < N; i++) {
		cerr << A[i] << " ";
	}
	cerr << endl;
	for (int i = 0; i < N; i++) {
		cerr << B[i] << " ";
	}
	cerr << endl;*/

	if (((3 * N) % 2) == c) {
		cout << "Petr" << endl;
	}
	else {
		cout << "Um_nik" << endl;
	}
}