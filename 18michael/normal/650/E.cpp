#include<bits/stdc++.h>
using namespace std;
int n,ans;
int fa[500002],fa1[500002],dep[500002],rt[500002];
struct aaa
{
	vector<int> vec[500002];
	inline void add_e(int x,int y)
	{
		vec[x].push_back(y),vec[y].push_back(x);
	}
}a[2];
inline void getroot(int x)
{
	if(rt[x]==x)return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
inline void dfs(int x,int f)
{
	fa[x]=f;
	for(int i=0,v;i<a[1].vec[x].size();++i)
		if((v=a[1].vec[x][i])!=f)
			dfs(v,x);
}
inline void dfs1(int x,int f,int d)
{
	fa1[x]=f,dep[x]=d;
	for(int i=0,v;i<a[0].vec[x].size();++i)
		if((v=a[0].vec[x][i])!=f)
			dfs1(v,x,d+1);
}
inline void dfs2(int x,int f)
{
	for(int i=0,v;i<a[0].vec[x].size();++i)
		if((v=a[0].vec[x][i])!=f)
		{
			getroot(x),getroot(v);
			if(rt[x]^rt[v])dfs2(v,x);
		}
	for(int i=0,v;i<a[0].vec[x].size();++i)
		if((v=a[0].vec[x][i])!=f)
		{
			getroot(x),getroot(v);
			if(rt[x]==rt[v])dfs2(v,x);
		}
	if(f)
	{
		getroot(x),getroot(fa[x]);
		if(rt[x]^rt[fa[x]])printf("%d %d %d %d\n",rt[x],fa1[rt[x]],x,fa[x]),rt[rt[x]]=rt[fa[x]];
	}
}
int main()
{
	scanf("%d",&n),ans=n-1;
	for(int i=1;i<=n;++i)rt[i]=i;
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),a[0].add_e(x,y);
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),a[1].add_e(x,y);
	dfs(1,0),dfs1(1,0,1);
	for(int i=1;i<=n;++i)
	{
		sort(a[0].vec[i].begin(),a[0].vec[i].end()),sort(a[1].vec[i].begin(),a[1].vec[i].end());
		for(int j=0,k=0;j<a[0].vec[i].size();++j)
		{
			if(dep[a[0].vec[i][j]]>dep[i])continue;
			while(k<a[1].vec[i].size() && a[1].vec[i][k]<a[0].vec[i][j])++k;
			if(k<a[1].vec[i].size() && a[1].vec[i][k]==a[0].vec[i][j])getroot(i),getroot(a[0].vec[i][j]),rt[rt[i]]=rt[a[0].vec[i][j]],--ans;
		}
	}
	printf("%d\n",ans),dfs2(1,0);
	return 0;
}