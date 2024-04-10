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
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
const int block = 316;

ll n, mincost, flow;

ll to[maxn], cap[maxn], cost[maxn], pre[maxn], last[maxn], pos[maxn];

ll dis[maxn], par[maxn];

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
	memset (dis, 63, sizeof dis);
	memset (par, -1, sizeof par);
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
	int source = 1, sink = 1 + n + 2 + 1;
	while (bfs (source, sink)) {
		for (int i = source; i <= sink; i++)
			pos[i] = last[i];
		flow += dfs (source, sink, inf);
	}
}

int cnt = 0;
void addEdge (int fi, int se, int ca, int co) {
	to[cnt] = se, cap[cnt] = ca, cost[cnt] = co, pre[cnt] = last[fi], last[fi] = cnt ++;
	to[cnt] = fi, cap[cnt] = 0, cost[cnt] = -co, pre[cnt] = last[se], last[se] = cnt ++;
}

int main () {
	ios_base::sync_with_stdio (false);
	memset (last, -1, sizeof last);
	int p, s;
	cin >> n >> p >> s;
	int source = 1, sink = 1 + n + 2 + 1;
	addEdge (1 + n + 1, sink, p, 0);
	addEdge (1 + n + 2, sink, s, 0);
	for (int i = 2; i <= n + 1; i++) {
		int a;
		cin >> a;
		addEdge (i, 1 + n + 1, 1, -a);
	}
	for (int i = 2; i <= n + 1; i++) {
		int a;
		cin >> a;
		addEdge (i, 1 + n + 2, 1, -a);
	}
	for (int i = 2; i <= n + 1; i++)
		addEdge (source, i, 1, 0);
	
	maxFlow ();
	cout << -1 * mincost << endl;
	for (int ed = last[1 + n + 1]; ed != -1; ed = pre[ed])
		if (cap[ed] == 1)
			cout << to[ed] - 1 << " ";
	cout << endl;
	for (int ed = last[1 + n + 2]; ed != -1; ed = pre[ed])
		if (cap[ed] == 1)
			cout << to[ed] - 1 << " ";
	cout << endl;
	return 0;
}