#include <iostream>
using namespace std;

const int N = 100 * 1000 + 5, M = 15, SQ = 300;
int n, m, q;

struct cell {
	int x, y; 
};

cell lp = {-1, -1};

char c[N + N][M];
bool mark[N + N][M];
cell dp[N + N][M];
bool val(int x, int y, int p) {
	if (x < p * SQ || x >= n || x >= (p + 1) * SQ)
		return false;
	if (y < 0 || y >= m)
		return false;
	return true;
}
bool kolval(int x, int y) {
	if (x < 0 || x >= n)
		return false;
	if (y < 0 || y >= m)
		return false;
	return true;
}
cell go(int x, int y, int p) {
	if (mark[x][y])
		return dp[x][y];
	mark[x][y] = true;
	dp[x][y] = lp;
	int x2 = x, y2 = y;
	if (c[x][y] == '<')
		y2--;
	if (c[x][y] == '>')
		y2++;
	if (c[x][y] == '^') 
		x2--;
	if (val(x2, y2, p)) {
		dp[x][y] = go(x2, y2, p);
	}
	else {
		dp[x][y] = {x, y};
	}
	return dp[x][y];
	
}
void update(int p) {
	fill(mark[p * SQ], mark[min((p + 1) * SQ, n)], false);
	for (int i = p * SQ; i < (p + 1) * SQ && i < n; i++) {
		for (int j = 0; j < m; j++) {
		//	cout << i << " " << j << endl;
			go(i, j, p);
		}
	}
}
cell get(int x, int y) {
	int x2 = dp[x][y].x, y2 = dp[x][y].y;
	if (x2 == -1) {
		return lp;
	}
	int x3 = x2, y3 = y2;
	if (c[x2][y2] == '<')
		y3--;
	if (c[x2][y2] == '>')
		y3++;
	if (c[x2][y2] == '^') 
		x3--;
	if (!kolval(x3, y3)) {
		cell c;
		c.x = x2;
		c.y = y2;
		return c;
	}
	else {
		return get(x3, y3);
	}
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c[i][j];
		}
	}
	for (int i = 0; i < n; i += SQ) {
		update(i / SQ);
	}
	for (int t = 0; t < q; t++) {
		char qt;
		cin >> qt;
		if (qt == 'A') {
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			cell d = get(x, y);
			int x2 = d.x, y2 = d.y;
			if (x2 == -1) {
				cout << -1 << " " << -1 << endl;
			}
			else {
				int x3 = x2, y3 = y2;
				if (c[x2][y2] == '<')
					y3--;
				if (c[x2][y2] == '>')
					y3++;
				if (c[x2][y2] == '^') 
					x3--;
				cout << x3 + 1 << " " << y3 + 1 << '\n';				
			}

		}
		else {
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			char d;
			cin >> d;
			c[x][y] = d;
			update(x / SQ);
		}
	}
	return 0;
}