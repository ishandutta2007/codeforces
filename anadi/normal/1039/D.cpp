#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
int cnt;
int res[N];
vector <int> G[N];

int nr[N];
int pre[N];
int Left[N];

void dfs(int u, int p){
	pre[++cnt] = u;
	nr[u] = cnt;

	for(int v: G[u])
		if(v != p)
			dfs(v, u);
}

int solve(int d){
	int res = 0;
	for(int i = n; i >= 1; --i){
		int mx = 1, mx2 = 1;
		for(int v: G[pre[i]]){
			if(nr[v] < nr[pre[i]])
				continue;
			
			++Left[v];
			if(Left[v] > mx){
				mx2 = mx;
				mx = Left[v];
			}
			else if(Left[v] > mx2)
				mx2 = Left[v];
		}
		
		if(mx + mx2 > d){
			Left[pre[i]] = 0;
			++res;
		}
		else
			Left[pre[i]] = mx;
	}
	
	return res;
}

void go(int p, int k, int from, int to){
	if(k < p)
		return;

	if(from == to){
		for(int i = p; i <= k; ++i)
			res[i] = from;
		return;
	}
	
	int m = (p + k) >> 1;
	res[m] = solve(m);
	
	go(p, m - 1, res[m], to);
	go(m + 1, k, from, res[m]);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs(1, 1);
	go(1, n, 0, n);

	for(int i = 1; i <= n; ++i)
		printf("%d\n", res[i]);
	return 0;
}