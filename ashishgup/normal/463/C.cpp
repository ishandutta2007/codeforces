#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2005;

int n, curmax, storex, storey;
int a[N][N], contrib[N][N], vis[N][N];
int d1[2*N], d2[2*N];
vector<pair<int, pair<int, int> > > v;
int dx[4]={+1, +1, -1, -1};
int dy[4]={+1, -1, +1, -1};

void dfs(int x, int y)
{
	if(x<1 || y<1 || x>n || y>n)
		return;
	if(vis[x][y])
		return;
	vis[x][y]=1;
	if(contrib[x][y]>curmax)
	{
		curmax=contrib[x][y];
		storex=x;
		storey=y;
	}	
	for(int k=0;k<4;k++)
		dfs(x+dx[k], y+dy[k]);
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			d1[j-i+n]+=a[i][j];
			d2[i+j]+=a[i][j];
		}
	}	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			contrib[i][j]=d1[j-i+n] + d2[i+j] - a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(!vis[i][j])
			{
				curmax=-1;
				dfs(i, j);
				v.push_back({curmax, {storex, storey}});
			}
		}
	}
	sort(v.rbegin(), v.rend());
	cout<<v[0].first+v[1].first<<endl;
	cout<<v[0].second.first<<" "<<v[0].second.second<<" "<<v[1].second.first<<" "<<v[1].second.second;
}