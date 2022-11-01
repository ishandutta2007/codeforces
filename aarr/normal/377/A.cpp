#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 505;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

char c[N][N];
bool mark[N][N];
queue<pair <int, int> > q;
vector <pair <int, int> > vec;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int sx = 0, sy = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c[i][j];
			if (c[i][j] == '.') {
				sx = i, sy = j;
			}
		}
	}
	q.push({sx, sy});
	mark[sx][sy] = true;
	while (q.size()) {
		int x = q.front().first, y = q.front().second;
	//	cout << "73 " << x << " " << y << endl;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x2 = x + dx[i], y2 = y + dy[i];
			if (x2 >= 0 && y2 >= 0 && x2 < n && y2 < m && c[x2][y2] == '.' && !mark[x2][y2]) {
				mark[x2][y2] = true;
				q.push({x2, y2});
				vec.push_back({x2, y2});
			}
		}
	}
	for (int i = (int) vec.size() - 1; i >= (int) vec.size() - k; i--) {
		c[vec[i].first][vec[i].second] = 'X';
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << c[i][j];
		}
		cout << endl;
	}
	return 0;
}