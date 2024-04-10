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
	int res = 0;
	vector<int> A(N);
	int t;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		A[i] = abs(A[i]);
	}

	sort(A.begin(), A.end());
	for (int i = 0; i < N; i++) {

		res += (upper_bound(A.begin(), A.end(), 2 * A[i]) - A.begin()) - i - 1;

	}

	cout << res << endl;
}