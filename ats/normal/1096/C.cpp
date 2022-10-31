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
bool check(int N, int K) {

	if ((K * N) % 180 == 0) {
		int a = (K * N) / 180;
		if (a >= 1 && a <= N - 2) {
			return true;
		}
	}
	return false;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> A(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 3; j <= 360; j++) {
			if (check(j, A[i])) {
				cout << j << endl;
				break;
			}
		}
	}
}