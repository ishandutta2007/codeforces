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
const int maxn = 1500 + 10;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
const int block = 316;

ll n, cnt = 0, to[maxn], cap[maxn], last[maxn], pre[maxn], pos[maxn];
ld cop[maxn];

int dis[maxn];

int dfs (int source, int sink, ll untilnow) {
	if (source == sink)
		return untilnow;

	ll now = 0;
	for (ll &ed = pos[source]; ed != -1; ed = pre[ed]) {
		if (cap[ed] and dis[to[ed]] == dis[source] + 1) {
			ll cur = dfs (to[ed], sink, min (cap[ed], untilnow));
			cap[ed] -= cur, cap[ed ^ 1] += cur, untilnow -= cur, now += cur;
			if (untilnow == 0)
				return now;
		}
	}
	return now;
}

bool bfs (int source, int sink) {
	memset (dis, -1, sizeof dis);
	dis[source] = 0;
	queue <int> Q;
	Q.push (source);
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		for (int ed = last[cur]; ed != -1; ed = pre[ed]) {
			if (cap[ed] and dis[to[ed]] == -1) {
				Q.push (to[ed]);
				dis[to[ed]] = dis[cur] + 1;
			}
		}
	}
	return dis[sink] != -1;
}

int flow () {
	int maxFlow = 0;
	while (bfs (1, n)) {
		for (int i = 1; i <= n; i++)
			pos[i] = last[i];
		maxFlow += dfs (1, n, inf);
	}
	return maxFlow;
}

void addEdge (int fi, int se, int c) {
	to[cnt] = se, cop[cnt] = c, cap[cnt] = c, pre[cnt] = last[fi], last[fi] = cnt ++;
	to[cnt] = fi, cop[cnt] = 0, cap[cnt] = 0, pre[cnt] = last[se], last[se] = cnt ++;
}

int main () {
	ios_base::sync_with_stdio (false);
	memset (last, -1, sizeof last);
	int m, x;
	cin >> n >> m >> x;
	for (int i = 1; i <= m; i++) {
		int fi, se, ca;
		cin >> fi >> se >> ca;
		addEdge (fi, se, ca);
	}
	
	ld lo = 0, hi = 1000 * 1000 * 1000;
	int hehehehe = 90;
	while (hehehehe--) {
		ld mid = (lo + hi) / 2;

		for (int i = 0; i < cnt; i++)
			cap[i] = cop[i] / mid;
		
		if (flow() >= x)
			lo = mid;
		else
			hi = mid;
	}
	cout << fixed << setprecision (6) << lo * x << endl;
}