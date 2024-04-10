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
#include <assert.h>
using namespace std;
#define int long long
int MOD = 1000000007;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, T;
	cin >> N >> T;
	vector<int> A(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	vector<int> B = A;
	sort(B.begin(), B.end());
	vector<int> sum = B;
	for (int i = 1; i < N; i++) {
		sum[i] += sum[i - 1];
	}
	while (true) {
		int k = upper_bound(B.begin(), B.end(), T) - B.begin() - 1;
		//cerr << k << endl;
		if (k == -1)break;
		if (sum[k] <= T) {
			int r = T / sum[k];
			res += r * (k + 1);
			T = T % sum[k];
		}
		else {
			for (int i = 0; i < N; i++) {
				if (T >= A[i]) {
					T -= A[i];
					res++;
				}
			}
		}
	}

	//assert(T < B[0]);
	//cerr << T << endl;
	cout << res << endl;
}