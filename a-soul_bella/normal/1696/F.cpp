#include <bits/stdc++.h>
#define int long long
using namespace std;
int d[105][105][105],p[105],n;
vector<pair<int,int> > e;
struct dsu
{
	int fa[105];
	inline void init()
	{
		for(int i=0;i<=n;i++) fa[i]=i;
	}
	inline int ff(int x)
	{
		if(fa[x]==x) return x;
		return fa[x]=ff(fa[x]);
	}
	inline void mer(int x,int y)
	{
		fa[ff(x)]=ff(y);
	}
	inline int cnt()
	{
		int rtn=0;
		for(int i=1;i<=n;i++) rtn+=fa[i]==i;
		return rtn;
	}
}D;
inline void solve(vector <int> v)
{
	if(v.size()==1) return ;
	if(v.size()==2)
	{
		e.push_back({v[0],v[1]});
		return ;
	}
	for(auto t:v) p[t]=0;
	int mx=-1;
	for(auto t:v)
	{
		D.init();
		for(auto x:v)
			for(auto y:v)
				if(d[x][y][t]) D.mer(x,y);
		p[t]=D.cnt();
		mx=max(mx,p[t]);
	}
	int x=0;
	for(auto t:v)
	{
		if(p[t]==mx)
		{
			p[t]=1,x=t;
		}
		else p[t]=0;
	}
	for(auto t:v)
	{
		if(p[t]) continue;
		int flag=1;
		for(auto A:v)
		{
			if(A==x||A==t) continue;
			for(auto B:v)
			{
				if(B==A) break;
				if(B==x||B==t) continue;
				if(d[A][B][x]!=d[A][B][t]) flag=0;
			}
		}
		if(flag)
		{
			e.push_back({x,t});
			v.erase(lower_bound(v.begin(),v.end(),x));
			solve(v);
			return ;
		}
	}
}
namespace check
{
	int dis[105][105];
	inline void init()
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j) dis[i][j]=1000;
				else dis[i][j]=0;
			}
		}
	}
	inline bool solve()
	{
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					if((dis[i][k]==dis[j][k])!=d[i][j][k]) return 0;
				}
			}
		}
		return 1;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		e.clear();
		cin >> n;
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<=n-i;j++)
			{
				string s;
				cin >> s;
				s=' '+s;
				for(int k=1;k<=n;k++)
				{
					if(s[k]=='1') d[i][i+j][k]=d[i+j][i][k]=1;
					else d[i][i+j][k]=d[i+j][i][k]=0;
				}
			}
		}
		vector <int> v;
		for(int i=1;i<=n;i++) v.push_back(i);
		solve(v);
		check::init();
		for(auto t:e)
			check::dis[t.first][t.second]=check::dis[t.second][t.first]=1;
		if(check::solve())
		{
			cout << "Yes\n";
			for(auto t:e) cout << t.first << " " << t.second << "\n";
		}
		else cout << "No\n";
	}
	return 0;
}