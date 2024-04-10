#include <iostream>
#include <vector>
using namespace std;

const int N = 505;
int n, m;

char a[N][N];
bool mark[N][N];
vector <pair <char, pair <int, int> > > ans;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool valid(int x, int y) {
	if (x < 0 || x >= n)
		return false;
	if (y < 0 || y >= m)
		return false;
	return true;
}
void dfs(int x, int y) {
	mark[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int x2 = x + dx[i], y2 = y + dy[i];
		if (valid(x2, y2) && mark[x2][y2] == false && a[x2][y2] == '.') {
			ans.push_back({'B', {x2, y2}});
			dfs(x2, y2);
			ans.push_back({'D', {x2, y2}});
			ans.push_back({'R', {x2, y2}});
		}
	}
}
int main() {
	ios :: sync_with_stdio(false);
	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mark[i][j] == false && a[i][j] == '.') {
				ans.push_back({'B', {i, j}});
				dfs(i, j);
			}
		}
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second.first + 1 << " " << ans[i].second.second + 1 << "\n";
	}
	return 0;
}