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
	string res(N, '0');
	if (K == 1) {
		res[0] = '1';
	}
	else {
		int t = (N - K) / 2;

		for (int i = 0; i < N; i += t + 1) {
			res[i] = '1';
		}
	}
	cout << res << endl;
}