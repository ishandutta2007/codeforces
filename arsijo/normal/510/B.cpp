/*
 *      Author: arsijo;
 */
#include <bits/stdc++.h>
using namespace std;
#define input freopen("input.txt", "r", stdin);
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define sync ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long

void happyEnd() {
	cout << "Yes";
	exit(0);
}

char ar[50][50];
bool bol[50][50];
int n, m;

bool dfs(int x, int y, int findX, int findY, int way) {
	//cout << x << " " << y << endl;
	bol[x][y] = true;
	if (x != 0) {
		if (findX == x - 1 && findY == y && way != 1)
			return true;
		if (!bol[x - 1][y] && ar[x - 1][y] == ar[x][y]
				&& dfs(x - 1, y, findX, findY, way + 1))
			return true;
	}
	if (y != 0) {
		if (findX == x && findY == y - 1 && way != 1)
			return true;
		if (!bol[x][y - 1] && ar[x][y - 1] == ar[x][y]
				&& dfs(x, y - 1, findX, findY, way + 1))
			return true;
	}
	if (x != n - 1) {
		if (findX == x + 1 && findY == y && way != 1)
			return true;
		if (!bol[x + 1][y] && ar[x + 1][y] == ar[x][y]
				&& dfs(x + 1, y, findX, findY, way + 1))
			return true;
	}
	if (y != m - 1) {
		if (findX == x && findY == y + 1 && way != 1)
			return true;
		if (!bol[x][y + 1] && ar[x][y + 1] == ar[x][y]
				&& dfs(x, y + 1, findX, findY, way + 1))
			return true;
	}
	return false;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> ar[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			memset(bol, false, sizeof(bol));
			//cout << "!" << endl;
			if (dfs(i, j, i, j, 0))
				happyEnd();
		}
	}
	cout << "No";
}