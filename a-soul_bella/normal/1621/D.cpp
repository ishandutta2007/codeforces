#include <bits/stdc++.h>
#define int long long
using namespace std;
int dis[250005],a[250005],n,vis[250005];
vector <int> e[250005];
inline int id(int x,int y)
{
	return (x-1)*n+y;
}
inline void add(int x,int y)
{
	e[x].push_back(y);
	e[y].push_back(x);
}
priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n;
		n*=2;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				cin >> a[id(i,j)];
		}
		for(int i=1;i<=n/2;i++) for(int j=1;j<=n/2;j++) a[id(i,j)]=1e18;
		for(int i=1;i<=n*n;i++) e[i].clear(),vis[i]=0,dis[i]=1e18;
		for(int i=1;i<=n;i++)
			for(int j=2;j<=n;j++) add(id(i,j),id(i,j-1));
		for(int i=1;i<=n;i++) add(id(i,1),id(i,n));
		for(int i=2;i<=n;i++)
			for(int j=1;j<=n;j++) add(id(i,j),id(i-1,j));
		for(int i=1;i<=n;i++) add(id(1,i),id(n,i));
		int ans=0;
		for(int i=n/2+1;i<=n;i++)
			for(int j=n/2+1;j<=n;j++)
				ans+=a[id(i,j)],a[id(i,j)]=1e18;
		vector <int> v;
		v.push_back(id(n/2,n/2));
		v.push_back(id(n/2+1,n/2+1));
		v.push_back(id(n/2,1));
		v.push_back(id(1,n/2));
		v.push_back(id(n,n/2+1));
		v.push_back(id(n/2+1,n));
		v.push_back(id(1,1));
		v.push_back(id(n,n));
		for(auto t:v) a[t]=0;
		for(auto t:v)
			if(t<=id(n/2,n/2)) dis[t]=0,q.push({0,t});
		while(!q.empty())
		{
			int x=q.top().second;
			q.pop();
			if(vis[x]) continue;
			vis[x]=1;
			for(auto v:e[x])
			{
				if(dis[v]>dis[x]+a[v])
				{
					dis[v]=dis[x]+a[v];
					q.push({dis[v],v});
				}
			}
		}
		int mn=1e18;
		for(int i=n/2+1;i<=n;i++)
			for(int j=n/2+1;j<=n;j++)
				mn=min(mn,dis[id(i,j)]);
		cout << ans+mn << "\n";
	}
	return 0;
}