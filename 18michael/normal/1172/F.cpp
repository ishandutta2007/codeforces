#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,m;
LL p;
int a[1000002];
LL pre[1000002];
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
	vector<LL> c[4000002];
	inline void build(int k,int l,int r)
	{
		if(l==r)return (void)(c[k].push_back(-inf),c[k].push_back(p-a[l]));
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r);
		for(int i=0;i+1<c[ls].size()+c[rs].size();++i)c[k].push_back(i? inf:-inf);
		for(int i=0,j=0;i<c[ls].size();--j,++i)for(;j<c[rs].size() && (i+1==c[ls].size() || c[ls][i+1]-1+pre[mid]-pre[l-1]-p*i>=c[rs][j]);++j)c[k][i+j]=min(c[k][i+j],max(c[ls][i],c[rs][j]-pre[mid]+pre[l-1]+p*i));
	}
	inline int query(int k,int l,int r,int l1,int r1,LL d)
	{
		if(l>=l1 && r<=r1)
		{
			int L=0,R=c[k].size()-1,Mid;
			for(;L<=R;)
			{
				Mid=((L+R)>>1);
				if(c[k][Mid]<=d)L=Mid+1;
				else R=Mid-1;
			}
			return R;
		}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k),res;
		if(r1<=mid)return query(ls,l,mid,l1,r1,d);
		if(l1>mid)return query(rs,mid+1,r,l1,r1,d);
		return res=query(ls,l,mid,l1,mid,d),res+query(rs,mid+1,r,mid+1,r1,d+pre[mid]-pre[l1-1]-p*res);
	}
}S;
int main()
{
	scanf("%d%d%lld",&n,&m,&p);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),pre[i]=pre[i-1]+a[i];
	S.build(1,1,n);
	for(int x,y;m--;)scanf("%d%d",&x,&y),printf("%lld\n",pre[y]-pre[x-1]-p*S.query(1,1,n,x,y,0));
	return 0;
}