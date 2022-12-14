#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long ll;
const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;
const int inf = 1e9 + 10;

pair<pair<int, int>, pair<int, int> > rec[55];
int n, a[maxn];
 
int cnt, to[maxn], cap[maxn], pre[maxn], last[maxn], pos[maxn];
 
void add_edge(int fi, int se, int ca) {
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
 
bool bfs(int source, int sink){
	memset (dis, -1, sizeof dis);
	dis[source] = 0;
	queue <int> Q;
	Q.push(source);
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		for (int ed = last[cur]; ed != -1; ed = pre[ed]) {
			if (cap[ed] and dis[to[ed]] == -1) {
				Q.push(to[ed]);
				dis[to[ed]] = dis[cur] + 1;
			}
		}
	}
	return dis[sink] != -1;
}
 
int max_flow(int source, int sink){
	int maxFlow = 0;
	while (bfs(source, sink)) { 
		for (int i = 0; i <= sink; i++)
			pos[i] = last[i];
		maxFlow += dfs(source, sink, inf);
	}
	return maxFlow;
}

bool mp[200][200];

int main(){
	ios_base::sync_with_stdio(false);
	memset(last, -1, sizeof last);
	int n, m;
	cin >> n >> m;
	if (m == 0)
		return cout << 0 << endl, 0;
	vector<int> up, dw;
	for (int i = 0; i < m; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		rec[i] = {{x1, y1}, {x2, y2}};
		up.push_back(x1);
		up.push_back(x2 + 1);
		dw.push_back(y1);
		dw.push_back(y2 + 1);
	}
	sort(up.begin(), up.end());
	up.resize(unique(up.begin(), up.end()) - up.begin());
	sort(dw.begin(), dw.end());
	dw.resize(unique(dw.begin(), dw.end()) - dw.begin());
	int upsz = up.size() - 1;
	int dwsz = dw.size() - 1;
	int src = 0, snk = upsz + dwsz + 1;
	for (int i = 0; i < upsz; i++)
		add_edge(src, i + 1, up[i + 1] - up[i]);
	for (int i = 0; i < dwsz; i++)
		add_edge(upsz + i + 1, snk, dw[i + 1] - dw[i]);
	for (int i = 0; i < m; i++){
		int x1 = rec[i].F.F, y1 = rec[i].F.S, x2 = rec[i].S.F, y2 = rec[i].S.S;
		x1 = lower_bound(up.begin(), up.end(), x1) - up.begin();
		y1 = lower_bound(dw.begin(), dw.end(), y1) - dw.begin();
		x2 = lower_bound(up.begin(), up.end(), x2 + 1) - up.begin();
		y2 = lower_bound(dw.begin(), dw.end(), y2 + 1) - dw.begin();
		for (int j = x1; j < x2; j++)
			for (int k = y1; k < y2; k++)
				if (mp[j][k] == 0)
					add_edge(j + 1, k + 1 + upsz, inf), mp[j][k] = 1;
	}
	cout << max_flow(src, snk) << endl;
}