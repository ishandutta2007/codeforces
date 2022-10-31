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
int A[2][1000010];
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int M;
	cin >> M;
	int h[2], a[2], x[2], y[2];
	for (int i = 0; i < 2; i++) {
		cin >> h[i] >> a[i];
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 1000010; j++) {
			A[i][j] = -1;
		}
	}
	int st[2];
	int ed[2];
	for (int i = 0; i < 2; i++) {
		int t = h[i];
		int z = 0;
		while (A[i][t] == -1) {
			A[i][t] = z;
			z++;
			//cerr << t << " ";
			t = (x[i] * t + y[i]) % M;
		}
		//cerr << t << " ";
		//cerr << endl;
		st[i] = A[i][t];
		ed[i] = z;
		//cerr << i << " " << st[i] << " " << ed[i] << endl;
	}
	int res = (int)1e18;
	int ans;
	int rep[2];
	bool ok = true;
	for (int i = 0; i < 2; i++) {
		if (A[i][a[i]] == -1) {
			ok = false;
			break;
		}
		if (st[i] <= A[i][a[i]]) {
			rep[i] = ed[i] - st[i];
		}
		else {
			rep[i] = 0;
		}
	}
	if (ok) {
		if (rep[0] == 0 && rep[1] == 0) {
			if (A[0][a[0]] == A[1][a[1]]) {
				res = A[0][a[0]];
			}
		}
		else {
			int p[2];
			p[0] = A[0][a[0]];
			p[1] = A[1][a[1]];
			//cerr << 0 << " " << p[0] << " " << rep[0] << endl;
			//cerr << 1 << " " << p[1] << " " << rep[1] << endl;
			if (rep[0] != 0) {
				swap(rep[0], rep[1]);
				swap(p[0], p[1]);
			}
			for (int j = 0; j < 1000010; j++) {
				int t = (p[0] + rep[0] * j) - p[1];
				if (t >= 0 && t % rep[1] == 0) {
					res = min(res, p[0] + rep[0] * j);
				}
			}
		}

	}
	if (res == (int)1e18) {
		res = -1;
	}
	cout << res << endl;
}