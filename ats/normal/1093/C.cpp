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
	vector<int> B(N / 2);
	int res = 0;
	for (int i = 0; i < N / 2; i++) {
		cin >> B[i];
	}

	vector<int> A(N);
	A[0] = 0;
	A.back() = B[0];
	for (int i = 1; i < N / 2; i++) {
		A[i] = A[i - 1];
		A[N - i - 1] = B[i] - A[i];
		if (A[N - i - 1] > A[N - i - 1 + 1]) {
			A[N - i - 1] = A[N - i - 1 + 1];
			A[i] = B[i] - A[N - i - 1];
		}
	}
	for (int i = 0; i < N; i++) {
		if (i > 0)cout << " ";
		cout << A[i];
	}
	cout << endl;
}