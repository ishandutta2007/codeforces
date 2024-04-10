#include<bits/stdc++.h>
using namespace std;
int n, m;
char mapp[1001][1001];
bool vis[1001][1001];
const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
void bfs(int x, int y) {
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	vis[x][y] = 1;
	while (q.size()) {
		int u = q.front().first, v = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int u0 = u + dir[i][0], v0 = v + dir[i][1];
			if (u0 <= 0 || u0 > n || v0 <= 0 || v0 > m) continue;
			if (vis[u0][v0] || mapp[u0][v0] == '.') continue;
			vis[u0][v0] = 1;
			q.push(make_pair(u0, v0));
		}
	}
}
int main() {
	cin >> n >> m;
	bool vis1 = 0, vis2 = 0;
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		for (int j = 1; j <= m; j++) {
			char c = getchar();
			while (c != '.' && c != '#') c=getchar();
			mapp[i][j] = c;
			if (c == '#') {
				if (tmp == 2) {
					puts("-1");
					return 0;
				}
				tmp = 1;
			}
			else if (tmp) tmp = 2;
		}
		if (!tmp) vis1 = 1;
	}
	for (int j = 1; j <= m; j++) {
		int tmp = 0;
		for (int i = 1; i <= n; i++) {
			char c = mapp[i][j];
			if (c == '#') {
				if (tmp == 2) {
					puts("-1");
					return 0;
				}
				tmp = 1;
			}
			else if (tmp) tmp = 2;
		}
		if (!tmp) vis2 = 1;
	}
	if (vis1 ^ vis2) {
		puts("-1");
		return 0;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (mapp[i][j] == '#' && !vis[i][j]) {
				bfs(i, j);
				++ans;
			}
	cout << ans << endl;
}