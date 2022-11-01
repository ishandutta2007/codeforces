#include <iostream>
using namespace std;

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};


const int N = 32, M = 205;
int n;

bool b[M * 2][M * 2];
bool mark[M * 2][M * 2][10][N];
int a[M];

void dfs(int x, int y, int d, int l) {
//	if (x < 0 || y < 0)
//	cout << x - M << " " << y - M << " " << d << " " << l << endl;
	if (mark[x][y][d][l] || l > n) {
		return;
	}
	mark[x][y][d][l] = true;
	for (int i = 1; i <= a[l]; i++) {
		x += dx[d];
		y += dy[d];
		b[x][y] = true;
	}
	int d1 = (d + 1) % 8, d2 = (d + 7) % 8;
	dfs(x, y, d1, l + 1);
	dfs(x, y, d2, l + 1);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	a[1]--;
//	mark[N][N][0][1] = true;
	b[M][M] = true;
	dfs(M, M, 0, 1);
	int ans = 0;
	for (int i = 0; i < M * 2; i++) {
		for (int j = 0; j < M * 2; j++) {
			if (b[i][j]) {
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}