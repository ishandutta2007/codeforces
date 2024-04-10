#include<bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, m;

vector<pair<int, int> > edge[N];

int fa[N], mins[N], type[N], stamp;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v, len;
		scanf("%d%d%d", &u, &v, &len);
		edge[u].push_back(make_pair(v, len));
		edge[v].push_back(make_pair(u, len));
	}
	memset(type, -1, sizeof(type));
	type[n - 1] = 0;
	queue<int> q;
	q.push(n - 1);
	queue<vector<int> > qq;
	qq.push(vector<int>());
	while (q.size()) {
		int u = q.front();
		qq.front().push_back(u);
		q.pop();
		for (int i = 0; i < (int)edge[u].size(); ++i) {
			int v = edge[u][i].first, d = edge[u][i].second;
			if (type[v] == -1 && d == 0) {
				type[v] = 0;
				fa[v] = u;
				q.push(v);
			}
		}
	}
	while (qq.size()) {
		vector<int> uu = qq.front();
		++stamp;
		qq.pop();
		vector<int> vis;
		for (int i = 0; i < (int)uu.size(); ++i) {
			int u = uu[i];
			for (int j = 0; j < (int)edge[u].size(); ++j) {
				int v = edge[u][j].first, d = edge[u][j].second;
				if (type[v] == -1) {
					type[v] = stamp;
					vis.push_back(v);
					fa[v] = u;
					mins[v] = d;
				} else if (type[v] == stamp && d < mins[v]) {
					fa[v] = u;
					mins[v] = d;	
				}
			}
		}
		vector<int> bucket[10];
		for (int i = 0; i < (int)vis.size(); ++i) {
			int u = vis[i];
			bucket[mins[u]].push_back(u);
		}
		for (int i = 0; i < 10; ++i) {
			if (bucket[i].size()) {
				qq.push(bucket[i]);
			}
		}
	}
	vector<int> path;
	path.push_back(0);	
	int u = 0;
	string ans;
	while (u != n - 1) {
		if (type[u]) {
			ans += mins[u] + '0';
		}
		u = fa[u];
		path.push_back(u);
	}
	if (ans.size()) {
		reverse(ans.begin(), ans.end());
		puts(ans.c_str());
	} else {
		puts("0");
	}
	printf("%d\n", (int)path.size());
	for (int i = 0; i < (int)path.size(); ++i) {
		printf("%d%c", path[i], i == (int)path.size() - 1 ? '\n' : ' ');
	}
	return 0;
}