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
int MOD = 998244353;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	string S;
	cin >> S;
	int l = 0;
	for (int i = 0; i < N; i++) {
			if (S[i] == S[0]) {
				l++;
			}
			else {
				break;
			}
	}
	int r = 0;
	for (int i = N - 1; i >= 0; i--) {
			if (S[i] == S.back()) {
				r++;
			}
			else {
				break;
			}
	}
	int res = 0;
	if (l == N) {
		res = (N * (N + 1)) / 2;
	}
	else {
		if (S[0] == S.back()) {
			res = (l + 1) * (r + 1);
		}
		else {
			res = l + r + 1;
		}

	}
	cout << res%MOD << endl;
}