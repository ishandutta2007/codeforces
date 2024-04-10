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
	vector<int> A(M);
	vector<int> H(M);
	int res = 0;
	for (int i = 0; i < M; i++) {
		cin >> A[i] >> H[i];
	}
	bool ok = true;
	int dx, dy;
	res = 0;
	for (int i = 0; i < M - 1; i++) {
		dx = A[i + 1] - A[i];
		dy = abs(H[i + 1] - H[i]);
		if (dy > dx)ok = false;
		int x = max(H[i], H[i + 1]) + (dx - dy) / 2;
		res = max(res, x);
	}
	res = max(res, A[0] - 1 + H[0]);
	res = max(res, N - A.back() + H.back());
	if (ok) {
		cout << res << endl;
	}
	else {
		cout << "IMPOSSIBLE" << endl;
	}
}