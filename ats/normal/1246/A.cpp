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
int bits(int a) {
	int res = 0;
	while (a > 0) {
		res += a % 2;
		a /= 2;
	}
	return res;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, P;
	cin >> N >> P;
	int res = -1;
	for (int i = 0; i <= 50; i++) {
		if (i <= N - P * i && bits(N - P * i) <= i) {
			res = i;
			break;
		}
	}
	cout << res << endl;
}