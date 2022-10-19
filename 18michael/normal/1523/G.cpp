#include<bits/stdc++.h>
using namespace std;
int n,m,S_t;
int ans[50002];
typedef pair<int,int> P;
vector<P> vec[50002];
struct aaa
{
	int l,r,t;
};
inline aaa merge(aaa a,aaa b)
{
	return a.t<b.t? a:b;
}
struct SegTree2
{
	int lson[20000002],rson[20000002];
	aaa a[20000002];
	inline int newnode()
	{
		return ++S_t,lson[S_t]=rson[S_t]=0,a[S_t].t=m+1,S_t;
	}
	inline void modify(int k,int l,int r,int x,int y,int d)
	{
		a[k]=merge(a[k],(aaa){x,y,d});
		if(l==r)return ;
		int mid=((l+r)>>1);
		if(y<=mid)
		{
			if(!lson[k])lson[k]=newnode();
			modify(lson[k],l,mid,x,y,d);
		}
		else
		{
			if(!rson[k])rson[k]=newnode();
			modify(rson[k],mid+1,r,x,y,d);
		}
	}
	inline aaa query(int k,int l,int r,int l1,int r1)
	{
		if(!k)return (aaa){0,0,m+1};
		if(l>=l1 && r<=r1)return a[k];
		int mid=((l+r)>>1),ls=lson[k],rs=rson[k];
		if(r1<=mid)return query(ls,l,mid,l1,r1);
		if(l1>mid)return query(rs,mid+1,r,l1,r1);
		return merge(query(ls,l,mid,l1,mid),query(rs,mid+1,r,mid+1,r1));
	}
}S2;
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
	int to[200002];
	inline void modify(int k,int l,int r,int x,int y,int d)
	{
		if(!to[k])to[k]=S2.newnode();
		S2.modify(to[k],1,n,x,y,d);
		if(l==r)return ;
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(x<=mid)modify(ls,l,mid,x,y,d);
		else modify(rs,mid+1,r,x,y,d);
	}
	inline aaa query(int k,int l,int r,int l1,int r1,int l2,int r2)
	{
		if(l>=l1 && r<=r1)return S2.query(to[k],1,n,l2,r2);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(r1<=mid)return query(ls,l,mid,l1,r1,l2,r2);
		if(l1>mid)return query(rs,mid+1,r,l1,r1,l2,r2);
		return merge(query(ls,l,mid,l1,mid,l2,r2),query(rs,mid+1,r,mid+1,r1,l2,r2));
	}
}S;
inline int calc(int l,int r)
{
	if(l>r)return 0;
	aaa tmp=S.query(1,1,n,l,n,1,r);
	return tmp.t<=m? calc(l,tmp.l-1)+calc(tmp.r+1,r)+tmp.r-tmp.l+1:0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),vec[y-x+1].push_back(P(x,i));
	for(int i=n;i;--i)
	{
		for(int j=0;j<vec[i].size();++j)S.modify(1,1,n,vec[i][j].first,vec[i][j].first+i-1,vec[i][j].second);
		ans[i]=calc(1,n);
	}
	for(int i=1;i<=n;++i)printf("%d\n",ans[i]);
	return 0;
}