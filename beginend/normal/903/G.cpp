#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

typedef long long LL;

const int N=200005;

int n,m,q,cnt,last[N],a[N],b[N];
LL val[N];
struct Queue
{
	priority_queue<LL> q1,q2;
	
	LL top()
	{
		while (!q2.empty()&&q1.top()==q2.top()) q1.pop(),q2.pop();
		return q1.top();
	}
	
	void del(LL x)
	{
		q2.push(x);
	}
	
	void push(LL x)
	{
		q1.push(x);
	}
}que;
struct tree{LL tag,mn;}t[N*5];
struct edge{int to,next,w;}e[N];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void addedge(int u,int v,int w)
{
	e[++cnt].to=v;e[cnt].w=w;e[cnt].next=last[u];last[u]=cnt;
}

void pushdown(int d,int l,int r)
{
	if (l==r||!t[d].tag) return;
	LL w=t[d].tag;t[d].tag=0;
	t[d*2].mn+=w;t[d*2].tag+=w;
	t[d*2+1].mn+=w;t[d*2+1].tag+=w;
}

void build(int d,int l,int r)
{
	if (l==r) {t[d].mn=b[l-1];return;}
	int mid=(l+r)/2;
	build(d*2,l,mid);build(d*2+1,mid+1,r);
	t[d].mn=min(t[d*2].mn,t[d*2+1].mn);
}

void ins(int d,int l,int r,int x,int y,int z)
{
	if (x>y) return;
	pushdown(d,l,r);
	if (l==x&&r==y) {t[d].mn+=z;t[d].tag+=z;return;}
	int mid=(l+r)/2;
	ins(d*2,l,mid,x,min(y,mid),z);
	ins(d*2+1,mid+1,r,max(x,mid+1),y,z);
	t[d].mn=min(t[d*2].mn,t[d*2+1].mn);
}

int main()
{
	n=read();m=read();q=read();
	for (int i=1;i<n;i++) a[i]=read(),b[i]=read();
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read(),z=read();
		addedge(x,y,z);
	}
	build(1,1,n);
	for (int i=1;i<=n;i++)
	{
		for (int j=last[i];j;j=e[j].next) ins(1,1,n,1,e[j].to,e[j].w);
		val[i]=t[1].mn;que.push(-val[i]-a[i]);
	}
	printf("%I64d\n",-que.top());
	while (q--)
	{
		int x=read(),y=read();
		que.del(-val[x]-a[x]);
		a[x]=y;
		que.push(-val[x]-a[x]);
		printf("%I64d\n",-que.top());
	}
	return 0;
}