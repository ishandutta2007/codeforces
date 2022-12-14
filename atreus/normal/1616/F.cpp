#include <bits/stdc++.h>
#define bit(n, k) (((n)>>(k))&1)
using namespace std;

const int maxn = 256 + 10;
const int mod = 998244353;

int m, row;
int e1[maxn], e2[maxn];
int e[10000][258], bit[10000], col[258];
bool mark[258];

void solveEquation() {
	for (int i = 0; i < m; i++)
		col[i] = 0;
	for (int i = 0; i < row; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (bit[j] != -1 and e[i][bit[j]] != 0) {
				int c = 1 + (e[i][bit[j]] != e[j][bit[j]]);
				for (int k = 0; k <= m; k++)
					e[i][k] = (e[i][k] - c * e[j][k] + 6) % 3;
			}
		}
		bit[i] = -1;
		for (int j = 0; j < m; j++)
			if (e[i][j] != 0)
				bit[i] = j;
		if (bit[i] != -1) {
			for (int j = i - 1; j >= 0; j--) {
				if (bit[j] != -1 and e[j][bit[i]] != 0) {
					int c = 1 + (e[i][bit[i]] != e[j][bit[i]]);
					for (int k = 0; k <= m; k++)
						e[j][k] = (e[j][k] - c * e[i][k] + 6) % 3;
				}
			}
			mark[bit[i]] = 1;
		}
		else {
			if (e[i][m] != 0) {
				cout << -1 << endl;
				return;
			}
		}
	}

	for (int i = 0; i < row; i++)
		if (bit[i] != -1)
			col[bit[i]] = e[i][m] * e[i][bit[i]] % 3;
	for (int i = 0; i < m; i++)
		cout << (col[i] + 1)  << " \n"[i == m-1];
}

void addEq(int i, int j, int k, int x) {
	for (int z = 0; z < m; z++)
		e[row][z] = (z == i) + (z == j) + (z == k);
	e[row][m] = x;
	row++;
}

void addEq(int i, int x) {
	for (int j = 0; j < m; j++)
		e[row][j] = (j == i);
	e[row][m] = x;
	row++;
}

int connected(int i, int j) {
	if (e1[i] == e1[j] || e1[i] == e2[j])
		return e1[i];
	if (e2[i] == e1[j] || e2[i] == e2[j])
		return e2[i];
	return 0;
}

bool isTri(int i, int j, int k) {
	return (connected(i, j) and connected(i, k) and connected(k, j) and connected(i, j) != connected(i, k));
}

void solve() {
	row = 0;	
	int n;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> e1[i] >> e2[i];
		int col;
		cin >> col;
		if (col != -1)
			addEq(i, col - 1);
	}
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			if (!connected(i, j))
				continue;
			for (int k = j + 1; k < m; k++) {
				if (isTri(i, j, k))
					addEq(i, j, k, 0);
			}
		}
	}
	solveEquation();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int tc;
	cin >> tc;
	while (tc --) {
		solve();
	}
}