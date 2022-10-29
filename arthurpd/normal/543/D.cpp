//http://codeforces.com/contest/543/problem/D

#include <stdio.h>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> graph[212345];
vector<int> tab[212345];
vector<int> pa[212345];
const long long mod = 1000000007;
typedef long long ll;
ll tot[212345];


ll sq(ll x){return x*x; }

ll pot(ll b, ll e)
{
	if(e == 0)
		return 1LL;
	if(e & 1)
		return (b * pot(b, e-1)) % mod;
	else
		return sq(pot(b, e/2)) % mod;
}

ll inv(ll x)
{
	return pot(x, mod - 2);
}

ll pd(int a, int p)
{
	if(graph[a].size() == 1)
		return 2;
	ll retv = 1;
	if(tab[a][p])
		return tab[a][p];
	if(tot[a])
		retv = (tot[a] * inv(pd(graph[a][p], pa[a][p]))) % mod;
	else
	for(int i = 0; i < graph[a].size(); i++)
		if(i != p)
			retv = (retv * (pd(graph[a][i], pa[a][i]))) % mod;
	return tab[a][p] = retv + 1;
}

void dfs(int a, int p)
{
	tot[a] = 1;
	for(int i = 0; i < graph[a].size(); i++)
		tot[a] = (tot[a] * pd(graph[a][i], pa[a][i]) ) % mod;
	
	for(int i = 0; i < graph[a].size(); i++)
		if(i != p)
			dfs(graph[a][i], pa[a][i]);
}

int
main(void)
{
	int n, a;
	scanf("%d", &n);
	for(int i = 2; i <= n; i++)
	{
		scanf("%d", &a);
		graph[a].push_back(i); tab[a].push_back(0); 
		graph[i].push_back(a); tab[a].push_back(0);
		
		pa[a].push_back(graph[i].size() - 1);
		pa[i].push_back(graph[a].size() - 1);
		
	}
	dfs(1, -1);
	for(int i = 1; i <= n; i++)
	{
		long long ans = 1;
		for(int j = 0; j < graph[i].size(); j++)
			ans = (ans * (pd(graph[i][j], pa[i][j]))) % mod;
		cout << ans << endl;
	}
}