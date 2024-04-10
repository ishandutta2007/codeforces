#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>

const int N=100005;
const int inf=1000000000;

int n,m,ans[N*3],a[N],lef[N*3];
struct tree{int mn;}t[N*4];
std::vector<int> vec[N];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct Segment_Tree
{
	int rt[N],sz;
	struct tree{int l,r,mx;}t[N*33];
	
	void ins(int &d,int l,int r,int x,int y)
	{
		int p=d;d=++sz;t[d]=t[p];t[d].mx=std::max(t[d].mx,y);
		if (l==r) return;
		int mid=(l+r)/2;
		if (x<=mid) ins(t[d].l,l,mid,x,y);
		else ins(t[d].r,mid+1,r,x,y);
	}
	
	int query(int d,int l,int r,int x,int y)
	{
		if (!d) return 0;
		if (x<=l&&r<=y) return t[d].mx;
		int mid=(l+r)/2,ans=0;
		if (x<=mid) ans=std::max(ans,query(t[d].l,l,mid,x,y));
		if (y>mid) ans=std::max(ans,query(t[d].r,mid+1,r,x,y));
		return ans;
	}
}seg;

void build(int d,int l,int r)
{
	t[d].mn=inf;
	if (l==r) return;
	int mid=(l+r)/2;
	build(d*2,l,mid);build(d*2+1,mid+1,r);
}

void modify(int d,int l,int r,int x,int y,int z)
{
	if (x<=l&&r<=y) {t[d].mn=std::min(t[d].mn,z);return;}
	int mid=(l+r)/2;
	if (x<=mid) modify(d*2,l,mid,x,y,z);
	if (y>mid) modify(d*2+1,mid+1,r,x,y,z);
}

int find(int d,int l,int r,int x)
{
	if (l==r) return t[d].mn;
	int mid=(l+r)/2;
	if (x<=mid) return std::min(t[d].mn,find(d*2,l,mid,x));
	else return std::min(t[d].mn,find(d*2+1,mid+1,r,x));
}

void solve()
{
	build(1,1,n);
	for (int i=1;i<=n;i++)
	{
		int x=a[i],p=seg.query(seg.rt[i-1],0,inf,0,x);
		while (p)
		{
			modify(1,1,n,1,p,x-a[p]);
			p=seg.query(seg.rt[p-1],0,inf,(x+a[p])/2+1,x);
		}
		for (int j=0;j<vec[i].size();j++) ans[vec[i][j]]=std::min(ans[vec[i][j]],find(1,1,n,lef[vec[i][j]]));
	}
}

int main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) seg.rt[i]=seg.rt[i-1],seg.ins(seg.rt[i],0,inf,a[i],i);
	m=read();
	for (int i=1;i<=m;i++)
	{
		int l=read(),r=read();
		vec[r].push_back(i);
		lef[i]=l;ans[i]=inf;
	}
	solve();
	for (int i=1;i<=n;i++) a[i]=inf-a[i];
	seg.sz=0;
	for (int i=1;i<=n;i++) seg.rt[i]=seg.rt[i-1],seg.ins(seg.rt[i],0,inf,a[i],i);
	solve();
	for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}