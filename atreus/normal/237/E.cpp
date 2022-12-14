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

int n, mincost;

int to[maxn], cap[maxn], cost[maxn], pre[maxn], last[maxn], pos[maxn];

int dis[maxn], par[maxn];

int dfs (int source, int sink, int untilnow) {
	if (source == sink)
		return untilnow;
	int now = 0;
	for (int &ed = pos[source]; ed != -1; ed = pre[ed]) {
		if (cap[ed] and par[to[ed]] == source) {
			int cur = dfs (to[ed], sink, min (cap[ed], untilnow));
			cap[ed] -= cur, cap[ed ^ 1] += cur, mincost += cost[ed] * cur, now += cur, untilnow -= cur;
			if (untilnow == 0)
				return now;
		}
	}
	return now;
}

bool mark[maxn];

bool bfs (int source, int sink) { // SPFA
	memset (dis, -1, sizeof dis);
	dis[source] = 1;
	queue <int> Q;
	Q.push (source);
	mark[source] = 1;
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		mark[cur] = 0;
		for (int ed = last[cur]; ed != -1; ed = pre[ed]) {
			if (cap[ed]) {
				if (dis[to[ed]] == -1) {
					dis[to[ed]] = dis[cur] + cost[ed];
					par[to[ed]] = cur;
					Q.push (to[ed]);
				}
				else if (dis[to[ed]] > dis[cur] + cost[ed]) {
					dis[to[ed]] = dis[cur] + cost[ed];
					par[to[ed]] = cur;
					if (!mark[to[ed]])
						Q.push (to[ed]);
				}
			}
		}
	}
	return dis[sink] != -1;
}

int maxFlow () {
	int source = 1, sink = 1 + 26 + n + 1;
	int ret = 0;
	while (bfs (source, sink)) {
		for (int i = source; i <= sink; i++)
			pos[i] = last[i];
		ret += dfs (source, sink, inf);
	}
	return ret;
}

int cnt = 0;
void addEdge (int fi, int se, int ca, int co) {
	to[cnt] = se, cap[cnt] = ca, cost[cnt] = co, pre[cnt] = last[fi], last[fi] = cnt ++;
	to[cnt] = fi, cap[cnt] = 0, cost[cnt] = -co, pre[cnt] = last[se], last[se] = cnt ++;
}

string s[maxn];
int a[maxn];

int main () {
	ios_base::sync_with_stdio (false);
	memset (last, -1, sizeof last);
	string t;
	cin >> t >> n;
	for (int i = 1; i <= n; i++)
		cin >> s[i] >> a[i];
	int source = 1, sink = 1 + 26 + n +	1;
	for (int i = 0; i < 26; i++) {
		char c = (char)(i + 'a');
		int Cnt = 0;
		for (int j = 0; j < t.size(); j++)
			if (t[j] == c)
				Cnt ++;
		if (Cnt > 0)
			addEdge (source, i + 2, Cnt, 0);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 26; j++) {
			char c = (char)(j + 'a');
			int Cnt = 0;
			for (int k = 0; k < s[i].size(); k++)
				if (s[i][k] == c)
					Cnt ++;
			if (Cnt > 0)
				addEdge (j + 2, 1 + 26 + i, Cnt, 0);
		}
		addEdge (1 + 26 + i, sink, a[i], i);
	}
	
	int flow = maxFlow();
	if (flow == (int)t.size())
		cout << mincost << endl;
	else
		cout << -1 << endl;
	return 0;
}