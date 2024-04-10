#include<bits/stdc++.h>
#define pb push_back
#define ls d<<1
#define rs d<<1|1

typedef long long LL;

const int N=500005;

int n,f[N],cnt;
struct data{int l,r;}a[N];
std::vector<int> vec[N*8];

bool cmp(data a,data b)
{
	return a.r<b.r;
}

int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}

void ins(int d,int l,int r,int x,int y,int z)
{
	if (x<=l&&r<=y) {vec[d].pb(z);return;}
	int mid=(l+r)/2;
	if (x<=mid) ins(ls,l,mid,x,y,z);
	if (y>mid) ins(rs,mid+1,r,x,y,z);
}

void build(int d,int l,int r,int x,int y)
{
	for (auto r:vec[d])
	{
		if (find(y)==find(r))
		{
			puts("NO");
			exit(0);
		}
		f[find(y)]=find(r);
		cnt++;
	}
	if (l==r) return;
	int mid=(l+r)/2;
	if (x<=mid) build(ls,l,mid,x,y);
	else build(rs,mid+1,r,x,y);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].l,&a[i].r);
	std::sort(a+1,a+n+1,cmp);
	LL ans=0;
	for (int i=1;i<=n;i++) f[i]=i;
	for (int i=1;i<=n;i++)
	{
		build(1,1,n*2,a[i].l,i);
		ins(1,1,n*2,a[i].l,a[i].r,i);
	}
	puts(cnt==n-1?"YES":"NO");
	return 0;
}