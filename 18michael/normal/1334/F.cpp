#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
#define inf1 0x3f3f3f3f3f3f3f
using namespace std;
int n,m,las;LL ans=inf,res;
int a[500002],p[500002],b[500002];
LL f[500002],suf[500002]={};
set<int> s[500002];
set<int>::iterator it1,it2;
typedef pair<int,int> P;
priority_queue<P,vector<P>,greater<P> > pq;
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
	LL sum[2000002];
	inline void build(int k,int l,int r)
	{
		if(l==r){sum[k]=p[l];return ;}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r),sum[k]=sum[ls]+sum[rs];
	}
	inline void modify(int k,int l,int r,int x,int d)
	{
		if(l==r){sum[k]=d;return ;}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(x<=mid)modify(ls,l,mid,x,d);
		else modify(rs,mid+1,r,x,d);
		sum[k]=sum[ls]+sum[rs];
	}
	inline LL query(int k,int l,int r,int l1,int r1)
	{
		if(l1>r1)return 0;
		if(l>=l1 && r<=r1)return sum[k];
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(r1<=mid)return query(ls,l,mid,l1,r1);
		if(l1>mid)return query(rs,mid+1,r,l1,r1);
		return query(ls,l,mid,l1,mid)+query(rs,mid+1,r,mid+1,r1);
	}
}S;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n),s[0].insert(b[0]=0);
	for(int i=1;i<=n;++i)read(a[i]),f[i]=inf,s[a[i]].insert(i),pq.push(P(a[i],i));
	for(int i=1;i<=n;++i)read(p[i]);
	S.build(1,1,n),read(m);
	for(int i=1;i<=m;++i)read(b[i]);
	for(int i=n;i;--i)
	{
		suf[i]=suf[i+1];
		if(a[i]>b[m] || p[i]<0)suf[i]+=p[i];
	}
	for(int i=1;i<=m;++i)
	{
		it1=s[b[i-1]].begin(),res=inf,las=1;
		while(!pq.empty() && pq.top().first<=b[i-1])
		{
			if(p[pq.top().second]>0)S.modify(1,1,n,pq.top().second,0);
			pq.pop();
		}
		for(it2=s[b[i]].begin();it2!=s[b[i]].end();++it2)
		{
			while(it1!=s[b[i-1]].end() && (*it1)<(*it2))res=min(res+S.query(1,1,n,las,(*it1)),f[*it1]),las=(*it1)+1,++it1;
			f[*it2]=res+S.query(1,1,n,las,(*it2)-1);
		}
	}
	for(int i=1;i<=n;++i)if(a[i]==b[m])ans=min(ans,f[i]+suf[i+1]);
	if(ans>=inf1)puts("NO");
	else printf("YES\n%lld",ans);
	return 0;
}