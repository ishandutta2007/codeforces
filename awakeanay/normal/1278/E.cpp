#include <iostream>
#include <vector>
#include <queue>
 
#define MAXN 5000005
#define int long
 
 
struct item
{
	int l, r, val;
};
 
std::vector<item> list(2*MAXN + 2);
std::vector<std::vector<int> > Adj(MAXN);
std::vector<int> rev(MAXN);
std::vector<bool> vis(MAXN);
std::vector<std::pair<int, int> > out(MAXN);
std::queue<int> q;
int c;
 
int insertL(int id, int val) {
	list[c].l = list[id].l;
	list[c].r = id;
	list[c].val = val;
	list[list[id].l].r = c;
	list[id].l = c;
	return c++;
}
 
int insertR(int id, int val) {
	list[c].l = id;
	list[c].r = list[id].r;
	list[c].val = val;
	list[list[id].r].l = c;
	list[id].r = c;
	return c++;
}
 
signed main() {
	std::ios_base::sync_with_stdio(false);
	
	int n;
	std::cin >> n;
 
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--; v--;
		Adj[u].push_back(v);
		Adj[v].push_back(u);
	}
 
	list[0].r = 1;
	list[1].l = 0;
	c = 2;
 
	rev[0] = insertL(1, 0);
	insertL(1, n);
 
	q.push(0);
 
	for(int i = 0; i < n; i++)
		vis[i] = false;
 
	vis[0] = true;
 
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int v : Adj[u]) {
			if(!vis[v]) {
				vis[v] = true;
				rev[v] = insertL(rev[u], v);
				insertR(rev[u], v+n);
				q.push(v);
			}
		}
	}
 
	int cur = list[0].r;
	for(int i = 1; i <= 2*n; i++) {
		int u = list[cur].val;
		if(u < n) {
			out[u].first = i;
		} else {
			out[u-n].second = i;
		}
		cur = list[cur].r;
	}
 
	for(int i = 0; i < n; i++) {
		std::cout << out[i].first << " " << out[i].second << std::endl;
	}
 
	return 0;
}