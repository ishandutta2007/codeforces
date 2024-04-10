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
	int N;
	cin >> N;
	if (N == 1) {
		cout << 1 << endl;
		return 0;
	}
	int t = N;
	vector<int> X;
	for (int i = 2; i*i <= t; i++) {
		if (t % i == 0) {
			X.push_back(i);
			while (t % i == 0) {
				t /= i;
			}
		}
	}
	if (t > 1) {
		X.push_back(t);
	}
	if (X.size() >= 2) {
		cout << 1 << endl;
	}
	else {
		cout << X[0] << endl;
	}

}