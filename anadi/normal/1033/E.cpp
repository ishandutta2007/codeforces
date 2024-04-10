#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 607;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m;
bool vis[N];
int color[N];
vector <int> G[N];
vector <int> cl[2];

int ask(vector <int> in){
	if(in.size() == n)
		return 0;

	vector <bool> inside(n + 1, 0);
	printf("? %d\n", n - in.size());
	
	for(int v: in)
		inside[v] = true;
	
	for(int i = 1; i <= n; ++i)
		if(!inside[i])
			printf("%d ", i);
//	puts("");
	fflush(stdout);
	
	int ret;
	scanf("%d", &ret);
	
	if(ret == -1)	exit(0);
	return m - ret;
}

int ask2(vector <int> in){
	if(in.size() == 0)
		return 0;

	printf("? %d\n", in.size());
	for(int v: in)
		printf("%d ", v);
//	puts("");
	fflush(stdout);
	
	int ret;
	scanf("%d", &ret);
	
	if(ret == -1)	exit(0);
	return m - ret;
}

void getM(){
	printf("? %d\n", n);
	for(int i = 1; i <= n; ++i)
		printf("%d ", i);
	fflush(stdout);

	scanf("%d", &m);
}

int go(vector <int> cur, int u){
	if(cur.size() == 1)
		return cur[0];
//	assert(cur.size() > 0);
	
	vector <int> help;
	int m = (cur.size() - 1) / 2;
	
	for(int i = 0; i <= m; ++i)
		help.push_back(cur[i]);
	
	int d = ask2(help);
	help.push_back(u);
	
	int d2 = ask2(help);
	help.pop_back();
	
	if(d != d2)
		return go(help, u);
	
	help.clear();
	for(int i = m + 1; i < (int)cur.size(); ++i)
		help.push_back(cur[i]);
	return go(help, u);
}

int getEdge(int u){
//	printf("SZUKAM DLA %d\n", u);
	vector <int> Visited;
	for(int i = 1; i <= n; ++i)
		if(vis[i] && i != u)
			Visited.push_back(i);
	
	int t = ask(Visited);
	Visited.push_back(u);
	int cnt = ask(Visited);
	
	if(t == cnt)
		return -1;
	
	cnt -= t;
	vector <int> Unvisited;

	for(int i = 1; i <= n; ++i)
		if(!vis[i])
			Unvisited.push_back(i);
	
	if(Unvisited.size() == 0)
		return -1;
	return go(Unvisited, u);
}

void dfs(int u){
	vis[u] = true;
	while(true){
		int id = getEdge(u);
		if(id == -1)
			break;

		G[u].push_back(id);
		G[id].push_back(u);
		
		color[id] = color[u] ^ 1;
		dfs(id);
	}
	
	cl[color[u]].push_back(u);
}

int p[N];
void Dfs(int u){
	vis[u] = true;
	for(int v: G[u])
		if(!vis[v])
			p[v] = u,
			Dfs(v);
}

void writeCycle(int t){
	int cnt = ask(cl[t ^ 1]); int who = -1;
	for(int i = 0; i < cl[t].size(); ++i){
		cl[t ^ 1].push_back(cl[t][i]);
		if(ask(cl[t ^ 1]) > cnt){
			cl[t ^ 1].pop_back();
			who = cl[t][i];
			break;
		}
		
		cl[t ^ 1].pop_back();
	}
	
	int who2 = -1; cnt = ask({who});
	for(int i = 0; i < cl[t].size(); ++i){
		if(cl[t][i] == who)	continue;
		int cnt2 = ask({cl[t][i]});
		if(cnt + cnt2 != ask({cl[t][i], who})){
			who2 = cl[t][i];
			break;
		}
	}
	
	for(int i = 1; i <= n; ++i)
		vis[i] = false;
	
	Dfs(who);
	vector <int> res;
	
 	t = who2;
	res.push_back(who2);

	while(t != who){
		t = p[t];
		res.push_back(t);
	}
	
	printf("N %d\n", res.size());
	for(int v: res)
		printf("%d ", v);
	fflush(stdout);
	exit(0);
}

int main(){
	scanf("%d", &n);
	getM();
	
	for(int i = 1; i <= n; ++i)
		if(!vis[i])
			dfs(i);
	
	if(ask(cl[0]) < m)
		writeCycle(1);
	if(ask(cl[1]) < m)
		writeCycle(0);
	
	printf("Y %d\n", cl[0].size());
	for(int v: cl[0])
		printf("%d ", v);
	puts("");
	fflush(stdout);
	return 0;
}