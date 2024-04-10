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
	int a, b, f, k;
	int bb;
	cin >> a >> b >> f >> k;
	bb = b;
	vector<int> A;
	A.push_back(f);
	if (k % 2 == 0) {
		for (int i = 0; i < (k/2) - 1; i++) {
			A.push_back(a - f + a - f);
			A.push_back(2 * f);
		}
		A.push_back(a - f + a - f);
		A.push_back(f);
	}
	else {
		for (int i = 0; i < (k / 2); i++) {
			A.push_back(a - f + a - f);
			A.push_back(2 * f);
		}
		A.push_back(a - f);
	}
	int res = 0;
	for (int i = 0; i < A.size(); i++) {
		if (b >= A[i]) {
			b -= A[i];
		}
		else {
			res++;
			b = bb;
			b -= A[i];
			if (b < 0) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	cout << res << endl;
}