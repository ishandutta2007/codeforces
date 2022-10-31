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
	int N;
	cin >> N;
	string S;
	cin >> S;
	int f = -1;
	vector<int> X(N, 0);
	for (int i = 1; i < N; i++) {

		if (S[i] == S[i - 1]) {
			if (f == -1) {
				f = 0;
			}
			else {
				break;
			}
		}
		if (f == 0) {
			X[i] = 1;
		}
	}
	for (int i = 0; i < N; i++) {
		if (X[i] == 1) {
			S[i] = '1' + '0' - S[i];
		}
	}
	//cerr << S << endl;
	int res = 1;
	for (int i = 1; i < N; i++) {
		if (S[i] != S[i - 1])res++;
	}
	cout << res << endl;
}