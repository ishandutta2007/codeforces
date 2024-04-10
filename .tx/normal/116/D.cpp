#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct rec {
	int ubr, kol;
	rec() {
		kol = 1e9;
		ubr = 0;
	}
	bool operator < (const rec &r) {
		return ubr > r.ubr || (ubr == r.ubr && kol < r.kol);
	}
};

rec a[150][150];
char b[150][150];
int n, m, mmin, k;

void dfs(int x, int y) {
	rec t = a[x][y];
	if (t.ubr == k) {
		mmin = min(mmin, t.kol);
	}
	int d = x % 2;
	if (d) { //
		if (y > 0) {
			t.kol++;
			t.ubr += b[x][y - 1] == 'W';
			if (t < a[x][y - 1]) {
				a[x][y - 1] = t;
				dfs(x, y - 1);
			}
		}
	}
	else { //
		t = a[x][y];
		if (y < m - 1) {
			t.kol++;
			t.ubr += b[x][y + 1] == 'W';
			if (t < a[x][y + 1]) {
				a[x][y + 1] = t;
				dfs(x, y + 1);
			}
		}
	}
	t = a[x][y];
	if (x < n - 1) {
		t.kol++;
		t.ubr += b[x + 1][y] == 'W';
		if (t < a[x + 1][y]) {
			a[x + 1][y] = t;
			dfs(x + 1, y);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m;
	getchar();
	mmin = 1e9;
	k = 0;
	for (int i = 0; i < n; i++) {
		for (int g = 0; g < m; g++) {
			b[i][g] = getchar();
			k += b[i][g] == 'W';
		}
		getchar();
	}
	a[0][0].kol = 0;
	a[0][0].ubr = b[0][0] == 'W';
	dfs(0, 0);
	cout << mmin;




	return 0;
}//tpqojm