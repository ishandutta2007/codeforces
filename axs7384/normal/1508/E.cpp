#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=300005;
int a[N],p[N],g[N],s[N],h[N];
int x,y,n,ti;
ll ans;
vector<int> e[N]; 
inline bool cmp(int x,int y)
{
	return a[x]<a[y];
}
inline void dfs(int x,int y)
{
	// cout<<x<<" ? "<<y<<endl;
	// puts("?");
	int p=-1;
	for (int i=0;i<(int)e[x].size();++i)
		if (e[x][i]!=y)
		{
			h[e[x][i]]=h[x]+1;
			dfs(e[x][i],x);
		}
		else
			p=i;
	// cout<<"?"<<x<<' '<<y<<' '<<p<<endl;
	if (x!=1)
		e[x].erase(e[x].begin()+p);
	if (e[x].size())
		sort(e[x].begin(),e[x].end(),cmp);
}
inline void sufdfs(int x)
{
	// cout<<x<<endl;
	// puts("!");
	for (int i=0;i<e[x].size();++i)
		sufdfs(e[x][i]);
	s[x]=++ti;
}
inline void predfs(int x)
{
	// puts(".");
	if (s[x]<a[1])
		return;
	p[x]=++ti;
	for (int i=0;i<(int)e[x].size();++i)
		predfs(e[x][i]);
}
inline void redfs(int x)
{
	// puts(",");
	p[x]=++ti;
	for (int i=0;i<(int)e[x].size();++i)
		redfs(e[x][i]);
}
inline void modifydfs(int x)
{
	// cout<<'?'<<x<<endl;
	for (int i=0;i<(int)e[x].size();++i)
		if (a[x]<a[e[x][i]])
		{
			// cout<<x<<' '<<a[i]<<" / "<<e[x][i]<<' '<<a[e[x][i]]<<endl;
			swap(a[x],a[e[x][i]]);
			modifydfs(e[x][i]);
			break;
		}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for (int i=1;i<n;++i)
	{
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1,0);
	sufdfs(1);
	ti=0;
	predfs(1);
	ti=0;
	for (int i=1;i<=n;++i)
		if (a[i]<a[1])
			ans+=h[i];
	for (int i=1;i<=n;++i)
		if (s[i]<a[1])
			g[i]=s[i];
		else
			g[i]=p[i]+a[1]-1;
	for (int i=1;i<=n;++i)
		if (a[i]==a[1]-1)
		{
			modifydfs(i);
			break;
		}
	// redfs(1);
	// ti=0;
	// for (int i=1;i<=n;++i)
	// 	cout<<i<<' '<<a[i]<<' '<<g[i]<<' '<<p[i]<<endl;
	for (int i=1;i<=n;++i)
		if (a[i]!=g[i])
		{
			puts("NO");
			return 0;
		}
	puts("YES");
	printf("%lld\n",ans);
	redfs(1);
	for (int i=1;i<=n;++i)
		printf("%d ",p[i]);
	return 0;
}