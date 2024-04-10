#include<bits/stdc++.h>
using namespace std;
const int N=100005,M=998244353,E=262144;
int n,i,a,x,y,ans,tree[N*4],las,lazy[N*4];
void pushdown(int i)
{
	lazy[i<<1]+=lazy[i];
	lazy[i<<1|1]+=lazy[i];
	tree[i<<1]+=lazy[i];
	tree[i<<1|1]+=lazy[i];
	lazy[i]=0;
}
void modify(int i,int l,int r,int x,int y)
{
	if(l==r)
	{
		tree[i]=y;
		return;
	}
	pushdown(i);
	int mid=l+r>>1;
	if(mid>=x)
		modify(i<<1,l,mid,x,y);
	else
		modify(i<<1|1,mid+1,r,x,y);
	tree[i]=max(tree[i<<1],tree[i<<1|1]);
}
void modify2(int i,int l,int r,int x,int y)
{
	if(l==r)
	{
		tree[i]+=y;
		return;
	}
	pushdown(i);
	int mid=l+r>>1;
	if(mid>=x)
		modify2(i<<1,l,mid,x,y);
	else
		modify2(i<<1|1,mid+1,r,x,y);
	tree[i]=max(tree[i<<1],tree[i<<1|1]);
}
int main()
{
#ifndef ONLINE_JUDGE 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a);
		modify2(1,0,n,a,-1);
		int tmp=tree[1];
		modify2(1,0,n,a,1);
		if(las!=a)
			++lazy[1];
		modify(1,0,n,las,tmp+1);
		las=a;
	}
	cout<<tree[1];
}