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
	int cur = 0;

	for (int i = 0; i < N;) {
		cur = max(i, cur);
		while (cur < N  && A[cur] <= 1)cur++;
		if (cur == N)break;
		if (i == cur) {
			if (A[i] >= 3) {
				res += A[i] / 3;
				A[i] %= 3;
			}
			else {
				cur++;
			}
		}
		else {

			int t = min(A[i], A[cur] / 2);
			res += t;
			A[i] -= t;
			A[cur] -= t * 2;
			if (A[i] == 0)i++;

		}
		if (cur == N)break;
	}



	cout << res << endl;
}