#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=3e5+5;

int n, m;
int visited[N], vis[N], recStack[N], in[N];
int cache[N][26];
char a[N];
vector<int> g[N];
int ans=1;

bool isCyclic(int k)
{
	if(!visited[k])
	{
		visited[k]=1;
		recStack[k]=1;
		for(auto it:g[k])
		{
			if(!visited[it] && isCyclic(it))
				return true;
			else if(recStack[it])
				return true;
		}
	}
	recStack[k]=false;
	return false;
}

bool checkCyclic()
{
	memset(visited, 0, sizeof(visited));
	memset(recStack, 0, sizeof(recStack));
	for(int i=1;i<=n;i++)
	{
		if(isCyclic(i))
			return true;
	}
	return false;
}

int dp(int k, char ch)
{
	int &ans=cache[k][ch-'a'];
	if(ans!=-1)
		return ans;
	ans=0;
	if(a[k]==ch)
		ans=1;
	for(auto it:g[k])
	{
		if(a[k]==ch)
			ans=max(ans, 1+dp(it, ch));
		else
			ans=max(ans, dp(it, ch));
	}
	return ans;
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	memset(cache, -1, sizeof(cache));
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		in[v]++;
	}
	if(checkCyclic())
	{
		cout<<"-1";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(!in[i])
		{
			for(char ch='a';ch<='z';ch++)
			{
				ans=max(ans, dp(i, ch));
			}
		}
	}
	cout<<ans;
	return 0;
}