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
	sort(A.begin(), A.end());
	int ok = 0;
	int ng = N;
	int m = 0;
	while (ng - ok > 1) {
		m = (ok + ng) / 2;
		bool f = true;
		for (int i = 0; i < m; i++) {
			if (A[i] >= A[i + N - m]) {
				f = false;
			}
		}
		if (f) {
			ok = m;
		}
		else {
			ng = m;
		}
	}
	cout << ok << endl;
}