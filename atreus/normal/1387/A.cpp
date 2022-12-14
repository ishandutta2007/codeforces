#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10;

vector<pair<int,int>> g[maxn];
ld a[maxn];
int h[maxn], b[maxn];
vector<int> now;
bool visited[maxn], mark[maxn];

void check(int v){
	mark[v] = 1;
	for (auto [u,c] : g[v]){
		if (mark[u])
			continue;
		a[u] = c - a[v];
		check(u);
	}
}

int root;

bool dfs(int v){
	visited[v] = 1;
	now.push_back(v);
	bool ret = 0;
	for (auto [u,c] : g[v]){
		if (!visited[u]){
			h[u] = h[v] + 1;
			b[u] = c - b[v];
			ret |= dfs(u);
		}
		else if (h[u] <= h[v]){
			int diff = h[v] - h[u];
			if (diff % 2 == 0){
				int x = b[v] + b[u];
				if (h[v] & 1) // x - 2*a[root] = c -> a[root] = (x - c) / 2
					a[root] = (x-c)/2.;
				else // x + 2*a[root] = c -> a[root] = (c - x) / 2
					a[root] = (c-x)/2.;
				ret = 1;
			}
		}
	}
	return ret;
}

pair<pair<int,int>, int> e[2*maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int v, u, c;
		cin >> v >> u >> c;
		e[i] = {{v,u}, c};
		g[v].push_back({u,c});
		g[u].push_back({v,c});
	}
	for (int v = 1; v <= n; v++){
		if (!visited[v]){
			now.clear();
			root = v;
			bool det = dfs(v);
			if (det == 0){
				for (int i = 0; i < now.size(); i++){
					int u = now[i];
					if (h[u] & 1)
						now[i] = b[u];
					else
						now[i] = -b[u];
				}
				sort(now.begin(), now.end());
				int k = now.size();
				a[v] = now[k/2];
				check(v);
			}
			else
				check(v);
		}
	}
	for (int i = 1; i <= m; i++){
		int v = e[i].first.first, u = e[i].first.second, c = e[i].second;
		if (abs(a[v] + a[u] - c) > 0.1){
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	for (int i = 1; i <= n; i++)
		cout << fixed << setprecision(6) << a[i] << " \n"[i == n];
}