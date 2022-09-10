#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PII pair <int, int>

const int N = 3e5 + 7;
const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n, m;
int dad[N];
bool vis[N];
int level[N];
vector <int> G[N];

int nast[N];
long long int pref[N];

PII find(int u, int v){
	PII ret = {v, v};
	while(u != v){
		ret.st = max(ret.st, u);
		ret.nd = min(ret.nd, u);
		u = dad[u];
	}
	
	return ret;
}

void dfs(int u){
	vis[u] = true;
	for(int v: G[u])
		if(!vis[v]){
			dad[v] = u;
			level[v] = level[u] + 1;
			dfs(v);
		}
		else if(v != dad[u] && level[v] < level[u]){
			PII val = find(u, v);
			nast[val.nd] = val.st - 1;
		}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		nast[i] = n;
	
	for(int i = 1; i <= m; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	for(int i = 1; i <= n; ++i)
		if(!vis[i]){
			dad[i] = i;
			dfs(i);
		}

	for(int i = n - 1; i >= 1; --i)
		nast[i] = min(nast[i], nast[i + 1]);
	
	for(int i = 1; i <= n; ++i)
		pref[i] = pref[i - 1] + nast[i] - i + 1;
	
	int q;
	scanf("%d", &q);
	while(q--){
		int l, r;
		scanf("%d %d", &l, &r);
		int p = l - 1, k = r;
		while(p < k){
			int m = (p + k + 1) / 2;
			if(r < nast[m])
				k = m - 1;
			else
				p = m;
		}
		
		printf("%lld\n", pref[k] - pref[l - 1] + 1LL * (r - k) * (r - k + 1) / 2LL);
	}

	return 0;
}