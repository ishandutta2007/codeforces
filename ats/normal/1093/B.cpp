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
	vector<string> A(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		sort(A[i].begin(), A[i].end());

		if (A[i][0] == A[i].back()) {
			cout << -1 << endl;
		}
		else {
			cout << A[i] << endl;
		}
	}

}