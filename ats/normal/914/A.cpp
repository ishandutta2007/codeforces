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
	int res = -100000000;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (A[i] < 0 || (int)(sqrt(A[i]) + 0.1)*(int)(sqrt(A[i]) + 0.1) != A[i]) {
			res = max(A[i], res);
		}
	}
	cout << res << endl;
}