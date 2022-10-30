#include <cstdio>
#include <vector> 
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;
vector < int > g[100005];
int values[100005];
#define ll long long
ll dp[100005][2];


bool used[100005];

void dfs(int v)
{
	vector < ll > ms, ps;
	used[v]=1;

	for(int i=0;i<g[v].size();i++)
	{
		if(used[g[v][i]])
			continue;
		dfs(g[v][i]);
		ms.push_back(dp[g[v][i]][0]);
		ps.push_back(dp[g[v][i]][1]);
	}

	ll curr_m = 0;
	ll curr_p = 0;
	
	ll last = 0;
	sort(ms.begin(),ms.end());
	sort(ps.begin(),ps.end());
	for(int i=0;i<ms.size();i++)
	{
		curr_m+=ms[i];
		if(i)
			curr_m-=ms[i-1];

		curr_p+=ps[i];
		if(i)
			curr_p-=ps[i-1];
	}

	ll curr = curr_p+values[v]-curr_m;
	if(curr<0)
	{
		curr_p+=-curr;
	}
	else
	{
		curr_m+=curr;
	}

	dp[v][0] = curr_m;
	dp[v][1] = curr_p;
}


int main()
{
	int n;
	scanf("%d", &n);

	for(int i=0;i<n-1;i++)
	{
		int a, b;
		scanf("%d %d",&a,&b);
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i=0;i<n;i++)
		scanf("%d",&values[i]);

	dfs(0);

	cout << dp[0][0] + dp[0][1];

	return 0;
}