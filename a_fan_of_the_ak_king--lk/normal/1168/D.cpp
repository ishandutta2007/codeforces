#include<bits/stdc++.h>
using namespace std;
int n,q,p[200005],i,f[200005][26],fa[200005],d[200005],bot[200005],k;
int md,x,tree[200005][26],de[200005],num,cnt[200005];
int head[200005],Next[400005],adj[400005],s[200005];
char c[200005],ch;
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
void dfs(int i,int dep)
{
	int j;
	if(d[i]==0)
		if(md==0)
			md=dep;
		else
			if(md!=dep)
			{
				for(i=1;i<=q;++i)
					puts("Fou");
				exit(0);
			}
	if(d[i]==2||d[i]==0)
		bot[i]=i;
	if(d[p[i]]!=1||p[i]==1)
		fa[i]=p[i];
	else
		fa[i]=fa[p[i]];
	for(j=head[i];j!=0;j=Next[j])
	{
		dfs(adj[j],dep+1);
		de[i]=max(de[i],de[adj[j]]+1);
		if(d[i]==1)
			bot[i]=bot[adj[j]];
	}
}
void Update(int x,int y)
{
	int i,j,k;
	for(i=x;i!=0;i=fa[i])
	{
		if(cnt[i]==1)
			--num;
		s[i]-=tree[i][y];
		tree[i][y]=0;
		for(j=head[i];j!=0;j=Next[j])
			tree[i][y]=max(tree[i][y],tree[bot[adj[j]]][y]+f[bot[adj[j]]][y]);
		s[i]+=tree[i][y];
		if(s[i]>de[i])
		{
			++num;
			cnt[i]=1;
		}
		else
			cnt[i]=0;
	}
}
int main()
{
	scanf("%d %d",&n,&q);
	for(i=2;i<=n;++i)
	{
		scanf("%d %c",&p[i],&c[i]);
		++d[p[i]];
		Push(p[i],i);
	}
	dfs(1,0);
	for(i=2;i<=n;++i)
		if(c[i]!='?')
		{
			++f[bot[i]][c[i]-'a'];
			Update(fa[i],c[i]-'a');
		}
	while(q--)
	{
		scanf("%d %c",&x,&ch);
		if(c[x]!='?')
		{
			--f[bot[x]][c[x]-'a'];
			Update(fa[x],c[x]-'a');
		}
		c[x]=ch;
		if(c[x]!='?')
		{
			++f[bot[x]][c[x]-'a'];
			Update(fa[x],c[x]-'a');
		}
		if(num==0)
		{
			long long ans=0,s=0;
			for(i=0;i<26;++i)
				s+=tree[1][i];
			s=de[1]-s;
			for(i=0;i<26;++i)
				ans+=(i+1)*(s+tree[1][i]);
			printf("Shi %lld\n",ans);
		}
		else
			puts("Fou");
	}
}