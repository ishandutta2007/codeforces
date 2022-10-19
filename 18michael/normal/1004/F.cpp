#include<cstdio>
#include<vector>
#define LL long long
using namespace std;
int n,m,X;
typedef pair<int,int> P;
int b[100002];
struct aaa
{
	LL sum;
	vector<P> pre,suf;
};
inline aaa merge(aaa a,aaa b,int l,int mid,int r)
{
	aaa c;int la=l-1;
	c.sum=a.sum+b.sum,c.pre=a.pre,c.suf=b.suf;
	for(int i=0,j;i<b.pre.size();++i)
	{
		if(c.pre.back().second==(j=(c.pre.back().second|b.pre[i].second)))continue;
		c.pre.push_back(P(b.pre[i].first,j));
	}
	for(int i=0,j;i<a.suf.size();++i)
	{
		if(c.suf.back().second==(j=(c.suf.back().second|a.suf[i].second)))continue;
		c.suf.push_back(P(a.suf[i].first,j));
	}
	for(int i=a.suf.size()-1,j=0;~i && j<b.pre.size();--i)
	{
		while(j<b.pre.size() && (a.suf[i].second|b.pre[j].second)<X)++j;
		if(j==b.pre.size())break;
		c.sum+=1LL*(a.suf[i].first-la)*(r-b.pre[j].first+1),la=a.suf[i].first;
	}
	return c;
}
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
	aaa a[400002];
	inline void build(int k,int l,int r)
	{
		if(l==r)
		{
			a[k].pre.push_back(P(l,b[l])),a[k].suf.push_back(P(l,b[l])),a[k].sum=(b[l]>=X);
			return ;
		}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r),a[k]=merge(a[ls],a[rs],l,mid,r);
	}
	inline void modify(int k,int l,int r,int x,int d)
	{
		if(l==r)
		{
			a[k].pre.clear(),a[k].suf.clear(),a[k].pre.push_back(P(l,d)),a[k].suf.push_back(P(l,d)),a[k].sum=(d>=X);
			return ;
		}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(x<=mid)modify(ls,l,mid,x,d);
		else modify(rs,mid+1,r,x,d);
		a[k]=merge(a[ls],a[rs],l,mid,r);
	}
	inline aaa query(int k,int l,int r,int l1,int r1)
	{
		if(l>=l1 && r<=r1)return a[k];
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(r1<=mid)return query(ls,l,mid,l1,r1);
		if(l1>mid)return query(rs,mid+1,r,l1,r1);
		return merge(query(ls,l,mid,l1,mid),query(rs,mid+1,r,mid+1,r1),l1,mid,r1);
	}
}S;
int main()
{
	scanf("%d%d%d",&n,&m,&X);
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	S.build(1,1,n);
	for(int x,y,z;m--;)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(x==1)S.modify(1,1,n,y,z);
		else printf("%lld\n",S.query(1,1,n,y,z).sum);
	}
	return 0;
}