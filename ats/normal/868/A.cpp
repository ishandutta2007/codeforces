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
	string S;
	cin >> S;
	int N;
	cin >> N;
	vector<string> A(N);
	int res = 0;
	bool f = false;
	bool a1 = false;
	bool a2 = false;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (S == A[i]) {
			f = true;
		}
		if (S[0] == A[i][1]) {
			a1 = true;
		}
		if (S[1] == A[i][0]) {
			a2 = true;
		}
	}

	if (a1 && a2) {
		f = true;
	}
	if (f) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}