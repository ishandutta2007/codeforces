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
	int X, Y, Z;
	cin >> X >> Y >> Z;
	int A, B, C;
	cin >> A >> B >> C;

	string res = "YES";

	if (A < X) {
		res = "NO";
	}
	else {
		A -= X;
		if (A + B < Y) {
			res = "NO";
		}
		else {
			A -= Y;
			if (A + B + C < Z) {
				res = "NO";
			}
		}
	}

	cout << res << endl;
}