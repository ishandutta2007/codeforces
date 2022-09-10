#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 2e5 + 7;
const int M = (1 << 20) + 7;

const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n, cur;
int type[N];
int pref[N];

LL res[N];
char s[N];
int pod[N];
bool block[N];

int sum[M];
vector <int> who;
vector <int> G[N];

int dfs(int u, int p){
	pod[u] = 1;
	for(int v: G[u])
		if(v != p && !block[v])
			pod[u] += dfs(v, u);
	return pod[u];
}

int centroid(int u){
	int p = u;
	int half = (dfs(u, u) + 1) / 2;
	
	bool change = true;
	while(change){
		change = false;
		for(int v: G[u])
			if(!block[v] && v != p && pod[v] >= half){
				p = u;
				u = v;

				change = true;
				break;
			}
	}
	
	return u;
}

void get(int u, int p, int mask){
	mask ^= 1 << type[u];
	for(int i = 0; i < 20; ++i)
		pref[u] += sum[mask ^ (1 << i)];
	pref[u] += sum[mask];
	
	for(int v: G[u])
		if(!block[v] && v != p)
			get(v, u, mask);
}

void add(int u, int p, int mask){
	mask ^= 1 << type[u];
	
	if(sum[mask] == 0)
		who.pb(mask);
	sum[mask]++;
	
	for(int v: G[u])
		if(!block[v] && v != p)
			add(v, u, mask);
}

LL licz(int u, int p){
	LL ret = pref[u];
	for(int v: G[u])
		if(!block[v] && v != p)
			ret += licz(v, u);
	
	res[u] += ret; pref[u] = 0;
	return ret;
}

int last(int u, int p, int mask){
	int ret = 0;
	mask ^= 1 << type[u];
	
	if(__builtin_popcount(mask) < 2)
		ret = 1;
	
	for(int v: G[u])
		if(v != p && !block[v])
			ret += last(v, u, mask);
	
	res[u] += ret;
	return ret;
}

void czysc(){
	for(int v: who)
		sum[v] = 0;
	who.clear();
}

void Rozbicie(int u){
	u = centroid(u);
	block[u] = true;
	
	cur = u;
	pref[u] = 1;

	czysc();
	for(int v: G[u])
		if(!block[v]){
			get(v, v, 0);
			add(v, v, 1 << type[u]);
		}
	
	czysc();
	reverse(G[u].begin(), G[u].end());
	
	for(int v: G[u])
		if(!block[v]){
			get(v, v, 0);
			add(v, v, 1 << type[u]);
		}
	
	LL t = res[u];
	licz(u, u);

	res[u] = (res[u] - t) / 2LL + t;
	last(u, u, 0);

	for(int v: G[u])
		if(!block[v])
			Rozbicie(v);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d %d", &u, &v);

		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	scanf("%s", s + 1);
	for(int i = 1; i <= n; ++i)
		type[i] = s[i] - 'a';
	
	Rozbicie(1);
	for(int i = 1; i <= n; ++i)
		printf("%lld ", res[i]);
	return 0;
}