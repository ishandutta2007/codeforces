#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
const int MAXN=300005,MAXK=21;

int n,a[MAXN],sum[MAXN<<2|1][MAXK];
void update(int id)
{
	for(int i=0;i<MAXK;i++)
	{
		sum[id][i]=sum[id<<1][i];
		for(int j=0;j<MAXK;j++)
			if(sum[id<<1][i]&(1<<j))
				sum[id][i]|=sum[id<<1|1][j];
	}
}
void build(int id,int l,int r)
{
	if(l==r)
	{
		for(int i=0;i<MAXK;i++)
			if(a[l]&(1<<i))sum[id][i]=a[l];
			else sum[id][i]=(1<<i);
		return;
	}
	int mid=(l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	update(id);
}
int query(int id,int l,int r,int ql,int qr,int x)
{
	if(l==ql && r==qr)
	{
		int ans=0;
		for(int i=0;i<MAXK;i++)
			if(x&(1<<i))ans|=sum[id][i];
//printf("[%d,%d]:%d->%d\n",l,r,x,ans);
		return ans|x;
	}
	int mid=(l+r)>>1;
	if(qr<=mid)return query(id<<1,l,mid,ql,qr,x);
	if(ql>mid)return query(id<<1|1,mid+1,r,ql,qr,x);
	int y=query(id<<1,l,mid,ql,mid,x);
	return query(id<<1|1,mid+1,r,mid+1,qr,y)|y;
}

int main()
{
	int Q,x,y;
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	build(1,1,n);
	while(Q--)
	{
		scanf("%d%d",&x,&y);
		if(y-x>=2)printf((query(1,1,n,x+1,y-1,a[x])&a[y])?"Shi\n":"Fou\n");
		else printf((a[x]&a[y])?"Shi\n":"Fou\n");
	}
	return 0;
}