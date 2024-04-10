#include<bits/stdc++.h>
using namespace std;
int n,m,p;
int a[150002];
typedef pair<int,int> P;
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
	int laz[600002],len[600002];
	vector<P> vec[600002];
	inline vector<P> merge(vector<P> a,vector<P> b)
	{
		int t;
		for(int i=0;i<b.size();++i)
		{
			t=0;
			for(int j=0;j<a.size();++j)
				if(a[j].first==b[i].first)
				{
					a[j].second+=b[i].second,t=1;
					break;
				}
			if(t)continue;
			a.push_back(b[i]),t=n;
			if(a.size()<=100/p)continue;
			for(int j=0;j<a.size();++j)t=min(t,a[j].second);
			for(int j=0;j<a.size();++j)if(a[j].second==t)a[j]=a.back(),a.pop_back(),--j;else a[j].second-=t;
		}
		return a;
	}
	inline void cover(int k,int d)
	{
		vec[k].clear(),vec[k].push_back(P(laz[k]=d,len[k]));
	}
	inline void pushdown(int k,int ls,int rs)
	{
		if(laz[k])cover(ls,laz[k]),cover(rs,laz[k]),laz[k]=0;
	}
	inline void build(int k,int l,int r)
	{
		len[k]=r-l+1;
		if(l==r)return (void)(vec[k].push_back(P(a[l],1)));
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r),vec[k]=merge(vec[ls],vec[rs]);
	}
	inline void modify(int k,int l,int r,int l1,int r1,int d)
	{
		if(l>=l1 && r<=r1)return cover(k,d);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		pushdown(k,ls,rs);
		if(r1<=mid)modify(ls,l,mid,l1,r1,d);
		else if(l1>mid)modify(rs,mid+1,r,l1,r1,d);
		else modify(ls,l,mid,l1,mid,d),modify(rs,mid+1,r,mid+1,r1,d);
		vec[k]=merge(vec[ls],vec[rs]);
	}
	inline vector<P> query(int k,int l,int r,int l1,int r1)
	{
		if(l>=l1 && r<=r1)return vec[k];
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		pushdown(k,ls,rs);
		if(r1<=mid)return query(ls,l,mid,l1,r1);
		if(l1>mid)return query(rs,mid+1,r,l1,r1);
		return merge(query(ls,l,mid,l1,mid),query(rs,mid+1,r,mid+1,r1));
	}
}S;
inline void print(vector<P> vec)
{
	printf("  %d ",vec.size());
	for(int i=0;i<vec.size();++i)printf("%d ",vec[i].first);
	puts("");
}
int main()
{
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	S.build(1,1,n);
	for(int o,x,y,z;m--;)
	{
		scanf("%d%d%d",&o,&x,&y);
		if(o==1)scanf("%d",&z),S.modify(1,1,n,x,y,z);
		else print(S.query(1,1,n,x,y));
	}
	return 0;
}