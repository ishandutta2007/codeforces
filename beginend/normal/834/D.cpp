#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=35005;

int n,m,a[N],ls[N],last[N],f[55][N];
struct tree{int mx,tag;}t[N*5];

void updata(int d)
{
	t[d].mx=max(t[d*2].mx,t[d*2+1].mx);
}

void pushdown(int d,int l,int r)
{
	if (l==r||!t[d].tag) return;
	int w=t[d].tag;t[d].tag=0;
	t[d*2].mx+=w;t[d*2].tag+=w;
	t[d*2+1].mx+=w;t[d*2+1].tag+=w;
}

void build(int d,int l,int r,int now)
{
	t[d].tag=0;
	if (l==r)
	{
		t[d].mx=f[now][l-1];
		return;
	}
	int mid=(l+r)/2;
	build(d*2,l,mid,now);build(d*2+1,mid+1,r,now);
	updata(d);
}

void ins(int d,int l,int r,int x,int y,int z)
{
	if (x>y) return;
	pushdown(d,l,r);
	if (l==x&&r==y)
	{
		t[d].mx+=z;t[d].tag+=z;
		return;
	}
	int mid=(l+r)/2;
	ins(d*2,l,mid,x,min(y,mid),z);
	ins(d*2+1,mid+1,r,max(x,mid+1),y,z);
	updata(d);
}

int query(int d,int l,int r,int x,int y)
{
	if (x>y) return 0;
	pushdown(d,l,r);
	if (l==x&&r==y) return t[d].mx;
	int mid=(l+r)/2;
	return max(query(d*2,l,mid,x,min(y,mid)),query(d*2+1,mid+1,r,max(x,mid+1),y));
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ls[i]=last[a[i]];last[a[i]]=i;
	}
	for (int i=1;i<=m;i++)
	{
		build(1,1,n,i-1);
		for (int j=1;j<=n;j++)
		{
			ins(1,1,n,ls[j]+1,j,1);
			f[i][j]=query(1,1,n,1,j);
		}
	}
	printf("%d",f[m][n]);
	return 0;
}