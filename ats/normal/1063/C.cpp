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
#include <assert.h>
using namespace std;
#define int long long
int MOD = 1000000007;
int ask(int x, int y) {
	/*if (x == -1) {
		return 0;
	}
	else {
		return 1;
	}*/
	cout << x << " " << y << endl << flush;
	string S;
	cin >> S;
	if (S[0] == 'b') {
		return 0;
	}
	else {
		return 1;
	}
}
signed main() {
	int N;
	cin >> N;
	vector<int> A(N);
	int u = (int)1e9;
	int d = 0;
	int l = ask(d, 0);
	for (int i = 1; i < N; i++) {
		assert(u - d > 1);
		int m = (u + d) / 2;
		int t = ask(m, 0);
		if (t == l) {
			d = m;
		}
		else {
			u = m;
		}

	}
	cerr << d << " " << u << endl;
	if (u == 1e9) {
		cout << 0 << " " << 1 << " " << 1 << " " << 1 << endl;
	}
	if (d != 0) {
		cout << d << " " << 1 << " " << d - 1 << " " << 3 << endl;
	}
	else {
		cout << u << " " << 1 << " " << u + 1 << " " << 3 << endl;
	}
}