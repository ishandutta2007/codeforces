#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iomanip>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 1e3 + 5;
const int Maxn = 4e3 + 5;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
const int block = 316;

int n, m, shoe[100][100];

int xx[] = {0, -1, 0, 1};
int yy[] = {-1, 0, 1, 0};

int to[Maxn], cap[Maxn], cost[Maxn], last[Maxn], pre[Maxn];
int cnt = 0;

int dis[maxn], minCost;

pii par[maxn];

bool mark[maxn];

bool shortpath () {
	memset (dis, -1, sizeof dis);
	dis[0] = 0;
	queue <int> Q;
	Q.push (0);
	mark[0] = 1;
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		mark[u] = 0;
		for (int i = last[u]; i != -1; i = pre[i]) {
			int x = to[i];
			if (cap[i] and (dis[x] == -1 or dis[x] > dis[u] + cost[i])) {
				dis[x] = dis[u] + cost[i];
				par[x].F = u;
				par[x].S = i;
				if (!mark[x]) {
					mark[x] = 1;
					Q.push (x);
				}
			}
		}
	}
	
	if (dis[n * m + 1] == -1)
		return 0;
	minCost += dis[n * m + 1];
	int k = n * m + 1;
	while (k != 0) {
		int idx = par[k].S;
		cap[idx] --;
		cap[idx ^ 1] ++;
		k = par[k].F;
	}
	return 1;
}

void find_flow () { // mincost - maxflow
	bool found = 1;
	while (found) {
		found = shortpath ();
	}
}

void AddEdge (int x, int y, int Cost, int Cap = 1) {
	to[cnt] = y, cap[cnt] = Cap, cost[cnt] = Cost, pre[cnt] = last[x], last[x] = cnt ++;
	to[cnt] = x, cap[cnt] = 0, cost[cnt] = -Cost, pre[cnt] = last[y], last[y] = cnt ++;
}

int ID (int x, int y) {
	return (x - 1) * m + y;
}

int main () {
	ios_base::sync_with_stdio (false);
	memset (last, -1, sizeof last);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> shoe[i][j];
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j ++) {
			if ((i + j) & 1) {
				int x = ID (i, j);
				AddEdge (x, n * m + 1, 0);
				continue;
			}
			int x = ID (i, j);
			AddEdge (0, x, 0);
			for (int k = 0; k < 4; k++) {
				if (i + xx[k] <= 0 or i + xx[k] > n or j + yy[k] <= 0 or j + yy[k] > m)
					continue;
				int x = ID (i, j), y = ID (i + xx[k], j + yy[k]);
				int Cost = (shoe[i][j] != shoe[i + xx[k]][j + yy[k]]);
				AddEdge (x, y, Cost);
			}
		}
	}
	find_flow ();
	cout << minCost << endl;
}