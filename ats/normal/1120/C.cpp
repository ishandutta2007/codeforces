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
void z(string &S, vector<int> &A) {
	A.clear();
	A.resize(S.size(), 0);
	A[0] = S.size();
	int i = 1, j = 0;
	while (i < S.size()) {
		while (i + j < S.size() && S[j] == S[i + j]) ++j;
		A[i] = j;
		if (j == 0) { ++i; continue; }
		int k = 1;
		while (i + k < S.size() && k + A[k] < j) A[i + k] = A[k], ++k;
		i += k; j -= k;
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, A, B;
	cin >> N >> A >> B;
	string S;
	cin >> S;
	vector<int> mx(N, 0);
	string T = S;
	vector<int> X;
	for (int i = 0; i < N; i++) {
		z(T, X);
		for (int j = 1; j < N - i; j++) {
			mx[j + i] = max(mx[j + i], min(X[j], j));
		}
		T.erase(T.begin());
	}

	vector<int> dp(N + 1, 0);

	/*for (int i = 0; i < N; i++) {
		cerr << mx[i] << " ";
	}
	cerr << endl;*/



	for (int i = N - 1; i >= 0; i--) {
		dp[i] = dp[i + 1] + A;

		for (int j = 1; j <= mx[i]; j++) {
			dp[i] = min(dp[i], dp[i + j] + B);
		}
	}


	cout << dp[0] << endl;
}