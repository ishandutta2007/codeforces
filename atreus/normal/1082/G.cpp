#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e3 + 10;
const int maxm = 4e3 + 10;
const ll inf = 1e18;

int cnt;
int to[2 * maxm], last[maxn], pre[2 * maxm], pos[maxn];
int dis[maxn], Q[maxn];
ll cap[2 * maxm];

ll dfs(int src, int snk, ll untilnow){
	if (src == snk)
		return untilnow;
	ll now = 0;
	for (int &ed = pos[src]; ed != -1; ed = pre[ed]){
		if (cap[ed] and dis[to[ed]] == dis[src] + 1){
			ll tmp = dfs(to[ed], snk, min(untilnow, cap[ed]));
			cap[ed] -= tmp, cap[ed^1] += tmp, now += tmp, untilnow -= tmp;
			if (untilnow == 0)
				return now;
		}
	}
	return now;
}

bool bfs(int src, int snk){
	memset(dis, -1, sizeof dis);
	dis[src] = 0;
	int head = 0, tail = 0;
	Q[head ++] = src;
	while (tail < head){
		int v = Q[tail ++];
		for (int ed = last[v]; ed != -1; ed = pre[ed]){
			if (cap[ed] and dis[to[ed]] == -1){
				dis[to[ed]] = dis[v] + 1;
				Q[head ++] = to[ed];
			}
		}
	}
	return dis[snk] != -1;
}

ll mincut(int src, int snk){
	ll ret = 0;
	while (bfs(src, snk)){
		for (int i = src; i <= snk; i++)
			pos[i] = last[i];
		ret += dfs(src, snk, inf);
	}
	return ret;
}

void add_edge(int v, int u, ll c){
	to[cnt] = u, cap[cnt] = c, pre[cnt] = last[v], last[v] = cnt ++;
	to[cnt] = v, cap[cnt] = 0, pre[cnt] = last[u], last[u] = cnt ++;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int src = 0, snk = n + m + 1;
	memset(last, -1, sizeof last);
	for (int i = 1; i <= n; i++){
		int a;
		cin >> a;
		add_edge(src, i, a);
	}
	ll sum = 0;
	for (int i = 1; i <= m; i++){
		int v, u, w;
		cin >> v >> u >> w;
		sum += w;
		add_edge(v, i + n, inf);
		add_edge(u, i + n, inf);
		add_edge(i + n, snk, w);
	}
	cout << sum - mincut(src, snk) << endl;
}