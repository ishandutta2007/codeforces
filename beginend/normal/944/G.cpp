#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=100005;
const int MOD=1000000007;

int k,n,m,cor[N*4],tot,sz,con0[N*4],con1[N*4];
struct tree{int l,r,tag,s;}t[N*16];
struct data{int l,r;}a[N],b[N];

inline int add(int x,int y) {return x+y<MOD?x+y:x+y-MOD;}
inline int dec(int x,int y) {return x-y<0?x-y+MOD:x-y;}
inline int mul(int x,int y) {return (LL)x*y%MOD;}

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

void pushdown(int d,int l,int r)
{
	if (t[d].tag==-1) return;
	int w=t[d].tag,mid=(l+r)/2;t[d].tag=-1;
	t[t[d].l].tag=t[t[d].r].tag=w;
	t[t[d].l].s=mul(w,mid-l+1);
	t[t[d].r].s=mul(w,r-mid);
}

void build(int &d,int l,int r)
{
	d=++sz;t[d].tag=-1;
	if (l==r) return;
	int mid=(l+r)/2;
	build(t[d].l,l,mid);build(t[d].r,mid+1,r);
}

void ins(int d,int l,int r,int x,int y,int z)
{
	if (x>y) return;
	if (x<=l&&r<=y) {t[d].tag=z;t[d].s=mul(z,r-l+1);return;}
	pushdown(d,l,r);
	int mid=(l+r)/2;
	if (x<=mid) ins(t[d].l,l,mid,x,y,z);
	if (y>mid) ins(t[d].r,mid+1,r,x,y,z);
	t[d].s=add(t[t[d].l].s,t[t[d].r].s);
}

int query(int d,int l,int r,int x,int y)
{
	if (x<=l&&r<=y) return t[d].s;
	pushdown(d,l,r);
	int mid=(l+r)/2;
	if (y<=mid) return query(t[d].l,l,mid,x,y);
	else if (x>mid) return query(t[d].r,mid+1,r,x,y);
	else return add(query(t[d].l,l,mid,x,y),query(t[d].r,mid+1,r,x,y));
}

int main()
{
	scanf("%d%d%d",&k,&n,&m);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].l,&a[i].r),a[i].l--,cor[++tot]=a[i].l,cor[++tot]=a[i].r;
	for (int i=1;i<=m;i++) scanf("%d%d",&b[i].l,&b[i].r),b[i].l--,cor[++tot]=b[i].l,cor[++tot]=b[i].r;
	cor[++tot]=0;cor[++tot]=k;
	std::sort(cor+1,cor+tot+1);
	tot=std::unique(cor+1,cor+tot+1)-cor-1;
	for (int i=1;i<=n;i++)
	{
		a[i].l=std::lower_bound(cor+1,cor+tot+1,a[i].l)-cor;
		a[i].r=std::lower_bound(cor+1,cor+tot+1,a[i].r)-cor;
		con0[a[i].r]=std::max(con0[a[i].r],a[i].l);
	}
	for (int i=1;i<=m;i++)
	{
		b[i].l=std::lower_bound(cor+1,cor+tot+1,b[i].l)-cor;
		b[i].r=std::lower_bound(cor+1,cor+tot+1,b[i].r)-cor;
		con1[b[i].r]=std::max(con1[b[i].r],b[i].l);
	}
	int rt0=0,rt1=0;
	build(rt0,1,tot);build(rt1,1,tot);
	ins(rt0,1,tot,1,1,1);
	ins(rt1,1,tot,1,1,1);
	for (int i=2;i<=tot;i++)
	{
		int x=query(rt0,1,tot,1,i-1);
		int y=query(rt1,1,tot,1,i-1);
		int coe=dec(ksm(2,cor[i]-cor[i-1]-1),1);
		ins(rt0,1,tot,i-1,i-1,add(y,query(rt0,1,tot,i-1,i-1)));
		ins(rt1,1,tot,i-1,i-1,add(x,query(rt1,1,tot,i-1,i-1)));
		coe=mul(x+y,coe);
		ins(rt0,1,tot,i,i,coe);
		ins(rt1,1,tot,i,i,coe);
		ins(rt0,1,tot,1,con1[i],0);
		ins(rt1,1,tot,1,con0[i],0);
	}
	printf("%d\n",mul(add(query(rt0,1,tot,1,tot),query(rt1,1,tot,1,tot)),ksm(2,MOD-2)));
	return 0;
}