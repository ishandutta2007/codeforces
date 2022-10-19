#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include<bits/stdc++.h>
#define Mx 59
#define LL long long
using namespace std;
int n,st_t=0;LL ans=0;
char one[1000002];
int l[1000002],r[1000002],st[1000002];
LL a[1000002];
struct aaa
{
	int x,opt,l,r;
};
vector<aaa> v[62];
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
	char laz[4000002];
	int cnt[4000002][3];
	inline void build(int k,int l,int r)
	{
		if(l==r){cnt[k][0]=1,cnt[k][1]=cnt[k][2]=0;return ;}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r),cnt[k][0]=cnt[ls][0]+cnt[rs][0],cnt[k][1]=cnt[ls][1]+cnt[rs][1],cnt[k][2]=cnt[ls][2]+cnt[rs][2];
	}
	inline void modify(int k,int l,int r,int l1,int r1,char d)
	{
		if(l>=l1 && r<=r1)
		{
			laz[k]+=d;
			if(d==1)cnt[k][2]=cnt[k][1],cnt[k][1]=cnt[k][0],cnt[k][0]=0;
			else cnt[k][0]=cnt[k][1],cnt[k][1]=cnt[k][2],cnt[k][2]=0;
			return ;
		}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		laz[ls]+=laz[k],laz[rs]+=laz[k];
		if(laz[k]==2)
		{
			cnt[ls][2]=cnt[ls][0],cnt[ls][1]=cnt[ls][0]=0;
			cnt[rs][2]=cnt[rs][0],cnt[rs][1]=cnt[rs][0]=0;
		}
		else if(laz[k]==1)
		{
			cnt[ls][2]=cnt[ls][1],cnt[ls][1]=cnt[ls][0],cnt[ls][0]=0;
			cnt[rs][2]=cnt[rs][1],cnt[rs][1]=cnt[rs][0],cnt[rs][0]=0;
		}
		else if(laz[k]==-1)
		{
			cnt[ls][0]=cnt[ls][1],cnt[ls][1]=cnt[ls][2],cnt[ls][2]=0;
			cnt[rs][0]=cnt[rs][1],cnt[rs][1]=cnt[rs][2],cnt[rs][2]=0;
		}
		else if(laz[k]==-2)
		{
			cnt[ls][0]=cnt[ls][2],cnt[ls][1]=cnt[ls][2]=0;
			cnt[rs][0]=cnt[rs][2],cnt[rs][1]=cnt[rs][2]=0;
		}
		laz[k]=0;
		if(r1<=mid)modify(ls,l,mid,l1,r1,d);
		else if(l1>mid)modify(rs,mid+1,r,l1,r1,d);
		else modify(ls,l,mid,l1,mid,d),modify(rs,mid+1,r,mid+1,r1,d);
		cnt[k][0]=cnt[ls][0]+cnt[rs][0],cnt[k][1]=cnt[ls][1]+cnt[rs][1],cnt[k][2]=cnt[ls][2]+cnt[rs][2];
	}
}S;
char buf[(1<<25)+2];int pbuf=-1;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=buf[++pbuf];
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=buf[++pbuf];
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=buf[++pbuf];
	x=f? -x:x;
}
inline bool cmp(aaa a,aaa b)
{
	return (a.x==b.x)? (a.opt<b.opt):(a.x<b.x);
}
inline char calc(LL x)
{
	char res=0;
	while(x)res+=(x&1),x>>=1;
	return res;
}
int main()
{
	fread(buf,1,1<<25,stdin),read(n);
	for(int i=1;i<=n;++i)
	{
		read(a[i]),one[i]=calc(a[i]);
		while(st_t && a[st[st_t]]<a[i])--st_t;
		l[i]=(st_t? st[st_t]+1:1),st[++st_t]=i;
	}
	st_t=0;
	for(int i=n;i;--i)
	{
		while(st_t && a[st[st_t]]<=a[i])--st_t;
		r[i]=(st_t? st[st_t]-1:n),st[++st_t]=i,v[one[i]].push_back((aaa){i,1,l[i],i}),v[one[i]].push_back((aaa){r[i]+1,-1,l[i],i});
	}
	st_t=0;
	for(int i=1;i<=n;++i)
	{
		while(st_t && a[st[st_t]]>a[i])--st_t;
		l[i]=(st_t? st[st_t]+1:1),st[++st_t]=i;
	}
	st_t=0;
	for(int i=n;i;--i)
	{
		while(st_t && a[st[st_t]]>=a[i])--st_t;
		r[i]=(st_t? st[st_t]-1:n),st[++st_t]=i,v[one[i]].push_back((aaa){i,1,l[i],i}),v[one[i]].push_back((aaa){r[i]+1,-1,l[i],i});
	}
	S.build(1,1,n);
	for(int i=0;i<=Mx;++i)
	{
		sort(v[i].begin(),v[i].end(),cmp);
		for(int j=0,k;j<v[i].size();j=k)
		{
			for(k=j;k<v[i].size() && v[i][k].x==v[i][j].x;++k)S.modify(1,1,n,v[i][k].l,v[i][k].r,v[i][k].opt);
			ans+=1LL*((k<v[i].size()? v[i][k].x:n+1)-v[i][j].x)*S.cnt[1][2];
		}
	}
	return 0&printf("%lld",ans);
}