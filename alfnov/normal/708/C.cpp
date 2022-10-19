#include<bits/stdc++.h>
using namespace std;
vector<int>g[400005],w[400005];
int sz[400005],bf[400005],fb[400005],fa[400005];
int n,ans[400005],q[400005];
void dfs1(int x,int la)
{
	sz[x]=1;
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		if(cu==la)
		{
			bf[x]=i;
			continue;
		}
		fb[cu]=i;
		dfs1(cu,x);
		fa[cu]=x,sz[x]+=sz[cu];
	}
}
void dfs2(int x,int la)
{
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		if(cu==la)continue;
		dfs2(cu,x);
	}
	if(x==1)return;
	if(sz[x]*2<=n)
	{
		w[x][bf[x]]=0;
		return;
	}
	int ans=INT_MAX;
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		if(cu==la)continue;
		int aa=sz[x]-sz[cu];
		if(sz[cu]*2>n)aa+=w[cu][bf[cu]];
		ans=min(ans,aa);
	}
	w[x][bf[x]]=ans;
}
void dfs3(int x,int la)
{
	if(sz[x]==1)return;
	int mx=1000000000,tot=0;
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		if(cu==la)
		{
			int aa=0;
			if((n-sz[x])*2>n)aa+=w[cu][fb[x]];
			for(int j=0;j<g[x].size();j++)
			{
				int c=g[x][j];
				if(c==la)continue;
				w[x][j]=aa+sz[x]-sz[c];
			}
		}else
		{
			int aa=-sz[cu];
			if(sz[cu]*2>n)aa+=w[cu][bf[cu]];
			q[++tot]=aa;
		}
	}
	sort(q+1,q+tot+1);
	if(tot!=1)
	{
		for(int i=0;i<g[x].size();i++)
		{
			int cu=g[x][i];
			if(cu==la)continue;
			int aa=-sz[cu];
			if(sz[cu]*2>n)aa+=w[cu][bf[cu]];
			if(q[1]==aa)aa=q[2]+(n-sz[cu]);
			else aa=q[1]+(n-sz[cu]);
			w[x][i]=min(w[x][i],aa);
		}
	}
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		if(cu==la)continue;
		dfs3(cu,x);
	}
}
int qwq(int x,int i)
{
	int y=g[x][i];
	if(fa[x]==y)return w[y][fb[x]];
	return w[y][bf[y]];
}
int main()
{	
	int T=1;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			g[i].clear(),w[i].clear();
			ans[i]=fa[i]=sz[i]=0;
			bf[i]=fb[i]=-1;
		}
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int aa=0;
		for(int i=1;i<=n;i++)for(int j=0;j<g[i].size();j++)
			w[i].push_back(1000000000);
		if(n==2)
		{
			printf("1 1\n");
			continue;
		}
		dfs1(1,0);
		dfs2(1,0);
		dfs3(1,0);
		for(int i=1;i<=n;i++)
		{
			int mx=-1,ww=-1;
			for(int j=0;j<g[i].size();j++)
			{
				int cu=g[i][j],dd=sz[cu];
				if(cu==fa[i])dd=n-sz[i];
				if(mx<dd)mx=dd,ww=j;
			}
			if(mx*2<=n||qwq(i,ww)*2<=n)putchar('1');
			else putchar('0');
			if(i!=n)putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}