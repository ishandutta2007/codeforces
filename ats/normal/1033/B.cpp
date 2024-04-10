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
	int t;
	cin >> t;
	while (t--) {
		int A, B;
		cin >> A >> B;
		string res;
		if (A - B == 1) {
			A = 2 * A - 1;
			res = "YES";
			for (int i = 2; i*i <= A; i++) {
				if (A%i == 0) {
					res = "NO";
					break;
				}
			}
		}
		else {
			res = "NO";
		}
		cout << res << endl;
	}
}