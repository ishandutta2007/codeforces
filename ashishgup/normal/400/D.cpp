#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;
const int M=505;
const int inf=1e9;

int n, m, k, grp=0;
int c[M], vis[N], comp[N];
int d[M][M];
vector<int> g[N];

int get(int x)
{
	auto it=lower_bound(c+1, c+k+1, x) - c;
	return it;
}

void dfs(int u)
{
	if(vis[u])
		return;
	vis[u]=1;
	comp[u]=grp;
	for(auto &it:g[u])
		dfs(it);
}

int32_t main()
{
	IOS;
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		c[i]+=c[i-1];
		for(int j=1;j<=k;j++)
			d[i][j]=inf;
	}
	for(int i=1;i<=m;i++)
	{
		int u, v, x;
		cin>>u>>v>>x;
		int uu=get(u);
		int vv=get(v);
		d[uu][vv]=min(d[uu][vv], x);
		d[vv][uu]=min(d[vv][uu], x);
		if(x==0)
		{
			g[u].push_back(v);
			g[v].push_back(u);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			dfs(i);
			grp++;
		}
	}
	bool check=1;
	for(int i=1;i<=k;i++)
	{
		d[i][i]=0;
		int val=-1;
		for(int j=c[i-1]+1;j<=c[i];j++)
		{
			if(val==-1)
				val=comp[j];
			else 
			{
				if(val!=comp[j])
				{
					check=0;
					break;
				}
			}
		}
	}
	if(!check)
	{
		cout<<"No";
		return 0;
	}
	cout<<"Yes"<<endl;
	for(int mid=1;mid<=k;mid++)
	{
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=k;j++)
			{
				if(d[i][j] > d[i][mid] + d[mid][j])
					d[i][j]=min(d[i][j], d[i][mid]+d[mid][j]);
			}
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(d[i][j]>=inf)
				d[i][j]=-1;
			cout<<d[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}