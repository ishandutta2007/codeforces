#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define LOGN 18
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 2e5 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, k, r;
bool spec[N];
vector <int> G[N];

int id[N];
queue <int> Q;

int rep[N];
int tr[N], add[N];
set <PII> S[N];

int lvl[N];
int jump[LOGN][N];
int pre[N], post[N];

int q;
int ans[N];
vector <PII> req[N];

int sz[N];
bool block[N];

int dists[N];
vector <int> colors;

void dfs(int u, int p){
	static int Time = 0;
	pre[u] = ++Time;
	jump[0][u] = p;
	
	for(auto v: G[u])
		if(v != p){
			lvl[v] = lvl[u] + 1;
			dfs(v, u);
		}

	post[u] = Time;
}

int Find(int u){
	if(rep[u] == u)
		return u;
	return rep[u] = Find(rep[u]);
}

void Union(int u, int v){
	rep[Find(u)] = Find(v);
}

int connect(int a, int b){
	add[b]++;
	if(S[a].size() > S[b].size())
		swap(a, b);
	
	for(auto v: S[a])
		S[b].insert({v.st + add[a] - add[b], v.nd});
	S[a].clear();

	if(S[b].size() > 1){
		auto it = *S[b].begin();
		S[b].erase(S[b].begin());
		
		while(S[b].size() > 0 && (*S[b].begin()).st + it.st + 2 * add[b] <= k){
			Union((*S[b].begin()).nd, it.nd);
			S[b].erase(S[b].begin());
		}
		
		S[b].insert(it);
	}
	
	return b;
}

void getGraph(int u, int p){
	tr[u] = u;
	if(spec[u])
		S[u].insert({0, u});
	
	for(auto v: G[u])
		if(v != p){
			getGraph(v, u);
			tr[u] = connect(tr[u], tr[v]);
		}
}

void prepare(){
	for(int i = 1; i <= n; ++i)
		if(spec[i]){
			id[i] = i;
			Q.push(i);
		}
		else
			id[i] = -1;
	
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		
		for(auto v: G[u])
			if(id[v] == -1){
				id[v] = id[u];
				Q.push(v);
			}
	}
	
	dfs(1, 1);
	for(int i = 1; i < LOGN; ++i)
		for(int j = 1; j <= n; ++j)
			jump[i][j] = jump[i - 1][jump[i - 1][j]];

	for(int i = 1; i <= n; ++i)
		rep[i] = i;
	getGraph(1, 0);
}

bool dad(int u, int v){
	return pre[u] <= pre[v] && post[v] <= post[u];
}

int lca(int u, int v){
	for(int i = LOGN - 1; i >= 0; --i)
		if(!dad(jump[i][u], v))
			u = jump[i][u];
	
	if(!dad(u, v))
		u = jump[0][u];
	return u;
}

int getHigher(int u, int d){
	for(int i = 0; i < LOGN; ++i)
		if(d & (1 << i))
			u = jump[i][u];
	return u;
}

void consider(int u, int v, int t){
	int m = lca(u, v);
	if(lvl[u] + lvl[v] - 2 * lvl[m] <= k){
		ans[t] = 3;
		return;
	}
	
	int d = lvl[u] + lvl[v] - 2 * lvl[m];
	d /= 2;
	
	if(lvl[u] > lvl[v])
		swap(u, v);
	m = getHigher(v, d);
	
	int who = Find(id[m]);
	req[u].push_back({who, t});
	req[v].push_back({who, -t});
}

int getSizes(int u, int p){
	sz[u] = 1;
	for(auto v: G[u])
		if(!block[v] && v != p)
			sz[u] += getSizes(v, u);
	return sz[u];
}

int centroid(int u){
	int half = getSizes(u, u) / 2;
	bool change = true;
	
	while(change){
		change = false;
		for(auto v: G[u])
			if(!block[v] && sz[v] < sz[u] && sz[v] >= half){
				u = v;
				change = true;
				break;
			}
	}
	
	return u;
}

void go(int u, int p, int d){
	if(spec[u]){
		int t = Find(u);
		colors.push_back(t);
		dists[t] = min(dists[t], d);
	}
	
	for(auto v: G[u])
		if(!block[v] && v != p)
			go(v, u, d + 1);
}

void ask(int u, int p, int d){
	for(auto v: req[u]){
//		printf("%d %d -> %d %d\n", u, d, v.st, v.nd);
		if(d + dists[v.st] > k)
			continue;
		
		if(v.nd < 0)
			ans[-v.nd] |= 2;
		else
			ans[v.nd] |= 1;
	}
	
	for(auto v: G[u])
		if(!block[v] && v != p)
			ask(v, u, d + 1);
}

void Decompose(int u){
	u = centroid(u);
	block[u] = true;
	
	go(u, u, 0);
	ask(u, u, 0);
	
	for(auto c: colors)
		dists[c] = N;
	colors.clear();
	
	for(auto v: G[u])
		if(!block[v])
			Decompose(v);
}

int main(){
	scanf("%d %d %d", &n, &k, &r);
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	for(int i = 1; i <= r; ++i){
		int t;
		scanf("%d", &t);
		spec[t] = true;
	}
	
	prepare();
	scanf("%d", &q);
	for(int i = 1; i <= q; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		consider(u, v, i);
	}
		
	for(int i = 1; i <= n; ++i)
		dists[i] = N;
	
	Decompose(1);
	for(int i = 1; i <= q; ++i)
		puts((ans[i] == 3) ? "YES" : "NO");
	return 0;
}