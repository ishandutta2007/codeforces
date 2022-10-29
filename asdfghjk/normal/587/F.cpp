#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
const int N=200005;
struct node
{
	int i,j,k,id;
}g[N],h[N];
int n,Q,i,j,k,x,y,cnt,tot,num,head[N],adj[N],nxt[N],ch[N][26],pt[N],q[N],bg,ed,fail[N],id[N],size[N],fa[N],son[N],tp[N],tk;
string s[N];
long long ans[N],w,c[N],dzx[N];
bool cmp(node a,node b)
{
	return a.i<b.i;
}
void dfs(int x)
{
	size[x]=1;
	for(int y=head[x];y;y=nxt[y])
	{
		fa[adj[y]]=x;
		dfs(adj[y]);
		size[x]+=size[adj[y]];
		if(!son[x]||size[adj[y]]>size[son[x]])
			son[x]=adj[y];
	}
}
void Dfs(int x)
{
	id[x]=++i;
	if(son[x])
	{
		tp[son[x]]=tp[x];
		Dfs(son[x]);
	}
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=son[x])
		{
			tp[adj[y]]=adj[y];
			Dfs(adj[y]);
		}
}
void add(int x,int y)
{
	while(x<=cnt+1)
	{
		c[x]+=y;
		x+=x&-x;
	}
}
long long sum(int x)
{
	long long rtn=0;
	while(x)
	{
		rtn+=c[x];
		x-=x&-x;
	}
	return rtn;
}
void work(int x)
{
	for(int y=head[x];y;y=nxt[y])
	{
		work(adj[y]);
		dzx[x]+=dzx[adj[y]];
	}
}
int main()
{
	cin>>n>>Q;
	for(i=1;i<=n;++i)
	{
		cin>>s[i];
		for(j=k=0;s[i][j];++j)
		{
			if(!ch[k][s[i][j]-'a'])
				ch[k][s[i][j]-'a']=++cnt;
			k=ch[k][s[i][j]-'a'];
		}
		tk+=j;
		pt[i]=k;
	}
	tk=min(tk,200);
	bg=1;
	for(i=0;i<26;++i)
		if(ch[0][i])
			q[++ed]=ch[0][i];
	while(bg<=ed)
	{
		for(i=0;i<26;++i)
			if(ch[q[bg]][i])
			{
				q[++ed]=ch[q[bg]][i];
				fail[q[ed]]=ch[fail[q[bg]]][i];
			}
			else
				ch[q[bg]][i]=ch[fail[q[bg]]][i];
		++bg;
	}
	for(i=1;i<=cnt;++i)
	{
		adj[i]=i+1;
		nxt[i]=head[fail[i]+1];
		head[fail[i]+1]=i;
	}
	dfs(1);
	tp[1]=1;
	i=0;
	Dfs(1);
	tot=0;
	for(i=1;i<=Q;++i)
	{
		cin>>j>>k>>x;
		if(s[x].size()<=tk)
		{
			if(j-1>0)
				g[++tot]=(node){j-1,x,-1,i};
			g[++tot]=(node){k,x,1,i};
		}
		else
			h[++num]=(node){j,k,x,i};
	}
	for(i=1;i<=n;++i)
	if(s[i].size()>tk)
	{
		for(j=1;j<=cnt+1;++j)
			dzx[j]=0;
		for(j=k=0;s[i][j];++j)
		{
			k=ch[k][s[i][j]-'a'];
			dzx[k+1]++;
		}
		work(1);
		for(j=1;j<=n;++j)
			c[j]=c[j-1]+dzx[pt[j]+1];
		for(j=1;j<=num;++j)
			if(h[j].k==i)
				ans[h[j].id]+=c[h[j].j]-c[h[j].i-1];
	}
	sort(g+1,g+1+tot,cmp);
	for(i=1;i<=n;++i)
		c[i]=0;
	for(i=1,x=1;i<=n;++i)
	{
		add(id[pt[i]+1],1);
		while(x<=tot&&g[x].i==i)
		{
			w=0;
			for(k=y=0;s[g[x].j][k];++k)
			{
				y=ch[y][s[g[x].j][k]-'a'];
				j=y+1;
				while(j)
				{
					w+=sum(id[j])-sum(id[tp[j]]-1);
					j=fa[tp[j]];
				}
			}
			ans[g[x].id]+=w*g[x].k;
			++x;
		}
	}
	for(i=1;i<=Q;++i)
		cout<<ans[i]<<endl;
	return 0;
}