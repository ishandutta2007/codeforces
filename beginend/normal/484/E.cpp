#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 100005
using namespace std;

int n,m,root[N],tot;
struct data{int h,id;}a[N];
struct tree{int l,r,size,ls,rs,mxs;}t[N*30];

bool cmp(data a,data b)
{
	return a.h>b.h;
}

void build(int &d,int l,int r)
{
	d=++tot;
	t[d].size=r-l+1;
	if (l==r) return;
	int mid=(l+r)/2;
	build(t[d].l,l,mid);
	build(t[d].r,mid+1,r);
}

void updata(int x)
{
	t[x].size=t[t[x].l].size+t[t[x].r].size;
	t[x].ls=t[t[x].l].ls;
	if (t[t[x].l].ls==t[t[x].l].size) t[x].ls+=t[t[x].r].ls;
	t[x].rs=t[t[x].r].rs;
	if (t[t[x].r].rs==t[t[x].r].size) t[x].rs+=t[t[x].l].rs;
	t[x].mxs=max(t[t[x].l].rs+t[t[x].r].ls,max(t[t[x].l].mxs,t[t[x].r].mxs));
}

void insert(int &x,int y,int p,int l,int r)
{
	x=++tot;
	if (l==r)
	{
		t[x].mxs=t[x].ls=t[x].rs=t[x].size=1;
		return;
	}
	t[x].l=t[y].l;
	t[x].r=t[y].r;
	int mid=(l+r)/2;
	if (p<=mid) insert(t[x].l,t[y].l,p,l,mid);
	else insert(t[x].r,t[y].r,p,mid+1,r);
	updata(x);
}

int query(int d,int x,int y,int l,int r)
{
	if (x==l&&y==r) return t[d].mxs;
	int mid=(l+r)/2;
	if (y<=mid) return query(t[d].l,x,y,l,mid);
	else if (x>mid) return query(t[d].r,x,y,mid+1,r);
	else return max(min(t[t[d].l].rs,mid-x+1)+min(t[t[d].r].ls,y-mid),max(query(t[d].l,x,mid,l,mid),query(t[d].r,mid+1,y,mid+1,r)));
}

int solve(int x,int y,int w)
{
	int l=1,r=n,ans;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (query(root[mid],x,y,1,n)>=w)
		{
			ans=a[mid].h;
			r=mid-1;
		}
		else l=mid+1;
	}
	return ans;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].h);
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	build(root[0],1,n);
	for (int i=1;i<=n;i++)
		insert(root[i],root[i-1],a[i].id,1,n);
	scanf("%d",&m);
	int rt=root[1];
	for (int i=1;i<=m;i++)
	{
		int l,r,w;
		scanf("%d%d%d",&l,&r,&w);
		printf("%d\n",solve(l,r,w));
	}
	return 0;
}