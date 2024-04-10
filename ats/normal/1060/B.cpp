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
int solve(int N) {
	if (N == 0)return 0;
	int k = N % 10;
	int res = k + solve((N - k)/10);
	if (N >= k + 10 && k <= 8) {
		res = max(res, k + 10 + solve((N - k - 10) / 10));
	}
	return res;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	cout << solve(N) << endl;
	
}