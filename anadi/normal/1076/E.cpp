#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 3e5 + 7;
const int T = 1 << 19;

const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m;
LL ans[N];
vector <int> G[N];

int rv[N];
int pre[N];
int post[N];
int depth[N];

LL tree[T + T + 7];
vector <PII> quests[N];

void dfs(int u, int p){
	static int Time = 0;
	
	pre[u] = ++Time;
	rv[Time] = u;
	
	for(auto v: G[u]){
		if(v == p)
			continue;

		depth[v] = depth[u] + 1;
		dfs(v, u);
	}
	
	post[u] = Time;
}

void add(int x, int v){
	x += T;
	while(x){
		tree[x] += v;
		x >>= 1;
	}
}

LL ask(int from, int to){
	LL ret = 0;
	from += T, to += T;
	
	while(from < to){
		if(from & 1)
			ret += tree[from];
		if(!(to & 1))
			ret += tree[to];
		
		from = (from + 1) >> 1;
		to = (to - 1) >> 1;
	}
	
	if(from == to)
		ret += tree[from];
	return ret;
}

int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);

	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	depth[1] = 1;
	dfs(1, 0);
	
	scanf("%d", &m);
	for(int i = 1; i <= m; ++i){
		int v, d, x;
		scanf("%d %d %d", &v, &d, &x);
		
		d += depth[v];
		d = min(d, n);
		
		quests[pre[v]].push_back({d, x});
		quests[post[v] + 1].push_back({d, -x});
	}
	
	for(int i = 1; i <= n; ++i){
		for(auto v: quests[i])
			add(v.st, v.nd);
		
		ans[rv[i]] = ask(depth[rv[i]], n);
	}
	
	for(int i = 1; i <= n; ++i)
		printf("%lld ", ans[i]);
	return 0;
}