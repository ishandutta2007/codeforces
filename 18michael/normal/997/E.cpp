#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f
using namespace std;
int n,q,stmx_t=0,stmn_t=0;
int p[120002],stmx[120002],stmn[120002];
LL ans[120002];
typedef pair<int,int> P;
vector<P> vec[120002];
struct aaa
{
	int mn;
	LL cnt;
};
inline aaa merge(aaa a,aaa b)
{
	if(a.mn>b.mn)swap(a,b);
	if(a.mn==b.mn)a.cnt+=b.cnt;
	return a;
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
	int laz[480002];
	aaa a[480002],b[480002],c[480002];
	inline void build(int k,int l,int r)
	{
		if(l==r)return (void)(a[k]=(aaa){l+inf,1});
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r),a[k]=merge(a[ls],a[rs]);
	}
	inline void add(int k,int d)
	{
		a[k].mn+=d,laz[k]+=d;
		if(laz[k]<b[k].mn)b[k]=(aaa){laz[k],0};
	}
	inline void add1(int k,aaa d)
	{
		c[k]=merge(c[k],(aaa){a[k].mn+d.mn,a[k].cnt*d.cnt}),b[k]=merge(b[k],(aaa){laz[k]+d.mn,d.cnt});
	}
	inline void pushdown(int k,int ls,int rs)
	{
		if(b[k].mn || b[k].cnt)add1(ls,b[k]),add1(rs,b[k]),b[k]=(aaa){0,0};
		if(laz[k])add(ls,laz[k]),add(rs,laz[k]),laz[k]=0;
	}
	inline void modify(int k,int l,int r,int l1,int r1,int d)
	{
		if(l>=l1 && r<=r1)return add(k,d);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		pushdown(k,ls,rs);
		if(r1<=mid)modify(ls,l,mid,l1,r1,d);
		else if(l1>mid)modify(rs,mid+1,r,l1,r1,d);
		else modify(ls,l,mid,l1,mid,d),modify(rs,mid+1,r,mid+1,r1,d);
		a[k]=merge(a[ls],a[rs]),c[k]=merge(c[ls],c[rs]);
	}
	inline void modify1(int k,int l,int r,int l1,int r1)
	{
		if(l>=l1 && r<=r1)return add1(k,(aaa){0,1});
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		pushdown(k,ls,rs);
		if(r1<=mid)modify1(ls,l,mid,l1,r1);
		else if(l1>mid)modify1(rs,mid+1,r,l1,r1);
		else modify1(ls,l,mid,l1,mid),modify1(rs,mid+1,r,mid+1,r1);
		a[k]=merge(a[ls],a[rs]),c[k]=merge(c[ls],c[rs]);
	}
	inline aaa query(int k,int l,int r,int l1,int r1)
	{
		if(l>=l1 && r<=r1)return c[k];
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		pushdown(k,ls,rs);
		if(r1<=mid)return query(ls,l,mid,l1,r1);
		if(l1>mid)return query(rs,mid+1,r,l1,r1);
		return merge(query(ls,l,mid,l1,mid),query(rs,mid+1,r,mid+1,r1));
	}
}S;
int main()
{
	scanf("%d",&n),S.build(1,1,n);
	for(int i=1;i<=n;++i)scanf("%d",&p[i]);
	scanf("%d",&q);
	for(int i=1,x,y;i<=q;++i)scanf("%d%d",&x,&y),vec[y].push_back(P(x,i));
	for(int i=1;i<=n;++i)
	{
		for(;stmx_t && p[stmx[stmx_t]]<p[i];--stmx_t)S.modify(1,1,n,stmx[stmx_t-1]+1,stmx[stmx_t],-p[stmx[stmx_t]]);
		for(;stmn_t && p[stmn[stmn_t]]>p[i];--stmn_t)S.modify(1,1,n,stmn[stmn_t-1]+1,stmn[stmn_t],p[stmn[stmn_t]]);
		S.modify(1,1,n,stmx[stmx_t]+1,i,p[i]),S.modify(1,1,n,stmn[stmn_t]+1,i,-p[i]),S.modify(1,1,n,1,i,-i-inf),stmx[++stmx_t]=stmn[++stmn_t]=i,S.modify1(1,1,n,1,i),S.modify(1,1,n,1,i,i+inf);
		for(int j=0;j<vec[i].size();++j)ans[vec[i][j].second]=S.query(1,1,n,vec[i][j].first,i).cnt;
	}
	for(int i=1;i<=q;++i)printf("%lld\n",ans[i]);
	return 0;
}