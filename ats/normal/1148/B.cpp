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
	int N, M, X, Y, K;
	cin >> N >> M >> X >> Y >> K;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		A[i] += X;
	}
	vector<int> B(M);
	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}

	if (K >= N || K >= M) {
		cout << -1 << endl;
		return 0;
	}

	int res = 0;
	for (int i = 0; i <= K; i++) {
		int a = A[i];

		int b = lower_bound(B.begin(), B.end(), a) - B.begin();
		//cerr << i <<" " << b << endl;
		b += K - i;

		if(b >= M){
			cout << -1 << endl;
			return 0;
		}
		else {
			res = max(res, B[b] + Y);
		}
	}

	cout << res << endl;
}