#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int n,m,k,ch[10000005][2],root[200005],u,v,head[100005],Next[200005],adj[200005],i,siz[100005],day;
long long tree[10000005],lazy[10000005],lazy1[10000005],ans;
int d[100005],w[100005],p;
struct str{
	int l,r;
	long long x;
}seg[100005];
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
void pushdown(int i)
{
	if(ch[i][0]==0)
		ch[i][0]=++k;
	if(ch[i][1]==0)
		ch[i][1]=++k;
	if(k>10000000)
		k=0;
	if(lazy1[i]!=0)
	{
		tree[ch[i][1]]+=lazy1[i];
		tree[ch[i][0]]+=lazy1[i];
		lazy1[ch[i][0]]+=lazy1[i];
		lazy1[ch[i][1]]+=lazy1[i];
		if(lazy[ch[i][0]]!=0)
			lazy[ch[i][0]]+=lazy1[i];
		if(lazy[ch[i][1]]!=0)
			lazy[ch[i][1]]+=lazy1[i];
		lazy1[i]=0;
	}
	if(lazy[i]!=0)
	{
		tree[ch[i][0]]=max(tree[ch[i][0]],lazy[i]);
		lazy[ch[i][0]]=max(lazy[ch[i][0]],lazy[i]);
		tree[ch[i][1]]=max(tree[ch[i][1]],lazy[i]);
		lazy[ch[i][1]]=max(lazy[ch[i][1]],lazy[i]);
		lazy[i]=0;
	}
}
void pushup(int i)
{
	tree[i]=max(tree[ch[i][0]],tree[ch[i][1]]);
}
void modify(int i,int l,int r,int ll,int rr,long long x)
{
	if(l!=r)
		pushdown(i);
	if(l>=ll&&r<=rr)
	{
		tree[i]+=x;
		if(l!=r)
			lazy1[i]+=x;
		else
			ans=tree[i];
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=ll)
		modify(ch[i][0],l,mid,ll,rr,x);
	if(mid<rr)
		modify(ch[i][1],mid+1,r,ll,rr,x);
	pushup(i);
}
void modify2(int i,int l,int r,int ll,int rr,long long x)
{
	if(l>=ll&&r<=rr)
	{
		tree[i]=max(tree[i],x);
		if(l!=r)
			lazy[i]=max(lazy[i],x);
		return;
	}
	if(l!=r)
		pushdown(i);
	int mid=(l+r)>>1;
	if(mid>=ll)
		modify2(ch[i][0],l,mid,ll,rr,x);
	if(mid<rr)
		modify2(ch[i][1],mid+1,r,ll,rr,x);
	pushup(i);
}
void dfs2(int i,int l,int r)
{
	if(ch[i][0]==ch[i][1]&&ch[i][0]==0)
	{
		seg[++p]=(str){l,r,tree[i]};
		return;
	}
	pushdown(i);
	int mid=(l+r)>>1;
	dfs2(ch[i][0],l,mid);
	dfs2(ch[i][1],mid+1,r);
}
void dfs(int i)
{
	int j,mx=0,mxx=0;
	siz[i]=(d[i]!=0);
	for(j=head[i];j!=0;j=Next[j])
	{
		dfs(adj[j]);
		siz[i]+=siz[adj[j]];
		if(siz[adj[j]]>mx)
		{
			mx=siz[adj[j]];
			mxx=adj[j];
		}
	}
	root[i]=root[mxx];
	if(mxx==0)
		root[i]=++k;
	for(j=head[i];j!=0;j=Next[j])
		if(adj[j]!=mxx)
		{
			p=0;
			dfs2(root[adj[j]],1,day);
			for(int u=1;u<=p;)
			{
				int y;
				for(y=u;y<=p&&seg[y].x==seg[u].x;y++);
				modify(root[i],1,day,seg[u].l,seg[y-1].r,seg[u].x);
				u=y;
			}
		}
	if(d[i]!=0)
	{
		modify(root[i],1,day,d[i],d[i],w[i]);
		if(d[i]!=day)
			modify2(root[i],1,day,d[i]+1,day,ans);
	}
}
int main()
{
	scanf("%d %d %d",&n,&m,&day);
	for(i=2;i<=n;i++)
	{
		scanf("%d",&u);
		Push(u,i);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d",&v);
		scanf("%d %d",&d[v],&w[v]);
	}
	k=0;
	dfs(1);
	cout<<tree[root[1]];
}