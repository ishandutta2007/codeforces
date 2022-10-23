#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
string a[1000005];
int vis[1000005],dis[1000005];
const int inf=1e18;
int n,m;
int id(int x,int y)
{
	return (x-1)*m+y;
}
vector<pair<int,int> > e[1000005];
void add(int A,int B,int C,int D,int w)
{
	if(A<=0||A>n||B<=0||B>m) return ;
	if(C<=0||C>n||D<=0||D>m) return ;
	if(a[A][B]=='#'||a[C][D]=='#') return ;
	e[id(A,B)].push_back({id(C,D),w});
}
priority_queue <pair<int,int>,vector <pair<int,int> >,greater <pair<int,int> > > q;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	int X,Y;
	cin >> X >> Y;
	for(int i=0;i<=n+1;i++)
		a[i].resize(m+2);
	for(int i=0;i<=1000000;i++) dis[i]=inf;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin >> a[i][j];
			if(a[i][j]=='.') dis[id(i,j)]=0,q.push({0,id(i,j)}); 
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='L')
			{
				add(i,j-1,i,j+1,Y);
				add(i,j+2,i,j,Y);
				add(i-1,j,i,j+1,X);
				add(i-1,j+1,i,j,X);
				add(i+1,j,i,j+1,X);
				add(i+1,j+1,i,j,X);
			}
			else if(a[i][j]=='U')
			{
				add(i-1,j,i+1,j,Y);
				add(i+2,j,i,j,Y);
				add(i,j+1,i+1,j,X);
				add(i+1,j+1,i,j,X);
				add(i,j-1,i+1,j,X);
				add(i+1,j-1,i,j,X);
			}
		}
	}
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(auto v:e[x])
		{
			if(dis[v.first]>dis[x]+v.second)
			{
				dis[v.first]=dis[x]+v.second;
				q.push({dis[v.first],v.first});
			}
		}
	}
	int ans=inf;
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++) ans=min(ans,dis[id(i,j)]+dis[id(i,j+1)]);
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++) ans=min(ans,dis[id(i,j)]+dis[id(i+1,j)]);
	if(ans>1e17) ans=-1;
	cout << ans;
	return 0;
}