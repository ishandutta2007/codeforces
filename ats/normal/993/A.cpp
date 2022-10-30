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

	vector<int> X1(4);
	vector<int> Y1(4);
	vector<int> X2(4);
	vector<int> Y2(4);
	int mnx1 = 1000;
	int mxx1 = -1000;
	int mny1 = 1000;
	int mxy1 = -1000;
	int mnx2 = 1000;
	int mxx2 = -1000;
	int mny2 = 1000;
	int mxy2 = -1000;
	for (int i = 0; i < 4; i++) {
		cin >> X1[i] >> Y1[i];
		mnx1 = min(mnx1, X1[i]);
		mxx1 = max(mxx1, X1[i]);
		mny1 = min(mny1, Y1[i]);
		mxy1 = max(mxy1, Y1[i]);
	}
	for (int i = 0; i < 4; i++) {
		cin >> X2[i] >> Y2[i];
		mnx2 = min(mnx2, X2[i]);
		mxx2 = max(mxx2, X2[i]);
		mny2 = min(mny2, Y2[i]);
		mxy2 = max(mxy2, Y2[i]);
	}
	int cx = (mnx2 + mxx2);
	int cy = (mny2 + mxy2);

	string res = "NO";
	for (int i = 0; i < 4; i++) {
		if (abs(cx - 2 * X1[i]) + abs(cy - 2 * Y1[i]) <= mxx2 - mnx2) {
			res = "YES";
		}
	}
	if (abs(cx - (mnx1 + mxx1)) + abs(cy - (mny1 + mxy1)) <= mxx2 - mnx2) {
		res = "YES";
	}
	for (int i = 0; i < 4; i++) {
		if (mnx1 <= X2[i] && mxx1 >= X2[i] && mny1 <= Y2[i] && mxy1 >= Y2[i]) {
			res = "YES";
		}
	}

	cout << res << endl;
}