#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 55;
int n, m;

int c[N];
int x[N];
int y[N];
int a[N][N];
vector <int> mv[3][N];


void move(int t, int x1, int y1, int x2, int y2) {
//	cout << "48 " << t << " " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	x[a[x1][y1]] = x2;
	y[a[x1][y1]] = y2;
	mv[t][0].push_back(x1);
	mv[t][1].push_back(y1);
	mv[t][2].push_back(x2);
	mv[t][3].push_back(y2);
	swap(a[x1][y1], a[x2][y2]);
}

void solve(int t) {
	sort(c + 1, c + m + 1, [] (int p, int q) {
		return x[p] < x[q];
	});
	for (int ii = 0; ii < n; ii++) {
		for (int i = 1; i <= m; i++) {
			int p = c[i];
			if (x[p] > i) {
				bool b = true;
				for (int j = i; j < x[p]; j++) {
					if (a[j][y[p]]) {
						b = false;
					}
				}
				if (!b) {
					continue;
				}
				while (x[p] > i) {
					move(t, x[p], y[p], x[p] - 1, y[p]);
				}
			}
			if (x[p] < i) {
				bool b = true;
				for (int j = i; j > x[p]; j--) {
					if (a[j][y[p]]) {
						b = false;
					}
				}
				if (!b) {
					continue;
				}
				while (x[p] < i) {
					move(t, x[p], y[p], x[p] + 1, y[p]);
				}				
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		while (y[i] > i) {
			move(t, x[i], y[i], x[i], y[i] - 1);
		}
		while (y[i] < i) {
			move(t, x[i], y[i], x[i], y[i] + 1);
		}
	}
	for (int i = 1; i <= m; i++) {
		while (x[i] > i) {
			move(t, x[i], y[i], x[i] - 1, y[i]);
		}
		while (x[i] < i) {
			move(t, x[i], y[i], x[i] + 1, y[i]);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> x[i] >> y[i];
		c[i] = i;
		a[x[i]][y[i]] = i;
	}
	solve(0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> x[i] >> y[i];
		c[i] = i;
		a[x[i]][y[i]] = i;
	}
	solve(1);
	cout << mv[0][0].size() + mv[1][0].size() << endl;
	for (int i = 0; i < mv[0][0].size(); i++) {
		cout << mv[0][0][i] << " " << mv[0][1][i] << " " << mv[0][2][i] << " " << mv[0][3][i] << endl;
	}
	for (int i = (int) mv[1][0].size() - 1; i >= 0; i--) {
		cout << mv[1][2][i] << " " << mv[1][3][i] << " " << mv[1][0][i] << " " << mv[1][1][i] << endl;
	}
	return 0;
}