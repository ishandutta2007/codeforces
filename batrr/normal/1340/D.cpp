#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = 1000100;
 
vector< int > g[N];
int n, m, k;
pii ans[N];
void dfs(int v, int p, int s){
	ans[k++] = {v, s};
	if(s == 0){
		for(auto to : g[v]){
			if(to == p)
				continue;
			dfs(to, v, ++s);	
			ans[k++] = {v, s};
		}
		return;
	}
	int sz = g[v].size() - 1, cur = s;
	bool fl = 0;
	if(cur == m){
		fl = 1;							
		ans[k++] = {v, s - 1 - sz}; 
		cur = s - 1 - sz;
	}
	for(auto to : g[v]){
		if(to == p)
			continue;
		sz--;
		dfs(to, v, ++cur);	
		ans[k++] = {v, cur};
		if(cur == m){
			fl = 1;							
			ans[k++] = {v, s - 1 - sz}; 
			cur = s - 1 - sz;
		}
	}
	if(!fl)
		ans[k++] = {v, s - 1 - sz};
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].pb(u);
		g[u].pb(v);
	}
	for(int i = 1; i <= n; i++)
		m = max(m, (int)g[i].size());
	dfs(1, 1, 0);
	printf("%d\n", k);
	for(int i = 0; i < k; i++)
		printf("%d %d\n", ans[i].f, ans[i].s);
}