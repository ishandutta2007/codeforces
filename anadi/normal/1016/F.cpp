#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int T = 1 << 20;

const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, q;
int p[N];
int pod[N];
int dlu[N];

vector <PLL> add;
vector <int> path;
vector <PII> G[N];

int dfs(int u, int par){
	pod[u] = 1;
	for(auto v: G[u]){
		if(v.st == par)
			continue;
		
		p[v.st] = u;
		dlu[v.st] = v.nd;
		pod[u] += dfs(v.st, u);
	}
	
	return pod[u];
}

LL get(int u, int v){
	LL ret = 0;
	while(v != u){
		ret += dlu[v];
		v = p[v];
	}
	
	return ret;
}

int main(){
	scanf("%d %d", &n, &q);
	for(int i = 1; i < n; ++i){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	
	dfs(1, 0);
	int cur = n;
	
	LL l = 0LL;
	path.push_back(cur);

	while(cur != 1){
		l += dlu[cur];
		cur = p[cur];
		path.push_back(cur);
	}
	
	cur = 0;
	bool maybe = false;

	for(auto v: path){
		if(pod[v] - cur > 2)
			maybe = true;
		cur = pod[v];
	}
	
	reverse(path.begin(), path.end());
	path.push_back(0);

	LL mx = -INF, mn = INF;
	for(int i = 0; i + 1 < (int)path.size(); ++i){
		if(i + 3 < (int)path.size())
			mn = min(mn, 1LL * dlu[path[i + 1]] + dlu[path[i + 2]]);
		
		LL d = 0;
		for(auto v: G[path[i]])
			if(v.st != p[path[i]] && v.st != path[i + 1])
				d = v.nd;
		
		if(d == 0)
			continue;
		
		add.push_back({path[i], d});
		if(i + 2 < (int)path.size())
			mx = max(mx, d - dlu[path[i + 1]]);
		if(i > 0)
			mx = max(mx, d - dlu[path[i]]);
	}
	
	for(int i = 0; i + 1 < (int)add.size(); ++i)
		mx = max(mx, add[i].nd + add[i + 1].nd - get(add[i].st, add[i + 1].st));
	
	while(q--){
		int x;
		scanf("%d", &x);
		if(maybe)
			printf("%I64d\n", l);
		else
			printf("%I64d\n", min(l, max(l + mx + x, l + x - mn)));
	}

	return 0;
}