# include <queue>
# include <vector>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 200051;
int n;
queue <int> q;
vector <int> g[MAXN];
int a[MAXN], b[MAXN];
bool cmp(int x, int y){
	return b[x] < b[y];
}
bool check(){
	q.push(1);
	for (int i = 1; i <= n; i++){
		if (q.empty() || q.front() != a[i]) return false;
		int nw = q.front();
		q.pop();
		int sz = g[nw].size();
		for (int j = 0; j < sz; j++){
			if (b[g[nw][j]] > b[nw]) q.push(g[nw][j]);
		}
		// printf("bfs %d %d\n", nw, g[nw].size());
	}
	return q.empty();
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n - 1; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; i++){
		scanf("%d", a + i);
		b[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) sort(g[i].begin(), g[i].end(), cmp);
	if (check()) printf("Yes\n");
	else printf("No\n");
	return 0;
}