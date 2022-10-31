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
	vector<int> P(N, -1);
	vector<vector<int> > g(N);

	for (int i = 1; i < N; i++) {
		cin >> P[i]; P[i]--;
		g[P[i]].push_back(i);
	}
	vector<int> sz(N, 0);
	for (int i = N - 1; i >= 0; i--) {
		for (int j : g[i]) {
			sz[i] += sz[j];
		}
		if (sz[i] == 0)sz[i] = 1;
	}
	vector<int> A(N + 1, 0);
	for (int i = 0; i < N; i++) {
		A[sz[i]]++;
	}
	vector<int> res(N + 1);
	for (int i = 1; i <= N; i++) {
		A[i] += A[i - 1];
	}
	for (int i = N; i > 0; i--) {
		res[A[i]] = i;
	}
	for (int i = N; i > 0; i--) {
		if (res[i] == 0)res[i] = res[i + 1];
	}
	for (int i = 1; i <= N; i++) {
		if (i > 1)cout << " ";
		cout << res[i];
	}
	cout << endl;
}