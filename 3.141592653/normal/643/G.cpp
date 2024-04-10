#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
int n,m,pc,rs;
int w[222222];
struct maxset
{
	int v[6],g[6];
	void print()
	{
		register int i;
		int cnt=0;
		for(i=1;i<=rs;i++)if(g[i])cnt++;
		printf("%d ",cnt);
		for(i=1;i<=rs;i++)if(g[i])printf("%d ",v[i]);
		puts("");
	}void clr()
	{memset(g,0,sizeof(g));}
	void ins(int x,int t)
	{
		register int i;
		for(i=1;i<=rs;i++)if(v[i]==x){g[i]+=t;return;}
		for(i=1;i<=rs;i++)if(!g[i]){v[i]=x,g[i]=t;return;}
		int pos=1;
		for(i=2;i<=rs;i++)
			if(g[i]<g[pos])pos=i;
		if(g[pos]>=t)for(i=1;i<=rs;i++)g[i]-=t;
		else
		{
			int del=g[pos];
			for(i=1;i<=rs;i++)g[i]-=del;
			v[pos]=x,g[pos]=t-del;
		}
	}
}tr[1111111];
maxset operator+(maxset x,maxset y)
{
	register int i;
	for(i=1;i<=rs;i++)if(y.g[i])x.ins(y.v[i],y.g[i]);
	return x;
}
int tag[1111111];
void push(int p,int c,int l,int r)
{tag[p]=c,tr[p].clr(),tr[p].ins(c,r-l+1);}
void pushd(int p,int l,int r)
{
	int mid=(l+r)>>1;
	if(tag[p])push(p<<1,tag[p],l,mid),push(p<<1|1,tag[p],mid+1,r),tag[p]=0;
}
int c[1111111];
void modify(int l,int r,int cc,int p=1,int pl=1,int pr=n)
{
	if(l>pr||pl>r)return;
	if(l<=pl&&pr<=r)return push(p,cc,pl,pr);
	int mid=(pl+pr)>>1;
	pushd(p,pl,pr),modify(l,r,cc,p<<1,pl,mid),modify(l,r,cc,p<<1|1,mid+1,pr),tr[p]=tr[p<<1|1]+tr[p<<1];
}
void build(int l=1,int r=n,int p=1)
{
	if(l==r)return tr[p].ins(c[l],1);
	int mid=(l+r)>>1;
	build(l,mid,p<<1),build(mid+1,r,p<<1|1),tr[p]=tr[p<<1|1]+tr[p<<1];
}
maxset query(int l,int r,int p=1,int pl=1,int pr=n)
{
	if(l<=pl&&pr<=r)return tr[p];
	int mid=(pl+pr)>>1;
	pushd(p,pl,pr);
	if(mid<l)return query(l,r,p<<1|1,mid+1,pr);
	if(mid>=r)return query(l,r,p<<1,pl,mid);
	return query(l,r,p<<1,pl,mid)+query(l,r,p<<1|1,mid+1,pr);
}
int main()
{
	scanf("%d%d%d",&n,&m,&pc),rs=100/pc;
	register int i;
	for(i=1;i<=n;i++)
		scanf("%d",c+i);
	build();
	for(i=1;i<=m;i++)
	{
		int o,x,y,z;
		scanf("%d%d%d",&o,&x,&y);
		if(o==2)query(x,y).print();
		else scanf("%d",&z),modify(x,y,z);
	}
}
/*
Just go for it.
*/