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
	for (int i = 0; i < N; i++) {
		if (A[i] != A[0]) {
			res = max(res, i);
		}
	}
	for (int i = 0; i < N; i++) {
		if (A[i] != A[N  - 1]) {
			res = max(res, N  -  1 - i);
		}
	}

	cout << res << endl;
}