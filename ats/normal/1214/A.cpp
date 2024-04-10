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
	int N, A, B;
	cin >> N >> A >> B;
	B *= 5;
	int res = N;
	for (int i = 0; i <= 100000; i++) {
		int r = N - B * i;
		if (r >= 0) {
			res = min(res, r % A);
		}
	}


	cout << res << endl;
}