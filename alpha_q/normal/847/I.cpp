#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 

ll a[300][300], vis[300][300];
char g[300][300];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m, p, q, t;

void bfs(int x, int y, int add) {
	queue<pair<ii, int> > q; q.push({{x, y}, add});
	vis[x][y] = t;
	while(!q.empty()) {
		auto it = q.front(); q.pop(); 
		int x = it.first.first, y = it.first.second;
		int add = it.second;
		a[x][y] += add;
		if(!add) continue; 
		for(int i = 0; i < 4; i++) {
			int xx = x + dx[i], yy = y + dy[i]; 
			if(xx >= 0 && xx < n && yy >= 0 && yy < m) {
				if(vis[xx][yy] < t && g[xx][yy] != '*') {
					vis[xx][yy] = t; 
					q.push({{xx, yy}, add/2});
				}
			}
		}
	}
}
int main(int argc, char const *argv[]) {
	cin >> n >> m >> q >> p;
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < m; j++) 
			cin >> g[i][j];
		
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(g[i][j] != '.' && g[i][j] != '*') {
				t++;
				bfs(i, j, (g[i][j] - 'A' + 1) * q); 
			}
		}
	}
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) 
			if(a[i][j] > p) cnt++;
	}
	cout << cnt << endl;
}