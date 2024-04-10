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
string res;
vector<int> A;
int N;
char dfs(int a) {
	if (res[a] == '.') {
		res[a] = 'B';
		int v = A[a];
		for (int i = a + v; i < N; i += v) {
			if (A[i] > v) {
				if (dfs(i) == 'B') {
					res[a] = 'A';
				}
			}
		}
		for (int i = a - v; i >= 0; i -= v) {
			if (A[i] > v) {
				if (dfs(i) == 'B') {
					res[a] = 'A';
				}
			}
		}

	}
	return res[a];
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N;
	A.resize(N);
	res.resize(N, '.');
	int t = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (A[i] == 1) {
			t = i;
		}
	}
	dfs(t);
	cout << res << endl;
}