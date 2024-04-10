#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m;
int a[100002],ans[300002],id[100002];
typedef pair<int,int> P;
vector<P> vec[100002];
vector<int> vec1[100002];
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
	int mn[400002];
	inline void build(int k,int l,int r)
	{
		mn[k]=inf;
		if(l==r)return ;
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r);
	}
	inline void modify(int k,int l,int r,int x,int d)
	{
		mn[k]=min(mn[k],d);
		if(l==r)return ;
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(x<=mid)modify(ls,l,mid,x,d);
		else modify(rs,mid+1,r,x,d);
	}
	inline int query(int k,int l,int r,int l1,int r1)
	{
		if(l>=l1 && r<=r1)return mn[k];
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(r1<=mid)return query(ls,l,mid,l1,r1);
		if(l1>mid)return query(rs,mid+1,r,l1,r1);
		return min(query(ls,l,mid,l1,mid),query(rs,mid+1,r,mid+1,r1));
	}
}S;
struct SegTree1
{
	int mx[400002];
	inline void build(int k,int l,int r)
	{
		mx[k]=-inf;
		if(l==r)return ;
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r);
	}
	inline void modify(int k,int l,int r,int x,int d)
	{
		mx[k]=max(mx[k],d);
		if(l==r)return ;
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(x<=mid)modify(ls,l,mid,x,d);
		else modify(rs,mid+1,r,x,d);
	}
	inline int find(int k,int l,int r,int x,int d)
	{
		if(!x)return 0;
		if(l==r)return mx[k]>=d? l:0;
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k),res=0;
		if(x>mid && mx[rs]>=d)res=find(rs,mid+1,r,x,d);
		if(!res)res=find(ls,l,mid,x,d);
		return res;
	}
}S1;
inline bool cmp(int x,int y)
{
	return a[x]==a[y]? (x<y):(a[x]<a[y]);
}
inline void solve()
{
	S.build(1,1,n),S1.build(1,1,n),sort(id+1,id+n+1,cmp);
	for(int i=1;i<=n;S1.modify(1,1,n,id[i],a[id[i]]),++i)
	{
		vec1[id[i]].clear();
		for(int j=S1.find(1,1,n,id[i],-inf+1);j;j=S1.find(1,1,n,j-1,((a[id[i]]+a[j])>>1)+1))vec1[id[i]].push_back(j);
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<vec1[i].size();++j)S.modify(1,1,n,vec1[i][j],a[i]-a[vec1[i][j]]);
		for(int j=0;j<vec[i].size();++j)ans[vec[i][j].second]=min(ans[vec[i][j].second],S.query(1,1,n,vec[i][j].first,i));
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),id[i]=i;
	scanf("%d",&m);for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),vec[y].push_back(P(x,i)),ans[i]=inf;
	solve();for(int i=1;i<=n;++i)a[i]=-a[i];
	solve();for(int i=1;i<=m;++i)printf("%d\n",ans[i]);
	return 0;
}//