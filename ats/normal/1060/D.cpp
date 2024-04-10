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
	vector<int> B(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i];
	}
	sort(B.begin(), B.end());
	sort(A.begin(), A.end());
	res = N;
	for (int i = 0; i < N; i++) {
		res += max(A[i], B[i]);
	}
	cout << res << endl;
}