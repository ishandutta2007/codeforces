#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=400005;
const int inf=1e9;

int n,q,a[N],p[N],f[N],g[N],rt1[N],rt2[N],sz,tim[N],w[N];
bool vis[N];
struct tree{int l,r,mx;}t[N*40];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int get_lis()
{
	int mx=0;
	for (int i=1;i<=n;i++)
	{
		f[i]=std::lower_bound(p+1,p+mx+1,a[i])-p;
		if (f[i]>mx) mx=f[i],p[mx]=a[i];
		else p[f[i]]=std::min(p[f[i]],a[i]);
	}
	mx=0;
	for (int i=1;i<=n;i++) a[i]=-a[i];
	for (int i=n;i>=1;i--)
	{
		g[i]=std::lower_bound(p+1,p+mx+1,a[i])-p;
		if (g[i]>mx) mx=g[i],p[mx]=a[i];
		else p[g[i]]=std::min(p[g[i]],a[i]);
	}
	for (int i=1;i<=n;i++) a[i]=-a[i];
	for (int i=1;i<=n;i++)
		if (f[i]+g[i]-1==mx) tim[f[i]]++;
	for (int i=1;i<=n;i++)
		if (f[i]+g[i]-1==mx&&tim[f[i]]==1) vis[i]=1;
	return mx;
}

void ins(int &d,int l,int r,int x,int y)
{
	int p=d;d=++sz;t[d]=t[p];
	t[d].mx=std::max(t[d].mx,y);
	if (l==r) return;
	int mid=(l+r)/2;
	if (x<=mid) ins(t[d].l,l,mid,x,y);
	else ins(t[d].r,mid+1,r,x,y);
}

int query(int d,int l,int r,int x,int y)
{
	if (x>y) return 0;
	if (x<=l&&r<=y) return t[d].mx;
	int mid=(l+r)/2;
	if (y<=mid) return query(t[d].l,l,mid,x,y);
	else if (x>mid) return query(t[d].r,mid+1,r,x,y);
	else return std::max(query(t[d].l,l,mid,x,y),query(t[d].r,mid+1,r,x,y));
}

int main()
{
	n=read();q=read();
	for (int i=1;i<=n;i++) a[i]=read(),w[i]=a[i];
	std::sort(w+1,w+n+1);
	int m=std::unique(w+1,w+n+1)-w-1;
	for (int i=1;i<=n;i++) a[i]=std::lower_bound(w+1,w+m+1,a[i])-w;
	int mx=get_lis();
	for (int i=1;i<=n;i++) rt1[i]=rt1[i-1],ins(rt1[i],1,m,a[i],f[i]);
	for (int i=n;i>=1;i--) rt2[i]=rt2[i+1],ins(rt2[i],1,m,a[i],g[i]);
	while (q--)
	{
		int x=read(),y=read();
		int k1=std::lower_bound(w+1,w+m+1,y)-w-1;
		int k2=std::upper_bound(w+1,w+m+1,y)-w;
		int w=query(rt1[x-1],1,m,1,k1)+query(rt2[x+1],1,m,k2,m)+1;
		printf("%d\n",vis[x]?std::max(mx-1,w):std::max(mx,w));
	}
	return 0;
}