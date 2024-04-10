#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=400005;
int n,q,i,j,k,fa[N],size[N],ch[N][2],col[N],c[N],Root,head[N],adj[N],nxt[N];
bool rev[N];
char s[100];
void add(int x,int y)
{
	//printf("%d %d\n",x,y);
	while(x<=400000)
	{
		c[x]+=y;
		x+=x&-x;
	}
}
int sum(int x)
{
	int rtn=0;
	while(x)
	{
		rtn+=c[x];
		x-=x&-x;
	}
	return rtn;
}
void dfs(int x,int dad)
{
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=dad)
		{
			fa[adj[y]]=x;
			dfs(adj[y],x);
		}
}
void pushrev(int o)
{
	rev[o]=!rev[o];
	swap(ch[o][0],ch[o][1]);
}
void pushdown(int o)
{
	if(rev[o])
	{
		rev[ch[o][0]]=!rev[ch[o][0]],rev[ch[o][1]]=!rev[ch[o][1]];
		swap(ch[ch[o][0]][0],ch[ch[o][0]][1]),swap(ch[ch[o][1]][0],ch[ch[o][1]][1]);
		rev[o]=false;
	}
	col[ch[o][0]]=col[ch[o][1]]=col[o];
}
void maintain(int o)
{
	size[o]=size[ch[o][0]]+size[ch[o][1]]+1;
}
int cmp(int o,int x)
{
	if(size[ch[o][0]]+1==x)
		return -1;
	return size[ch[o][0]]+1<x;
}
void rotate(int &o,int d)
{
	int k=ch[o][d];
	ch[o][d]=ch[k][d^1];
	ch[k][d^1]=o;
	fa[k]=fa[o];
	fa[o]=k;
	fa[ch[o][d]]=o;
	maintain(o);
	maintain(k);
	o=k;
}
void splay(int &o,int x)
{
	pushdown(o);
	int k1=cmp(o,x);
	if(k1==-1)
		return;
	if(k1==1)
		x-=size[ch[o][0]]+1;
	pushdown(ch[o][k1]);
	int k2=cmp(ch[o][k1],x);
	if(k2!=-1)
	{
		if(k2==1)
			x-=size[ch[ch[o][k1]][0]]+1;
		splay(ch[ch[o][k1]][k2],x);
		if(k1==k2)
			rotate(o,k1);
		else
			rotate(ch[o][k1],k2);
	}
	rotate(o,k1);
}
int work(int o)
{
	if(!fa[o]||(ch[fa[o]][0]!=o&&ch[fa[o]][1]!=o))
	{
		Root=o;
		pushdown(o);
		return 0;
	}
	int rtn=work(fa[o]);
	pushdown(o);
	return rtn+(o==ch[fa[o]][0]?0:size[ch[fa[o]][0]]+1);
}
void Splay(int x)
{
	int rk=work(x)+size[ch[x][0]]+1;
	splay(Root,rk);
}
void access(int x)
{
	for(int y=0;x;)
	{
		Splay(x);
		add(col[x],-size[ch[x][0]]-1);
		ch[x][1]=y;
		maintain(x);
		y=x;
		x=fa[x];
	}
}
void makeroot(int x,int w)
{
	access(x);
	Splay(x);
	pushrev(x);
	col[x]=w;
	add(col[x],size[x]);
}
int cirno(int x)
{
	Splay(x);
	int rtn=sum(col[x]-1);
	rtn+=size[ch[x][1]]+1;
	return rtn;
}
int main()
{
	scanf("%d%d",&n,&q);
	for(i=1;i<n;++i)
	{
		scanf("%d%d",&j,&k);
		adj[i*2-1]=k;
		nxt[i*2-1]=head[j];
		head[j]=i*2-1;
		adj[i*2]=j;
		nxt[i*2]=head[k];
		head[k]=i*2;
	}
	for(i=1;i<=n;++i)
	{
		col[i]=i,size[i]=1;
		add(i,1);
	}
	dfs(1,-1);
	for(i=1;i<=n;++i)
		makeroot(i,i);
	while(q--)
	{
		scanf("%s",s);
		if(s[0]=='u')
		{
			scanf("%d",&i);
			++n;
			makeroot(i,n);
		}
		else if(s[0]=='w')
		{
			scanf("%d",&i);
			printf("%d\n",cirno(i));
		}
		else
		{
			scanf("%d%d",&i,&j);
			if(cirno(i)<cirno(j))
				printf("%d\n",i);
			else
				printf("%d\n",j);
		}
	}
	return 0;
}