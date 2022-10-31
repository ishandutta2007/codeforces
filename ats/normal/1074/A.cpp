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
	int N, M;
	cin >> N >> M;
	vector<int> A(N);
	int res = (int)1e9;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	A.push_back((int)1e9);
	sort(A.begin(), A.end());
	vector<int> X;
	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			X.push_back(-b);
		}
	}
	sort(X.begin(), X.end());
	for (int i = 0; i < N + 1; i++) {
		//cerr << i + (upper_bound(X.begin(), X.end(), -A[i]) - X.begin()) << endl;
		res = min(res, i + (upper_bound(X.begin(), X.end(), -A[i]) - X.begin()));
	}
	cout << res << endl;
}