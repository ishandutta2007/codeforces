# include <set>
# include <queue>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 200051;
set <int> st;
set <int> g[MAXN];
int n, m;
int ans[MAXN];
int bfs(int s){
	queue <int> q;
	int cnt = 0;
	q.push(s);
	while (!q.empty()){
		int nw = q.front();
		q.pop();
		cnt++;
		for (set <int>::iterator i = st.begin(); i != st.end(); ){
			int nxtn = *i;
			if (g[nw].find(nxtn) != g[nw].end()){
				i++;
				continue;
			}
			q.push(nxtn);
			st.erase(i++);
		}
	}
	return cnt;
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].insert(v);
		g[v].insert(u);
	}
	for (int i = 1; i <= n; i++) st.insert(i);
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		set <int>::iterator p = st.find(i);
		if (p == st.end()) continue;
		st.erase(p++);
		ans[++cnt] = bfs(i);
	}
	sort(ans + 1, ans + cnt + 1);
	printf("%d\n", cnt);
	for (int i = 1; i <= cnt; i++) printf("%d ", ans[i]);
	putchar('\n');
	return 0;
}