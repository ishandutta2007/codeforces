#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ls d<<1
#define rs d<<1|1

typedef long long LL;

const int N=400005;
const int MOD=1000000007;

int n,pri[305],ny[305],tot,a[N],val[N*4],tag[N*4],fa[70][N],c[70][N],q;
bool vis[305];

void get_prime(int n)
{
	for (int i=2;i<=n;i++)
		if (!vis[i])
		{
			pri[++tot]=i;
			for (int j=i*2;j<=n;j+=i) vis[j]=1;
		}
}

int ksm(int x,int y)
{
	int ans=1;
	while (y)
	{
		if (y&1) ans=(LL)ans*x%MOD;
		x=(LL)x*x%MOD;y>>=1;
	}
	return ans;
}

int find(int i,int x)
{
	if (fa[i][x]==x) return x;
	else return fa[i][x]=find(i,fa[i][x]);
}

void add(int i,int x)
{
	while (x<=n) c[i][x]++,x+=x&(-x);
}

int get(int i,int x)
{
	int ans=0;
	while (x) ans+=c[i][x],x-=x&(-x);
	return ans;
}

void ins(int l,int r,int y)
{
	for (int i=1;i<=tot;i++)
		if (y%pri[i]==0)
		{
			int x=find(i,l);
			while (x<=r) add(i,x),fa[i][x]=x+1,x=find(i,x);
		}
}

void push(int d,int l,int r)
{
	int w=tag[d],mid=(l+r)/2;tag[d]=1;
	if (w==1) return;
	val[ls]=(LL)val[ls]*ksm(w,mid-l+1)%MOD;tag[ls]=(LL)tag[ls]*w%MOD;
	val[rs]=(LL)val[rs]*ksm(w,r-mid)%MOD;tag[rs]=(LL)tag[rs]*w%MOD;
}

void build(int d,int l,int r)
{
	tag[d]=1;
	if (l==r) {val[d]=a[l];return;}
	int mid=(l+r)/2;
	build(ls,l,mid);build(rs,mid+1,r);
	val[d]=(LL)val[ls]*val[rs]%MOD;
}

void mul(int d,int l,int r,int x,int y,int w)
{
	if (x<=l&&r<=y) {tag[d]=(LL)tag[d]*w%MOD;val[d]=(LL)val[d]*ksm(w,r-l+1)%MOD;return;}
	push(d,l,r);
	int mid=(l+r)/2;
	if (x<=mid) mul(ls,l,mid,x,y,w);
	if (y>mid) mul(rs,mid+1,r,x,y,w);
	val[d]=(LL)val[ls]*val[rs]%MOD;
}

int query(int d,int l,int r,int x,int y)
{
	if (l==x&&r==y) return val[d];
	push(d,l,r);
	int mid=(l+r)/2;
	if (y<=mid) return query(ls,l,mid,x,y);
	else if (x>mid) return query(rs,mid+1,r,x,y);
	else return (LL)query(ls,l,mid,x,mid)*query(rs,mid+1,r,mid+1,y)%MOD;
}

int main()
{
	get_prime(300);
	for (int i=1;i<=300;i++) ny[i]=ksm(i,MOD-2);
	scanf("%d%d",&n,&q);
	for (int i=1;i<=tot;i++)
		for (int j=1;j<=n+1;j++)
			fa[i][j]=j;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),ins(i,i,a[i]);
	build(1,1,n);
	while (q--)
	{
		char ch[10];scanf("%s",ch);
		if (ch[0]=='T')
		{
			int l,r;scanf("%d%d",&l,&r);
			int ans=query(1,1,n,l,r);
			for (int i=1;i<=tot;i++)
				if (get(i,r)-get(i,l-1)) ans=(LL)ans*ny[pri[i]]%MOD*(pri[i]-1)%MOD;
			printf("%d\n",ans);
		}
		else
		{
			int l,r,x;scanf("%d%d%d",&l,&r,&x);
			mul(1,1,n,l,r,x);
			ins(l,r,x);
		}
	}
	return 0;
}