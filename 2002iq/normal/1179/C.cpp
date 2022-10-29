#include <iostream>
using namespace std;
#define MX 1000000
long long tree[4000005],lazy[4000005];
void push(int node,int st,int en)
{
	tree[node]+=lazy[node];
	if (st!=en)
	{
		lazy[2*node]+=lazy[node];
		lazy[2*node+1]+=lazy[node];
	}
	lazy[node]=0;
}
void update(int node,int st,int en,int l,int r,int val)
{
	if (l<=st && en<=r)
	lazy[node]+=val;
	push(node,st,en);
	if (en<l || st>r || r<l || (l<=st && en<=r))
	return;
	int mid=(st+en)/2;
	update(2*node,st,mid,l,r,val);
	update(2*node+1,mid+1,en,l,r,val);
	tree[node]=min(tree[2*node],tree[2*node+1]);
}
int query(int node,int st,int en)
{
	push(node,st,en);
	if (st==en)
	return st;
	int mid=(st+en)/2;
	push(2*node,st,mid);
	push(2*node+1,mid+1,en);
	if (tree[2*node+1]<0)
	return query(2*node+1,mid+1,en);
	return query(2*node,st,mid);
}
int a[300005],b[300005];
int main()
{
	int n,m,q;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		update(1,0,MX,0,a[i],-1);
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
		update(1,0,MX,0,b[i],1);
	}
	scanf("%d",&q);
	while (q--)
	{
		int t,i,x;
		scanf("%d%d%d",&t,&i,&x);
		if (t==1)
		{
			update(1,0,MX,0,a[i],1);
			a[i]=x;
			update(1,0,MX,0,a[i],-1);
		}
		else
		{
			update(1,0,MX,0,b[i],-1);
			b[i]=x;
			update(1,0,MX,0,b[i],1);
		}
		if (tree[1]>=0)
		printf("-1\n");
		else
		printf("%d\n",query(1,0,MX));
	}
}