#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=400005,MAXK=19;

int n,p[MAXN],disp[MAXN];
struct Edge
{
	int v;
	Edge *next;
}pool[MAXN],*h[MAXN];
int etot=0;
inline void addEdge(int u,int v)
{
	Edge *p=&pool[++etot];
	p->v=v;p->next=h[u];h[u]=p;
}

int dep[MAXN],euler[MAXN<<1|1],dfn[MAXN],cnt=0;
void geteuler(int u)
{
	euler[++cnt]=u;
	for(Edge *p=h[u];p;p=p->next)
	{
		dep[p->v]=dep[u]+1;
		geteuler(p->v);
		euler[++cnt]=u;
	}
}
int _log2[MAXN],rmq[MAXN][MAXK];
void sparse()
{
	_log2[1]=0;
	for(int i=2;i<=cnt;i++)
		if((1<<(_log2[i-1]+1))<=i)_log2[i]=_log2[i-1]+1;
		else _log2[i]=_log2[i-1];
	for(int i=1;i<=cnt;i++)
		rmq[i][0]=i;
	for(int j=1;j<MAXK;j++)
		for(int i=1;i+(1<<j)-1<=cnt;i++)
			if(dep[euler[rmq[i][j-1]]]<dep[euler[rmq[i+(1<<(j-1))][j-1]]])
				rmq[i][j]=rmq[i][j-1];
			else rmq[i][j]=rmq[i+(1<<(j-1))][j-1];
}
inline int RMQ(int l,int r)
{
	int t=_log2[r-l+1];
	if(dep[euler[rmq[l][t]]]<dep[euler[rmq[r-(1<<t)+1][t]]])return rmq[l][t];
	return rmq[r-(1<<t)+1][t];
}
inline int LCA(int u,int v)
{
	if(dfn[u]>dfn[v])swap(u,v);
	return euler[RMQ(dfn[u],dfn[v])];
}

struct Node
{
	bool cha;
	int u,v;
	Node(){cha=u=v=0;}
	Node(int x)
	{
		cha=1;
		u=v=x;
	}
}st[MAXN<<2|1];

inline Node update(Node ls,Node rs)
{
	Node ans;
	ans.cha=0;
	if(!ls.cha || !rs.cha)return ans;
	int a[4]={ls.u,ls.v,rs.u,rs.v};
	for(int i=0;i<4;i++)
		for(int j=i+1;j<4;j++)
		{
			bool flag=1;
			for(int k=0;k<4;k++)
			{
				if(k==i || k==j)continue;
				int d=LCA(a[i],a[j]);
				if( (LCA(a[k],a[i])==a[k] || LCA(a[k],a[j])==a[k]) && 
					LCA(a[k],d)==d )continue;
				flag=0;
				break;
			}
			if(flag)
			{
				ans.cha=1;
				ans.u=a[i];ans.v=a[j];
				return ans;
			}
		}
	return ans;
}

void build(int id,int l,int r)
{
	if(l==r){st[id]=Node(disp[l]);return;}
	int mid=(l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	st[id]=update(st[id<<1],st[id<<1|1]);
}
void modify(int id,int l,int r,int x,int c)
{
	if(l==r){st[id]=Node(c);return;}
	int mid=(l+r)>>1;
	if(x<=mid)modify(id<<1,l,mid,x,c);
	else modify(id<<1|1,mid+1,r,x,c);
	st[id]=update(st[id<<1],st[id<<1|1]);
}
int query(int id,int l,int r,Node s)
{
	Node t;
	if(l>1)t=update(s,st[id]);
	else t=st[id];
	if(t.cha)return r;
	if(l==r)return l-1;
	int mid=(l+r)>>1;
	if(l>1)t=update(s,st[id<<1]);
	else t=st[id<<1];
	if(t.cha)
	{
		if(l>1)s=update(s,t);
		else s=t;
		return query(id<<1|1,mid+1,r,s);
	}
	return query(id<<1,l,mid,s);
}

int main()
{
    int Q,op,u,v;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		++p[i];disp[p[i]]=i;
	}
    for(int i=2;i<=n;i++)
    {
    	scanf("%d",&u);
    	addEdge(u,i);
    }
    geteuler(1);
    for(int i=1;i<=cnt;i++)
    	if(!dfn[euler[i]])dfn[euler[i]]=i;
    sparse();
	build(1,1,n);
    scanf("%d",&Q);
    while(Q--)
    {
    	scanf("%d",&op);
    	if(op==1)
    	{
	    	scanf("%d%d",&u,&v);
	    	modify(1,1,n,p[u],v);
	    	modify(1,1,n,p[v],u);
	    	swap(p[u],p[v]);
	    }
	    else printf("%d\n",query(1,1,n,Node()));
    }
    return 0;
}