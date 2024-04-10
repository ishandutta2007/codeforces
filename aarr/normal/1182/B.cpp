#include <iostream>
using namespace std;

const int N = 510;

int a[N];
int b[N];
char c[N][N];
bool solve() {
	int n, m;
	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c[i][j];
			if (c[i][j] == '*') {
				a[i]++;
				b[j]++;
			}
		}
 		
	}
	int x = -1, y = -1, fx = -1, lx = -1, fy = -1, ly = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] > 1) {
			if (x >= 0)
				return false;
			x = i;
		}
		if (a[i] > 0) {
			if (fx == -1)
				fx = i;
			lx = i;
		}
		
	}
	for (int i = 0; i < m; i++) {
		if (b[i] > 1) {
			if (y >= 0)
				return false;
			y = i;
		}
		if (b[i] > 0) {
			if (fy == -1)
				fy = i;
			ly = i;
		}
	}
	if (x < 0 || y < 0)
		return false;
	//cout << x << " " << fx << " " << lx << endl;
	//cout << y << " " << fy << " " << ly << endl;
	if (lx == x || fx == x || fy == y || ly == y)
		return false;
	for (int i = fx; i <= lx; i++) {
		if (c[i][y] == '.')
			return false;
	}
	for (int i = fy; i <= ly; i++) {
		if (c[x][i] == '.')
			return false;
	}
	return true;
}
int main() {
	if (solve())
		cout << "YES";
	else
		cout << "NO";
	return 0;
}