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
	int N, U;
	cin >> N >> U;
	vector<int> A(N);
	double res = -1;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int ne = 0;
	for (int i = 0; i < N - 1; i++) {
		while (ne < N && A[ne] - A[i] <= U) {
			ne++;
		}
		if (ne - 1 >= i + 2) {
			res = max(res, (A[ne - 1] - A[i + 1]) / (double)(A[ne - 1] - A[i]));
		}
	}
	if (res < -0.5) {
		cout << -1 << endl;
	}
	else {
		cout << setprecision(15) <<  res << endl;
	}
}