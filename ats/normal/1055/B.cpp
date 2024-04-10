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
	int N, M, L;
	cin >> N >> M >> L;
	vector<int> A(N);
	int res = 0;
	vector<int> X(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (A[i] <= L) {
			X[i] = 0;
		}
		else {
			X[i] = 1;
			int l = ((i == 0) ? 0 : X[i - 1]);
			int r = ((i == N - 1) ? 0 : X[i + 1]);
			res += 1 - l - r;
		}
	}
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a;
		if (a == 0) {
			cout << res << endl;
		}
		else {
			cin >> a >> b;
			a--;
			A[a] += b;
			if (X[a] == 0) {
				if (A[a] > L) {
					//cerr << "A" << A[a] << endl;
					X[a] = 1;
					int l = ((a == 0) ? 0 : X[a - 1]);
					int r = ((a == N - 1) ? 0 : X[a + 1]);
					res += 1 - l - r;
				}
			}
		}
	}
}