#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <deque>
#include <unordered_map>
#include <fstream>
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
const int maxn = 5e5 + 10;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
const int block = 316;

ll n, flow;
ld mincost;

ll to[maxn], cap[maxn], pre[maxn], last[maxn], pos[maxn];
ld cost[maxn];

ll par[maxn];
ld dis[maxn];

int dfs (int source, int sink, ll untilnow) {
	if (source == sink)
		return untilnow;
	int now = 0;
	for (ll &ed = pos[source]; ed != -1; ed = pre[ed]) {
		if (cap[ed] and par[to[ed]] == source) {
			ll cur = dfs (to[ed], sink, min (cap[ed], untilnow));
			cap[ed] -= cur, cap[ed ^ 1] += cur, mincost += cost[ed] * cur, now += cur, untilnow -= cur;
			if (untilnow == 0)
				return now;
		}
	}
	return now;
}

bool mark[maxn];

bool bfs (int source, int sink) { // SPFA
	memset (par, -1, sizeof par);
	for (int i = source; i <= sink; i++)
		dis[i] = inf;
	dis[source] = 0;
	queue <int> Q;
	Q.push (source);
	mark[source] = 1;
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		mark[cur] = 0;
		for (int ed = last[cur]; ed != -1; ed = pre[ed]) {
			if (cap[ed] and dis[to[ed]] > dis[cur] + cost[ed]) {
				dis[to[ed]] = dis[cur] + cost[ed];
				par[to[ed]] = cur;
				if (!mark[to[ed]]) {
					Q.push (to[ed]);
					mark[to[ed]] = 1;
				}
			}
		}
	}
	return par[sink] != -1;
}

void maxFlow () {
	int source = 1, sink = 1 + 2 * n + 1;
	while (bfs (source, sink)) {
		for (int i = source; i <= sink; i++)
			pos[i] = last[i];
		flow += dfs (source, sink, inf);
	}
}

int cnt = 0;
void addEdge (int fi, int se, int ca, ld co) {
	to[cnt] = se, cap[cnt] = ca, cost[cnt] = co, pre[cnt] = last[fi], last[fi] = cnt ++;
	to[cnt] = fi, cap[cnt] = 0, cost[cnt] = -co, pre[cnt] = last[se], last[se] = cnt ++;
}

int x[maxn], y[maxn];

ld DIS (int i, int j) {
	ld xx = abs (x[i] - x[j]), yy = abs (y[i] - y[j]);
	return sqrt (1.0 * xx * xx + yy * yy);
}

int main () {
	ios_base::sync_with_stdio (false);
	memset (last, -1, sizeof last);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> x[i] >> y[i];
	
	int source = 1, sink = 1 + 2 * n + 1;
	for (int i = 1; i <= n; i++)
		addEdge (source, 1 + i, 2, 0);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (y[i] > y[j]) 
				addEdge (1 + i, 1 + n + j, 1, DIS (i, j));
	for (int i = 1; i <= n; i++)
		addEdge (1 + n + i, sink, 1, 0);
	
	maxFlow();
	if (flow == n - 1)
		cout << fixed << setprecision (12) << mincost << endl;
	else
		cout << -1 << endl;
	return 0;
}