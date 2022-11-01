#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ls d<<1
#define rs d<<1|1

const int N=200005;

int n,m,q,p[N],a[N],bel[N],nx[N][20],mn[N*4],rig[N],lst[N];

void build(int d,int l,int r)
{
	if (l==r) {mn[d]=rig[l];return;}
	int mid=(l+r)/2;
	build(ls,l,mid);build(rs,mid+1,r);
	mn[d]=std::min(mn[ls],mn[rs]);
}

int query(int d,int l,int r,int x,int y)
{
	if (x<=l&&r<=y) return mn[d];
	int mid=(l+r)/2;
	if (y<=mid) return query(ls,l,mid,x,y);
	else if (x>mid) return query(rs,mid+1,r,x,y);
	else return std::min(query(ls,l,mid,x,y),query(rs,mid+1,r,x,y));
}

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]),bel[p[i]]=i;
	for (int i=1;i<=m;i++) scanf("%d",&a[i]);
	for (int i=m;i>=1;i--)
	{
		int nxt=bel[a[i]]%n+1;
		nx[i][0]=lst[p[nxt]];
		for (int j=1;j<=18;j++) nx[i][j]=nx[nx[i][j-1]][j-1];
		lst[a[i]]=i;
	}
	for (int i=1;i<=m-n+1;i++)
	{
		rig[i]=i;
		for (int j=18;j>=0;j--)
			if ((n-1)&(1<<j)) rig[i]=nx[rig[i]][j];
		if (!rig[i]) rig[i]=m+1;
	}
	build(1,1,m);
	while (q--)
	{
		int l,r;scanf("%d%d",&l,&r);
		if (r-l+1<n) putchar('0');
		else if (query(1,1,m,l,r-n+1)<=r) putchar('1');
		else putchar('0');
	}
	return 0;
	return 0;
}