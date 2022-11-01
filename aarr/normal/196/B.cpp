#include <iostream>
#include <set>
using namespace std;

const int N = 1505;
const int inf = 1000 * 1000 * 1000 + 7;
pair <int, int> pinf = {inf, inf};
int n, m, xs, ys, nparts = 1;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char c[N][N];
int part[N][N];
pair <int, int> mark[N][N];
bool vp[N * N];
set <pair <int, int> > s;
//bool vis[N][N][9];
bool val(int x, int y) {
	if (x < 0 || x >= n)
		return false;
	if (y < 0 || y >= m)
		return false;
	return true;
}
int md(int a, int b) {
	return (a + b * N) % b;
}
void dfs(int x, int y) {
//	cout << "47 " << x << " " << y << endl;
	int xm = md(x, n), ym = md(y, m);
	pair <int, int> p = {x, y};
	if (c[xm][ym] == '#' || mark[xm][ym] == p)
		return;
//	cout << "49 " << x << " " << y << endl;
	if (mark[xm][ym] != pinf) 
	{
//		cout << "56 " << x << " " << y << endl;
		cout << "Yes";
		exit(0);
	}
	mark[xm][ym] = {x, y};
	for (int i = 0; i < 4; i++) {
		int x2 = x + dx[i], y2 = y + dy[i];
		dfs(x2, y2);
	}
}
void dfs2(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int x2 = x + dx[i], y2 = y + dy[i];
		if (val(x2, y2) && part[x2][y2] == 0 && c[x2][y2] != '#') {
			part[x2][y2] = part[x][y];
			dfs2(x2, y2);
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c[i][j];
			if (c[i][j] == 'S') {
				xs = i, ys = j;
			}
			mark[i][j] = pinf;
		}
	}
	dfs(xs, ys);
	cout << "No";
	return 0;
}