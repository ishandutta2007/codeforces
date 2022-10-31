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
	int N, K, X;
	cin >> N >> K >> X;
	vector<int> A(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	vector<int> cnt(62, 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 62; j++) {
			if (A[i] & (1LL << j)) {
				cnt[j]++;
			}
		}
	}
	vector<int> cnt2(62, 0);
	int p = 1;
	for (int i = 0; i < K; i++) {
		p *= X;
	}
	
	for (int i = 0; i < N; i++) {
		int t = A[i] * p;
		cnt2 = cnt;

		for (int j = 0; j < 62; j++) {
			if (t & (1LL << j)) {
				cnt2[j]++;
			}
			if (A[i] & (1LL << j)) {
				cnt2[j]--;
			}
		}
		int tmp = 0;
		for (int j = 0; j < 62; j++) {
			if (cnt2[j] > 0) {
				tmp += (1LL << j);
			}
		}
		res = max(res, tmp);
	}


	cout << res << endl;
}