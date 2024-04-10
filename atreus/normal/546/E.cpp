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
const int maxn = 200 + 5;
const int Maxn = 2005;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
const int block = 316;

int n, m, a[maxn], b[maxn], go[maxn][maxn];

bool visited[maxn];

int to[Maxn], cap[Maxn], pre[Maxn], last[Maxn], pos[Maxn];

int cnt = 0, Maxflow;

void add (int fi, int se, int ca) {
	to[cnt] = se, cap[cnt] = ca, pre[cnt] = last[fi], last[fi] = cnt ++;
	to[cnt] = fi, cap[cnt] = 0, pre[cnt] = last[se], last[se] = cnt ++;
}

int dis[maxn];

bool bfs (int src, int sin) {
	memset (dis, -1, sizeof dis);
	dis[src] = 0;
	queue <int> Q;
	Q.push (src);
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for (int i = last[u]; i != -1; i = pre[i]) {
			if (cap[i] and dis[to[i]] == -1) {
				dis[to[i]] = dis[u] + 1;
				Q.push (to[i]);
			}
		}
	}
	return dis[sin] != -1;
}

int dfs (int src, int sin, int untilnow) {
	if (src == sin)
		return untilnow;
	int now = 0;
	for (int &i = pos[src]; i != -1; i = pre[i]) {
		if (cap[i] and dis[to[i]] == dis[src] + 1) {
			int cur = dfs (to[i], sin, min (untilnow, cap[i]));
			cap[i] -= cur, cap[i ^ 1] += cur, untilnow -= cur, now += cur;
			if (untilnow == 0)
				return now;
		}	
	}
	return now;
}

int main() {
	memset (last, -1, sizeof last);
	cin >> n >> m;
	int sum = 0, tot = 0;
	for (int i = 1; i <= n; i++) { 
		cin >> a[i];
		tot += a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		sum += b[i];
	}
	for (int i = 1; i <= m; i++) {
		int u, w;
		cin >> u >> w;
		add (2 * u + 0, 2 * w + 1, a[u]);
		add (2 * w + 0, 2 * u + 1, a[w]);
	}
	
	if (tot != sum) {
		return cout << "NO" << endl, 0;
	}

	for (int i = 1; i <= n; i++) {
		add (2 * i + 1, 1, b[i]);
		add (0, 2 * i + 0, a[i]);
		add (2 * i + 0, 2 * i + 1, a[i]);
	}
	
	int src = 0, sin = 1;
	while (bfs (src, sin)) {
		for (int i = 0; i <= 2 * n + 1; i++)
			pos[i] = last[i];
		Maxflow += dfs (src, sin, inf);
	}
	
	if (Maxflow != sum)
		return cout << "NO" << endl, 0;

	cout << "YES" << endl;
	
	for (int i = 1; i <= n; i++) {
		int u = 2 * i + 1;
		for (int j = last[u]; j != -1; j = pre[j]) {
			if (j % 2 == 1)
				go[to[j] / 2][i] += cap[j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << go[i][j] << " ";
		cout << '\n';
	}
}