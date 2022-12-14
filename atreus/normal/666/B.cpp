#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <queue>
#include <time.h>
#include <set>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <bitset>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define In insert
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7, maxn = 3e3 + 100;
int n, m, dis[maxn][maxn], go[maxn][5], come[maxn][5];
bool visited[maxn];
queue <int> bfs;
vector <int> v[maxn];

void bfsearch (int u){
	bfs.push(u);
	visited[u] = 1;
	dis[u][u] = 0;
	int m = u;
	while (!bfs.empty()){
		u = bfs.front();
		bfs.pop();
		for (auto w : v[u]){
			if (!visited[w]){
				bfs.push(w);
				visited[w] = 1;
				dis[m][w] = dis[m][u] + 1;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int u, w;
		cin >> u >> w;
		v[u].PB(w); // u --> w
	}
	memset (dis, -63, sizeof dis);
	for (int i = 1; i <= n; i++){
		memset (visited, 0, sizeof visited);
		bfsearch (i);
	}
	for (int i = 1; i <= n; i++){
		vector <pair <int, int> > g, c;
		for (int j = 1; j <= n; j++){
			g.PB({dis[i][j], j});
			c.PB({dis[j][i], j});
		}
		sort (g.begin(), g.end(), greater <pair <int, int> > ());
		sort (c.begin(), c.end(), greater <pair <int, int> > ());
		for (int k = 0; k < 3; k++){
			go[i][k] = g[k].S;
			come[i][k] = c[k].S;
		}
	}
	int maxx = -1, a1, a2, a3, a4;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (i == j)
				continue;
			for (int k = 0; k < 3; k++){
				for (int l = 0; l < 3; l++){
					int u = come[i][k], w = go[j][l];
					if (dis[u][i] <= 0 || dis[i][j] <= 0 || dis[j][w] <= 0)
						continue;
					if (u != j and u != w and w != i and maxx < dis[u][i] + dis[i][j] + dis[j][w]){
						maxx = dis[u][i] + dis[i][j] + dis[j][w];
						a1 = u;
						a2 = i;
						a3 = j;
						a4 = w;
					}
				}
			}
		}
	}
//	cout << maxx << endl;
	cout << a1 << " " << a2 << " " << a3 << " " << a4 << endl;
}