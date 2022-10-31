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
	vector<int> A(N);
	int res = 1;
	int a, b;
	vector<int> X(N, 0);
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b; a--; b--;
		X[a]++;
		X[b]++;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= X[i]; j++) {
			res = (res * j) % MOD;
		}
	}
	res = (res * N) % MOD;
	cout << res << endl;
}