#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

int nowcmp = 0;
int cnt1[maxn], cnt2[maxn];
int cmp1[maxn], cmp2[maxn];
bool visited[maxn];
vector<int> g[maxn];
map<pair<int, int>, int> cnt;

void dfs2(int v){
	visited[v] = 1;
	cmp2[v] = nowcmp;
	for (auto u : g[v])
		if (!visited[u])
			dfs2(u);
}

void dfs1(int v){
	visited[v] = 1;
	cmp1[v] = nowcmp;
	for (auto u : g[v])
		if (!visited[u])
			dfs1(u);
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		int n, m, a, b;
		cin >> n >> m >> a >> b;
		for (int i = 1; i <= n; i++)
			g[i].clear();
		for (int i = 1; i <= m; i++){
			int v, u;
			cin >> v >> u;
			g[v].push_back(u);
			g[u].push_back(v);
		}
		int root;
		for (int i = 1; i <= n; i++)
			if (a != i and b != i)
				root = i;
		nowcmp = 1;
		for (int i = 1; i <= n; i++)
			visited[i] = 0;
		visited[a] = 1;
		for (int i = 1; i <= n; i++)
			if (!visited[i])
				dfs1(i), nowcmp ++;
		for (int i = 1; i <= n; i++)
			visited[i] = 0;
		visited[b] = 1;
		nowcmp = 1;
		for (int i = 1; i <= n; i++)
			if (!visited[i])
				dfs2(i), nowcmp ++;
		ll answer = 0;
		for (int i = 1; i <= n; i++){
			if (i == a or i == b)
				continue;
			answer += cnt1[cmp1[i]];
			answer += cnt2[cmp2[i]];
			answer -= cnt[{cmp1[i], cmp2[i]}];
			cnt1[cmp1[i]] ++;
			cnt2[cmp2[i]] ++;
			cnt[{cmp1[i], cmp2[i]}] ++;
		}
		ll tot = 1ll * (n - 2) * (n - 3) / 2;
		cout << tot - answer << '\n';
		for (int i = 0; i <= n; i++)
			cnt1[i] = cnt2[i] = 0;
		cnt.clear();
	}
}