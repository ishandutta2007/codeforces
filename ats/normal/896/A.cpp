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
int INF = (int)1000000000 * 1000000000 + 10;
vector<int> num(100005);
string S0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string S1 = "What are you doing while sending \"";
string S2 = "\"? Are you busy? Will you send \"";
string S3 = "\"?";
char solve(int n, int k) {
	if (n > 0) {
		if (k <= (int)S1.size()) {
			return S1[k - 1];
		}
		k -= (int)S1.size();
		if (k <= num[n - 1]) {
			return solve(n - 1, k);
		}
		k -= num[n - 1];
		if (k <= (int)S2.size()) {
			return S2[k - 1];
		}
		k -= (int)S2.size();
		if (k <= num[n - 1]) {
			return solve(n - 1, k);
		}
		k -= num[n - 1];
		if (k <= (int)S3.size()) {
			return S3[k - 1];
		}
		k -= (int)S3.size();
	}
	else {
		if (k <= (int)S0.size()) {
			return S0[k - 1];
		}
	}
	return '.';
}
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
	num[0] = S0.size();
	for (int i = 1; i < 100005; i++) {
		num[i] = (int)num[i - 1] * 2 + (int)S1.size() + S2.size() + S3.size();
		if (num[i] > INF) {
			num[i] = INF;
		}
	}
	for (int i = 0; i < N; i++) {
		cout << solve(A[i], B[i]);
	}
	cout << endl;
}