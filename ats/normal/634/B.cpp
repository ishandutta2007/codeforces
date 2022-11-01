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
	int S, X;
	cin >> S >> X;
	int t = S - X;
	if (t % 2 == 1) {
		cout << 0 << endl;
		return 0;
	}

	t /= 2;
	

	if (t & X) {
		cout << 0 << endl;
		return 0;
	}
	int res = 1;
	while (X > 0) {
		if (X % 2)res *= 2;
		X /= 2;
	}
	if (t == 0) {
		res -= 2;
	}

	cout << res << endl;
}