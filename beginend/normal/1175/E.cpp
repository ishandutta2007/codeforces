#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ls d<<1
#define rs d<<1|1

const int N=200005;
const int inf=1e9;

int n,m,mxr[N*10],bz[N][25],bin[25];
struct val{int l,r;}a[N];

bool cmp(val a,val b)
{
	return a.l<b.l||a.l==b.l&&a.r<b.r;
}

int get_max(int x,int y)
{
	return a[x].r>a[y].r?x:y;
}

void ins(int d,int l,int r,int x,int y)
{
	if (l==r)
	{
		mxr[d]=get_max(mxr[d],y);
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid) ins(ls,l,mid,x,y);
	else ins(rs,mid+1,r,x,y);
	mxr[d]=get_max(mxr[ls],mxr[rs]);
}

int query(int d,int l,int r,int x,int y)
{
	if (x<=l&&r<=y) return mxr[d];
	int mid=(l+r)/2;
	if (y<=mid) return query(ls,l,mid,x,y);
	else if (x>mid) return query(rs,mid+1,r,x,y);
	else return get_max(query(ls,l,mid,x,y),query(rs,mid+1,r,x,y));
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].l,&a[i].r);
	std::sort(a+1,a+n+1,cmp);
	int tmp=n,mx=0;
	for (int i=1;i<=n;i++)
		if (mx>=a[i].r) a[i].l=inf,tmp--;
		else mx=a[i].r;
	std::sort(a+1,a+n+1,cmp);
	n=tmp;
	for (int i=1;i<=n;i++) ins(1,0,a[n].r,a[i].l,i);
	bin[0]=1;
	for (int i=1;i<=20;i++) bin[i]=bin[i-1]<<1;
	for (int i=1;i<n;i++)
	{
		bz[i][0]=query(1,0,a[n].r,a[i].l,a[i].r);
		if (bz[i][0]==i) bz[i][0]=0;
	}
	for (int j=1;j<=20;j++)
		for (int i=1;i+bin[j]-1<=n;i++)
			bz[i][j]=bz[bz[i][j-1]][j-1];
	while (m--)
	{
		int x,y;scanf("%d%d",&x,&y);
		int now=query(1,0,a[n].r,0,x),ans=1;
		for (int i=20;i>=0;i--)
			if (a[bz[now][i]].r<y&&bz[now][i]) ans+=bin[i],now=bz[now][i];
		if (a[now].r<y)
		{
			if (bz[now][0]) ans++;
			else ans=-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}