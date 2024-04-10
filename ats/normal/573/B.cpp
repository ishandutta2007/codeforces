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
vector<int> solve(const vector<int> &B) {
	int N = B.size();
	vector<int> res(N);
	int mn = MOD;
	for (int i = 0; i < N; i++) {
		mn++;
		mn = min(mn, B[i]);
		res[i] = mn;
	}
	return res;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	vector<int> B(N);
	B[0] = 0;
	B.back() = 0;
	for (int i = 1; i < N - 1; i++) {
		B[i] = min(A[i - 1], A[i + 1]);
		B[i] = min(B[i], A[i] - 1);
	}
	vector<int> X1 = solve(B);
	reverse(B.begin(), B.end());
	vector<int> X2 = solve(B);
	reverse(X2.begin(), X2.end());
	int res = 0;

	/*for (int i = 0; i < N; i++) {
		cerr << X1[i] << " ";
	}
	cerr << endl;
	for (int i = 0; i < N; i++) {
		cerr << X2[i] << " ";
	}
	cerr << endl;*/
	for (int i = 0; i < N; i++) {
		res = max(res, min(X1[i], X2[i]));
	}
	cout << res + 1 << endl;
}