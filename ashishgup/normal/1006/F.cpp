#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=25;

int n, m, k, ans=0;
int a[N][N], type[N][N], vis[N][N], vis2[N][N];
int level[N][N], level2[N][N];
map<int, int> store[N][N], store2[N][N];

void meetinthemiddle()
{
	int len=(n-1+m-1)/2;
	queue<pair<int, int> > q;
	q.push({1, 1});
	level[1][1]=0;
	store[1][1][a[1][1]]=1;
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		if(level[x][y]==len)
			continue;
		if(x+1<=n)
		{
			for(auto it:store[x][y])
				store[x+1][y][it.first^a[x+1][y]]+=it.second;
			if(!vis[x+1][y])
			{
				vis[x+1][y]=1;
				q.push({x+1, y});
			}
			level[x+1][y]=level[x][y]+1;
		}
		if(y+1<=m)
		{
			for(auto it:store[x][y])
				store[x][y+1][it.first^a[x][y+1]]+=it.second;
			if(!vis[x][y+1])
			{
				vis[x][y+1]=1;
				q.push({x, y+1});
			}
			level[x][y+1]=level[x][y]+1;
		}
	}
	int len2=(n-1+m-1)-len-1;
	q.push({n, m});
	level2[n][m]=0;
	store2[n][m][a[n][m]]=1;
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		if(level2[x][y]==len2)
			continue;
		if(x-1>=1)
		{
			for(auto it:store2[x][y])
				store2[x-1][y][it.first^a[x-1][y]]+=it.second;
			if(!vis2[x-1][y])
			{
				vis2[x-1][y]=1;
				q.push({x-1, y});
			}
			level2[x-1][y]=level2[x][y]+1;
		}
		if(y-1>=1)
		{
			for(auto it:store2[x][y])
				store2[x][y-1][it.first^a[x][y-1]]+=it.second;
			if(!vis2[x][y-1])
			{
				vis2[x][y-1]=1;
				q.push({x, y-1});
			}
			level2[x][y-1]=level2[x][y]+1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(level[i][j]==len)
			{
				if(level2[i+1][j]==len2)
				{
					for(auto it:store[i][j])
					{
						int reqd=it.first^k;
						if(store2[i+1][j].find(reqd)!=store2[i+1][j].end())
							ans+=it.second*store2[i+1][j][reqd];
					}
				}
				if(level2[i][j+1]==len2)
				{
					for(auto it:store[i][j])
					{
						int reqd=it.first^k;
						if(store2[i][j+1].find(reqd)!=store2[i][j+1].end())
							ans+=it.second*store2[i][j+1][reqd];
					}
				}
			}
		}
	}
}

int32_t main()
{
	IOS;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	if(n==1 && m==1)
	{
		if(a[1][1]==k)
			cout<<"1";
		else
			cout<<"0";
		return 0;
	}
	meetinthemiddle();
	cout<<ans;
	return 0;
}