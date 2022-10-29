#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m, s;
int vis[N], vis2[N][2], par[N][2];
vector<int> g[N];

bool findLoop(int v) 
{
	if(vis[v]==1)
		return 1;
	if(vis[v]==2)
		return 0;
	vis[v]=1;
	for(auto &it:g[v])
	{
		if(findLoop(it))
			return 1;
	}
	vis[v]=2;
	return 0;
}

int dfs(int k, int col)
{
	vis2[k][col]=1;
	if(g[k].size()==0)
	{
		if(col==1)
			return k;
		return 0;
	}
	for(auto &it:g[k])
	{
		if(!vis2[it][col^1])
		{
			par[it][col^1]=k;
			int nxt=dfs(it, col^1);
			if(nxt>0)
				return nxt;
		}
	}
	return 0;
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int cur;
		cin>>cur;
		for(int j=1;j<=cur;j++)
		{
			int v;
			cin>>v;
			g[i].push_back(v);
		}
	}	
	cin>>s;
	int last=dfs(s, 0);
	if(last>0)
	{
		vector<int> path;
		path.push_back(last);
		int cur=last, col=1;
		do
		{
			cur=par[cur][col];
			col^=1;
			path.push_back(cur);
		}while(!(cur==s && col==0));
		cout<<"Win"<<endl;
		reverse(path.begin(), path.end());
		for(auto &it:path)
			cout<<it<<" ";
	}
	else if(findLoop(s))
		cout<<"Draw";
	else
		cout<<"Lose";
	return 0;
}