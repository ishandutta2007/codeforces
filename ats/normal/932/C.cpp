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
	int N, A, B;
	cin >> N >> A >> B;
//	int res = 0;
	vector<int> res(N);
	for (int i = 0; i < N; i++) {
		res[i] = i;
	}
	for (int i = 0; N - i*A >= 0; i++) {
		int C = N - i*A;
		if (C % B == 0) {
			int j = C / B;
			int st = 0;
			for (int ii = 0; ii < i; ii++) {
				int ed = st + A;
				for (int jj = st; jj < ed - 1; jj++) {
					res[jj] = jj + 1;
				}
				res[ed - 1] = st;
				st += A;
			}
			for (int ii = 0; ii < j; ii++) {
				int ed = st + B;
				for (int jj = st; jj < ed - 1; jj++) {
					res[jj] = jj + 1;
				}
				res[ed - 1] = st;
				st += B;
			}
			//cerr << st << endl;
			for (int i = 0; i < N; i++) {
				if (i > 0)cout << " ";
				cout << res[i] + 1;
			}
			cout << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}