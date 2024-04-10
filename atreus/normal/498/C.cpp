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
const int maxn = 2000 + 5;
const int Maxn = 2005;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
const int block = 316;
int n, m;
int dis[maxn];

int to[maxn], cap[maxn], pre[maxn], last[maxn], pos[maxn];

int cnt = 0;

void add (int fi, int se, int ca) {
	to[cnt] = se, cap[cnt] = ca, pre[cnt] = last[fi], last[fi] = cnt ++;
	to[cnt] = fi, cap[cnt] = 0, pre[cnt] = last[se], last[se] = cnt ++;
}	

int dfs (int source, int sink, int untilnow) {
	if (source == sink)
		return untilnow;
	int now = 0;
	for (int &i = pos[source]; i != -1; i = pre[i]) {
		if (cap[i] and dis[to[i]] == dis[source] + 1) {
			int cur = dfs (to[i], sink, min (untilnow, cap[i]));
			cap[i] -= cur, cap[i ^ 1] += cur, untilnow -= cur, now += cur;
			if (untilnow == 0) {
				return now;
			}
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
		for (int i = last[cur]; i != -1; i = pre[i]) {
			if (cap[i] and dis[to[i]] == -1) {
				dis[to[i]] = dis[cur] + 1;
				Q.push (to[i]);
			}
		}
	}

	return dis[sink] != -1;
}

int solve () {
	int Maxflow = 0, source = 0, sink = n + 1;
	while (bfs (source, sink)) {
		for (int i = 0; i <= sink; i++)
			pos[i] = last[i];
		Maxflow += dfs (source, sink, inf);
	}
	return Maxflow;
}

unordered_map <int, bool> mark;
vector <int> p;

int a[maxn], b[maxn];

pii ed[maxn];

void pri (int x) {
	for (int i = 2; i <= sqrt (x); i++) {
		while (x % i == 0) {
			if (!mark[i]) {
				mark[i] = 1;
				p.PB (i);
			}
			x /= i;
		}
	}
	if (x != 0 and x > 1 and !mark[x]) {
		mark[x] = 1;
		p.PB (x);
	}
}	

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) { 
		cin >> a[i];
		pri (a[i]);
	}
	for (int i = 1; i <= m; i++) {
		cin >> ed[i].F >> ed[i].S;
		if (ed[i].F % 2 == 1)
			swap (ed[i].F, ed[i].S);
	}
	
	int ans = 0;
	for (auto u : p) {
		memset (last, -1, sizeof last);
		cnt = 0;

		for (int i = 1; i <= n; i++) {
			b[i] = 0;
			int x = a[i];
			while (x % u == 0) {
				x /= u;
				b[i] ++;
			}
		}
		for (int i = 1; i <= m; i++) {
			int u = ed[i].F, w = ed[i].S;
			add (u, w, min (b[u], b[w]));
		}
		for (int i = 1; i <= n; i++) {
			if (i % 2 == 1)
				add (i, n + 1, b[i]);
			else
				add (0, i, b[i]);
		}
		ans += solve ();
	}
	cout << ans << endl;
}