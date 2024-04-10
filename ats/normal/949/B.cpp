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
int solve(int n,int k,int t) {
	//cerr << n << " " << k << " " << t << endl;
	if ((k % 2) == 1 - t) {
		return (k + 1) / 2;
	}
	if (t == 0) {
		return ((n + 1) / 2) + solve(n - ((n + 1) / 2), k / 2, n % 2);
	}
	else {
		return ((n) / 2) + solve(n - ((n) / 2), (k + 1) / 2,  1 - (n % 2));
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, Q;
	cin >> N >> Q;
	int a;
	for (int i = 0; i < Q; i++) {
		cin >> a;
		int res = solve(N, a, 0);
		cout << solve(N, a, 0) << endl;
	}
}