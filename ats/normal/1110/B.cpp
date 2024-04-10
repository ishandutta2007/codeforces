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
	int N, M, K;
	cin >> N >> M >> K;
	vector<int> A(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int all = A.back() - A[0] + 1;

	vector<int> B;
	for (int i = 1; i < A.size(); i++) {
		B.push_back(A[i] - A[i - 1]);
	}
	sort(B.rbegin(), B.rend());
	int z = 0;
	for (int i = 0; i < K - 1; i++) {
		all -= B[i] - 1;
	}


	cout << all << endl;
}