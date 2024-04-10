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
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int res = 0;
	for (int i = 0; i < K; i++) {
		int t = 0;
		for (int j = 0; j < N; j++) {
			if (j % K != i) {
				t += A[j];
			}
		}
		res = max(res, abs(t));
	}
	cout << res << endl;
}