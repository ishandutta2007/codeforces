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
int solve(int a) {
	if (a % 2 == 0) {
		return a / 2;
	}
	else {
		return -((a + 1) / 2);
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> L(N);
	vector<int> R(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> L[i] >> R[i];
	}
	for (int i = 0; i < N; i++) {
		res = solve(R[i]) - solve(L[i] - 1);
		cout << res << endl;
	}
}