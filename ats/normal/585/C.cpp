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
	int X, Y;
	cin >> X >> Y;
	bool s = false;
	if (X > Y) {
		s = true;
		swap(X, Y);
	}
	vector<int> res;
	while (X > 0) {
		res.push_back(Y / X);
		int t = Y % X;
		Y = X;
		X = t;
	}
	if (Y != 1) {
		cout << "Impossible" << endl;
		return 0;
	}
	res.back()--;
	if (res.back() == 0) {
		res.pop_back();
	}
	char AB;
	if (s) {
		AB = 'A';
	}
	else {
		AB = 'B';
	}
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << AB;
		AB = (int)'A' + 'B' - AB;
	}

}