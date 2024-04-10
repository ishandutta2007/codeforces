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
const int maxn = 2e5 + 5;
const int Maxn = 2e4 + 10;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
const int block = 316;

int maxFlow, n, a[maxn];

bool prime[Maxn];

int cnt, to[maxn], cap[maxn], pre[maxn], last[maxn], pos[maxn];

void add (int fi, int se, int ca) {
	to[cnt] = se, cap[cnt] = ca, pre[cnt] = last[fi], last[fi] = cnt ++;
	to[cnt] = fi, cap[cnt] = 0, pre[cnt] = last[se], last[se] = cnt ++;
}


int dis[maxn];

int dfs (int source, int sink, int untilnow) {
	if (source == sink)
		return untilnow;
	int now = 0;
	for (int &ed = pos[source]; ed != -1; ed = pre[ed]) {
		if (cap[ed] and dis[to[ed]] == dis[source] + 1) {
			int cur = dfs (to[ed], sink, min (cap[ed], untilnow));
			cap[ed] -= cur, cap[ed ^ 1] += cur, now += cur, untilnow -= cur;
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

void flow () {
	int source = 0, sink = n + 1;
	while (bfs (source, sink)) { 
		for (int i = 0; i <= sink; i++)
			pos[i] = last[i];
		maxFlow += dfs (source, sink, inf);
	}
}

void setprimes () {
	for (int i = 1; i <= 2e4; i++)
		prime[i] = 1;
	prime[1] = 0;
	for (int i = 2; i <= 2e4; i++)
		for (int j = 2; j <= sqrt (i); j++)
			if (i % j == 0)
				prime[i] = 0;
}

vector <int> v[maxn], com[maxn];
int idx;
bool visited[maxn];

void DFS (int u) {
	visited[u] = 1;
	com[idx].PB (u);
	for (auto w : v[u])
		if (!visited[w])
			DFS (w);
}

int main() {
	memset (last, -1, sizeof last);
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	
	setprimes ();

	if (n % 2 == 1)
		return cout << "Impossible" << endl, 0;

	for (int i = 1; i <= n; i++) {
		if (a[i] % 2 == 0)
			add (0, i, 2);
		else
			add (i, n + 1, 2);
	}
	
	for (int i = 1; i <= n; i++) {
		if (a[i] % 2 == 1)
			continue;
		for (int j = 1; j <= n; j++)
			if (prime[a[i] + a[j]])
				add (i, j, 1); 
	}

	flow ();
	if (maxFlow != n)
		return cout << "Impossible" << endl, 0;

	for (int i = 1; i <= n; i++) {
		for (int j = last[i]; j != -1; j = pre[j]) {	
			if (to[j] != 0 and to[j] != n + 1 and j % 2 == 0 and cap[j] == 0) {
				v[i].PB (to[j]);
				v[to[j]].PB (i);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			DFS (i);
			idx ++;
		}
	}	
	
	cout << idx << endl;
	for (int i = 0; i < idx; i++) {
		cout << com[i].size() << " ";
		for (auto w : com[i])
			cout << w << " ";
		cout << endl;
	}
}