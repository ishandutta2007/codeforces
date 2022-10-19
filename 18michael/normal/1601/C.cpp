#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f
using namespace std;
int Test_num,n,m,mn,tot,tot1,tot2,t,tmp;LL ans;
int a[1000008],b[1000008],c[2000008],id[2000008],id1[1000008];
inline int lowbit(int x)
{
	return x&(-x);
}
struct BIT
{
	int sum[2000008];
	inline void modify(int x,int d)
	{
		while(x<=tot)sum[x]+=d,x+=lowbit(x);
	}
	inline int query(int x)
	{
		int res=0;
		while(x)res+=sum[x],x-=lowbit(x);
		return res;
	}
}S;
inline int lson(int x)
{
	return (x<<1);
}
inline int rson(int x)
{
	return ((x<<1)|1);
}
struct SegTree
{
	int mn[8000008],laz[8000008];
	inline void modify(int k,int l,int r,int l1,int r1,int d)
	{
		//printf("MDF %d %d %d %d %d %d\n",k,l,r,l1,r1,d);
		if(l>=l1 && r<=r1){laz[k]+=d,mn[k]+=d;return ;}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		laz[ls]+=laz[k],mn[ls]+=laz[k],laz[rs]+=laz[k],mn[rs]+=laz[k],laz[k]=0;
		if(r1<=mid)modify(ls,l,mid,l1,r1,d);
		else if(l1>mid)modify(rs,mid+1,r,l1,r1,d);
		else modify(ls,l,mid,l1,mid,d),modify(rs,mid+1,r,mid+1,r1,d);
		mn[k]=min(mn[ls],mn[rs]);
	}
}S1;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(int x,int y)
{
	return c[x]<c[y]? 1:0;
}
inline bool cmp1(int x,int y)
{
	return a[x]<a[y]? 1:0;
}
inline void solve()
{
	read(n),read(m),ans=tot=t=0;
	for(int i=1;i<=n;++i)read(a[i]),c[++tot]=a[i],id[tot]=tot,id1[i]=i;
	for(int i=1;i<=m;++i)read(b[i]),c[++tot]=b[i],id[tot]=tot;
	sort(id+1,id+tot+1,cmp);
	for(int i=1;i<=tot;++i)
	{
		if(i==1 || c[id[i]]!=c[id[i-1]])++t;
		if(id[i]<=n)a[id[i]]=t;
		else b[id[i]-n]=t;
	}
	sort(b+1,b+m+1);
	for(int i=1;i<=tot;++i)S.sum[i]=0;
	for(int i=1;i<=n;++i)ans+=i-1-S.query(a[i]),S.modify(a[i],1);
	tot=tot1=tot2=1,sort(id1+1,id1+n+1,cmp1);
	for(int i=1;i<=4*(n+1);++i)S1.mn[i]=S1.laz[i]=0;
	for(int i=1;i<=n;++i)S1.modify(1,1,n+1,i+1,n+1,1);
	for(int i=1;i<=t;++i)
	{
		while(tot<=n && a[id1[tot]]==i)S1.modify(1,1,n+1,id1[tot]+1,n+1,-1),++tot;
		while(tot1<=n && a[id1[tot1]]==i-1)S1.modify(1,1,n+1,1,id1[tot1],1),++tot1;
		while(tot2<=m && b[tot2]==i)ans+=S1.mn[1],++tot2;
		//printf("%d:%d\n",i,ans);
		//puts("");
	}
	printf("%lld\n",ans);
}
int main()
{
	read(Test_num);
	while(Test_num--)solve();
	return 0;
}