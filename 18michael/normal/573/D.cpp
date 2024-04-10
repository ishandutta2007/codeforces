#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,q;
int idw[30002],idh[30002],tow[30002],toh[30002];
LL w[30002],h[30002],t[30002];
struct Matrix
{
	LL a[3][3];
}M[30002];
inline Matrix Mul(Matrix A,Matrix B)
{
	Matrix C;
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
		{
			C.a[i][j]=-inf;
			for(int k=0;k<3;++k)C.a[i][j]=max(C.a[i][j],A.a[i][k]+B.a[k][j]);
		}
	return C;
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
	Matrix a[120002];
	inline void build(int k,int l,int r)
	{
		if(l==r)return (void)(a[k]=M[l]);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r),a[k]=Mul(a[rs],a[ls]);
	}
	inline void modify(int k,int l,int r,int x)
	{
		if(l==r)return (void)(a[k]=M[l]);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(x<=mid)modify(ls,l,mid,x);
		else modify(rs,mid+1,r,x);
		a[k]=Mul(a[rs],a[ls]);
	}
}S;
inline bool cmp(int x,int y)
{
	return t[x]<t[y];
}
inline void upd(int x)
{
	M[x]=(Matrix){{idw[x]!=idh[x]? w[x]*h[x]:-inf,x>1? ((idw[x]!=idh[x-1] && idw[x-1]!=idh[x])? w[x]*h[x-1]+w[x-1]*h[x]:-inf):-inf,
	x>2? max((idw[x]!=idh[x-1] && idw[x-1]!=idh[x-2] && idw[x-2]!=idh[x])? w[x]*h[x-1]+w[x-1]*h[x-2]+w[x-2]*h[x]:-inf,
	(idw[x-1]!=idh[x] && idw[x-2]!=idh[x-1] && idw[x]!=idh[x-2])? w[x-1]*h[x]+w[x-2]*h[x-1]+w[x]*h[x-2]:-inf):-inf,
	0,-inf,-inf,-inf,0,-inf}};
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)scanf("%lld",&w[i]),idw[i]=i,t[i]=w[i];
	sort(idw+1,idw+n+1,cmp);
	for(int i=1;i<=n;++i)w[i]=t[idw[i]];
	for(int i=1;i<=n;++i)scanf("%lld",&h[i]),idh[i]=i,t[i]=h[i];
	sort(idh+1,idh+n+1,cmp);
	for(int i=1;i<=n;++i)h[i]=t[idh[i]];
	for(int i=1;i<=n;++i)tow[idw[i]]=toh[idh[i]]=i;
	for(int i=1;i<=n;++i)upd(i);
	S.build(1,1,n);
	for(int x,y;q--;)
	{
		scanf("%d%d",&x,&y),swap(toh[x],toh[y]),swap(idh[toh[x]],idh[toh[y]]);
		for(int i=toh[x];i<=min(toh[x]+2,n);++i)upd(i),S.modify(1,1,n,i);
		for(int i=toh[y];i<=min(toh[y]+2,n);++i)upd(i),S.modify(1,1,n,i);
		printf("%lld\n",S.a[1].a[0][0]);
	}
	return 0;
}