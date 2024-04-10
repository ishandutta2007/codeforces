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
	vector<int> B(M);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	
	if (A.back() > B[0]) {
		cout << -1 << endl;
		return 0;
	}

	for (int i = 0; i < N; i++) {
		res += A[i] * B.size();
	}

	if (B[0] == A.back()) {
		for (int i = 0; i < M; i++) {
			
			res += B[i] - A.back();
		}
	}
	else {
		for (int i = 1; i < M; i++) {
			res += B[i] - A.back();
		}
		res += B[0] - A[(int)A.size() - 2];
	}

	

	cout << res << endl;
}