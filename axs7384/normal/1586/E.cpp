#include<bits/stdc++.h>
using namespace std;
int ANS=0;
int n,m,q;
const int N=300005;
vector<int> e[N],ans[N],temp;
int f[N],dep[N],g[N],fa[N],par[N];
inline int getfa(int x)
{
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
inline void dfs(int x,int y)
{
	dep[x]=dep[y]+1;
	par[x]=y;
	for (int z:e[x])
		if (z!=y)
			dfs(z,x);
}
inline void lianbian(int x,int y,int k)
{
	temp.clear();
	while (dep[x]>dep[y])
	{
		ans[k].push_back(x);
		f[x]=!f[x];
		x=par[x];
	}
	while (dep[y]>dep[x])
	{
		temp.push_back(y);
		f[y]=!f[y];
		y=par[y];
	}
	while (x!=y)
	{
		ans[k].push_back(x);
		temp.push_back(y);
		f[x]=!f[x];
		f[y]=!f[y];
		x=par[x];
		y=par[y];
	}
	ans[k].push_back(x);
	reverse(temp.begin(),temp.end());
	for (int z:temp)
		ans[k].push_back(z);
}
// inline void work(int x,int y)
// {
// 	// cout<<x<<' '<<f[x]<<endl;
// 	int sum=0;
// 	for (int z:e[x])
// 		if (z!=y)
// 		{
// 			work(z,x);
// 			if (g[z])
// 				++sum;
// 		}
// 	// cout<<x<<' '<<sum<<endl;
// 	if (f[x])
// 	{
// 		g[x]=1;
// 		ANS+=sum/2;
// 	}
// 	else
// 	{
// 		if (sum%2==0)
// 		{
// 			ANS+=sum/2;
// 		}
// 		else
// 		{
// 			if (x==1)
// 				ANS+=(sum+1)/2;
// 			else
// 			{
// 				g[x]=1;
// 				ANS+=sum/2;
// 			}
// 		}
// 	}
// }
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
		fa[i]=i;
	for (int i=1,u,v;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		int fu=getfa(u),fv=getfa(v);
		if (fu!=fv)
		{
			fa[fu]=fv;
			e[u].push_back(v);
			e[v].push_back(u);
		}
	}
	dfs(1,0);
	scanf("%d",&q);
	for (int i=1,x,y;i<=q;++i)
	{
		scanf("%d%d",&x,&y);
		g[x]=!g[x];
		g[y]=!g[y];
		lianbian(x,y,i);
	}
	// for (int i=1;i<=n;++i)
	// 	if (g[i])
	// 	{
	// 		puts("NO");
	// 		work(1,0);
	// 		cout<<ANS<<endl;
	// 		return 0;
	// 	}
	int sum=0;
	for (int i=1;i<=n;++i)
		sum+=g[i];
	if (sum)
	{
		puts("NO");
		cout<<sum/2<<endl;
		return 0;
	}
	puts("YES");
	for (int i=1;i<=q;++i)
	{
		printf("%d\n",(int)ans[i].size());
		for (int x:ans[i])
			printf("%d ",x);
		puts("");
	}
	return 0;
}