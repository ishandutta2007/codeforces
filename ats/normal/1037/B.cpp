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
	int N, S;
	cin >> N >> S;
	vector<int> A(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int mi = N / 2;
	for (int i = 0; i < N; i++) {
		if (i < mi) {
			if (A[i] > S) {
				res += A[i] - S;
			}
		}
		else if (i == mi) {
			res += abs(A[i] - S);
		}
		else {
			if (A[i] < S) {
				res += S - A[i];
			}
		}
	}
	cout << res << endl;
}