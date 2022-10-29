#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
const int N=400005;
vector<int> vct[N];
int n,m,i,j,k,x,pt[N],ch[N][26],cnt,chd[N][26],len,fail[N],q[N],bg,ed,head[N],adj[N],nxt[N],size[N],tp[N],son[N],id[N],fa[N],g[N],c[N],ans[N];
char s[N];
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
	++x;
	while(x<=len+1)
	{
		c[x]+=y;
		x+=x&-x;
	}
}
int sum(int x)
{
	int rtn=0;
	++x;
	while(x)
	{
		rtn+=c[x];
		x-=x&-x;
	}
	return rtn;
}
void work(int x,int w)
{
	int y=w;
	while(y!=-1)
	{
		add(id[tp[y]],1);
		add(id[y]+1,-1);
		y=fa[tp[y]];
	}
	for(y=vct[x].size()-1;y>=0;--y)
		ans[vct[x][y]]=sum(id[g[vct[x][y]]]);
	for(y=0;y<26;++y)
		if(ch[x][y])
			work(ch[x][y],chd[w][y]);
	y=w;
	while(y!=-1)
	{
		add(id[tp[y]],-1);
		add(id[y]+1,1);
		y=fa[tp[y]];
	}
}
int main()
{
	scanf("%d",&n);
	pt[0]=0;
	for(i=1;i<=n;++i)
	{
		scanf("%d",&j);
		if(j==1)
		{
			scanf("%s",s+1);
			if(!ch[0][s[1]-'a'])
				ch[0][s[1]-'a']=++cnt;
			pt[i]=ch[0][s[1]-'a'];
		}
		else
		{
			scanf("%d%s",&j,s+1);
			if(!ch[pt[j]][s[1]-'a'])
				ch[pt[j]][s[1]-'a']=++cnt;
			pt[i]=ch[pt[j]][s[1]-'a'];
		}
	}
	scanf("%d",&m);
	len=0;
	for(i=1;i<=m;++i)
	{
		scanf("%d%s",&j,s+1);
		for(k=1,x=0;s[k];++k)
		{
			if(!chd[x][s[k]-'a'])
				chd[x][s[k]-'a']=++len;
			x=chd[x][s[k]-'a'];
		}
		g[i]=x;
		vct[pt[j]].push_back(i);
	}
	bg=1,ed=0;
	for(i=0;i<26;++i)
		if(chd[0][i])
			q[++ed]=chd[0][i];
	while(bg<=ed)
	{
		for(i=0;i<26;++i)
			if(chd[q[bg]][i])
			{
				q[++ed]=chd[q[bg]][i];
				fail[q[ed]]=chd[fail[q[bg]]][i];
			}
			else
				chd[q[bg]][i]=chd[fail[q[bg]]][i];
		++bg;
	}
	for(i=1;i<=len;++i)
	{
		adj[i]=i;
		nxt[i]=head[fail[i]];
		head[fail[i]]=i;
	}
	fa[0]=-1;
	dfs(0);
	i=-1;
	tp[0]=0;
	Dfs(0);
	work(0,0);
	for(i=1;i<=m;++i)
		printf("%d\n",ans[i]);
	return 0;
}