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
	int N, K;
	cin >> N >> K;
	string S;
	cin >> S;
	vector<int> A(N);
	int p = 1;
	for (int i = 0; i < N; i++) {
		if (S[i] == '(') {
			A[i] = p;
			p++;
		}
	}
	p = 1;
	for (int i = N - 1; i >= 0; i--) {
		if (S[i] == ')') {
			A[i] = p;
			p++;
		}
	}
	string res;
	for (int i = 0; i < N; i++) {
		if (A[i] <= (K / 2)) {
			res.push_back(S[i]);
		}
	}
	cout << res << endl;
}