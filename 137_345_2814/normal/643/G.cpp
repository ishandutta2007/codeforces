//log^2
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 150050
int n,m,v[N],cl[N],as[11],ct,p,l1,r1,a,b,c,d,t,is2[N];
struct sth{int s[6][2];};
sth operator *(sth a,sth b)
{
	for(int i=0;i<t;i++)
	for(int j=0;j<t;j++)
	if(a.s[i][0]==b.s[j][0])a.s[i][1]+=b.s[j][1],b.s[j][1]=0;
	for(int j=0;j<t;j++)
	if(b.s[j][1])
	{
		int tp=b.s[j][1],fg=1;
		for(int i=0;i<t;i++)
		if(tp>a.s[i][1])tp=a.s[i][1];
		for(int i=0;i<t;i++)
		{
			a.s[i][1]-=tp;
			if(a.s[i][1]==0&&fg)a.s[i][0]=b.s[j][0],a.s[i][1]=b.s[j][1]-tp,fg=0;
		}
	}
	return a;
}
struct segtree{
	struct node{int l,r,lz;sth as;}e[N*4];
	void pushup(int x){e[x].as=e[x<<1].as*e[x<<1|1].as;}
	void pushdown(int x,int s)
	{
		if(e[x].lz==-1)return;
		memset(e[x<<1].as.s,0,sizeof(e[x<<1].as.s));
		memset(e[x<<1|1].as.s,0,sizeof(e[x<<1|1].as.s));
		e[x<<1].as.s[0][0]=e[x<<1|1].as.s[0][0]=e[x].lz;
		e[x<<1].as.s[0][1]=(s+1)>>1;
		e[x<<1|1].as.s[0][1]=s>>1;
		e[x<<1].lz=e[x<<1|1].lz=e[x].lz;
		e[x].lz=-1;
	}
	void build(int x,int l,int r)
	{
		e[x].l=l;e[x].r=r;e[x].lz=-1;
		if(l==r){e[x].as.s[0][0]=v[l];e[x].as.s[0][1]=1;return;}
		int mid=(l+r)>>1;
		build(x<<1,l,mid);
		build(x<<1|1,mid+1,r);
		pushup(x);
	}
	void modify(int x,int l,int r,int v)
	{
		if(e[x].l==l&&e[x].r==r){memset(e[x].as.s,0,sizeof(e[x].as.s));e[x].as.s[0][0]=v;e[x].as.s[0][1]=e[x].r-e[x].l+1;e[x].lz=v;return;}
		pushdown(x,e[x].r-e[x].l+1);
		int mid=(e[x].l+e[x].r)>>1;
		if(mid>=r)modify(x<<1,l,r,v);
		else if(mid<l)modify(x<<1|1,l,r,v);
		else modify(x<<1,l,mid,v),modify(x<<1|1,mid+1,r,v);
		pushup(x);
	}
	sth query(int x,int l,int r)
	{
		if(e[x].l==l&&e[x].r==r)
		{
			return e[x].as;
		}
		pushdown(x,e[x].r-e[x].l+1);
		int mid=(e[x].l+e[x].r)>>1;
		if(mid>=r)return query(x<<1,l,r);
		else if(mid<l)return query(x<<1|1,l,r);
		else return query(x<<1,l,mid)*query(x<<1|1,mid+1,r);
	}
}st;
int main()
{
	scanf("%d%d%d",&n,&m,&p);t=100/p;
	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	st.build(1,1,n);
	while(m--)
	{
		scanf("%d",&a);
		if(a==1)
		{
			scanf("%d%d%d",&b,&c,&d);
			st.modify(1,b,c,d);
		}
		else
		{
			scanf("%d%d",&l1,&r1);
			ct=0;
			sth tp=st.query(1,l1,r1);
			printf("%d ",100/p);
			for(int i=1;i<=100/p;i++)printf("%d ",tp.s[i-1][0]);
			printf("\n");
		}
	}
}