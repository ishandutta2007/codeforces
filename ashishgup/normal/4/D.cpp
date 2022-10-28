#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=5005;

int n;
int w[N], h[N], len[N], vis[N], par[N];

void dfs(int idx)
{
	if(vis[idx])
		return;
	vis[idx]=1;
	for(int i=0;i<=n;i++)
	{
		if(w[idx]<w[i] && h[idx]<h[i])
		{
			dfs(i);
			if(len[i]+1>len[idx])
			{
				len[idx]=len[i]+1;
				par[idx]=i;
			}
		}
	}
}

void path(int idx)
{
	cout<<idx;
	if(par[idx])
	{
		cout<<" ";
		path(par[idx]);
	}
}

int32_t main()
{
	IOS;
	cin>>n>>w[0]>>h[0];
	for(int i=1;i<=n;i++)
		cin>>w[i]>>h[i];
	dfs(0);
	cout<<len[0]<<endl;
	if(len[0])
		path(par[0]);
	return 0;
}