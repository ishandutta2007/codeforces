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
	int N, K;
	cin >> N >> K;
	int res = 0;
	res += (2 * N + K - 1) / K;
	res += (5 * N + K - 1) / K;
	res += (8 * N + K - 1) / K;
	cout << res << endl;
}