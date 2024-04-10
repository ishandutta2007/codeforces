#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = 1010;
 
vector< int > g[N * N], G[N * N];
char s[N];
int n, m, q, k, sz[N * N], p[N * N], d[N * N];
bool a[N * N], was[N * N];

void dfs(int v){
	if(was[v])
		return;
	was[v] = 1;
	p[v] = k;
	sz[k]++;
	for(auto to : g[v])
		if(a[v] == a[to])
        	dfs(to);
}
int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 0; i < n; i++){
		scanf("%s", s);
		for(int j = 0; j < m; j++)
			a[i * m + j] = s[j] - '0';
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(i + 1 < n)
				g[i * m + j].pb((i + 1) * m + j);
			if(i - 1 >= 0)
				g[i * m + j].pb((i - 1) * m + j);
			if(j + 1 < m)
				g[i * m + j].pb(i * m + j + 1);
			if(j - 1 >= 0)
				g[i * m + j].pb(i * m + j - 1);
		}
	}
	for(int i = 0; i < n * m; i++)
		if(!was[i]){
			dfs(i);
			k++;
		}
	for(int i = 0; i < n * m; i++)
		for(auto j : g[i])
			if(p[i] != p[j])
				G[p[i]].pb(p[j]);
	
	{
  		queue < int > q;
		for(int i = 0; i < k; i++)
			if(sz[i] > 1){
				d[i] = 1;
				q.push(i);
			}
		while(!q.empty()){
			int v = q.front();
			q.pop();
			for(auto to : G[v])
				if(d[to] == 0){
					d[to] = d[v] + 1;
					q.push(to);
				}
		}
	}
	while(q--){
		int x, y;
		ll z;
		scanf("%d%d%lld", &x, &y, &z);
		--x, --y;
		int v = p[x * m + y];
		ll res = a[x * m + y];
		if(d[v] == 0)
       		z = 0;
       	else
       		z = max(0ll, z - d[v] + 1);
	    res += z; 
		printf("%lld\n", res & 1);
	}
}