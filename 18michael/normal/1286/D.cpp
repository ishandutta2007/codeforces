#include<bits/stdc++.h>
#define LL long long
#define mod 998244353
using namespace std;
int n,vec_t=0;
LL ans=0;
LL X[100002],v[100002];
LL p[100002][2];
struct aaa
{
	int x;
	bool o1,o2;
	LL a,b;
}vec[200002];
inline bool cmp(aaa a,aaa b)
{
	return a.a*b.b>b.a*a.b;
}
inline LL Pow(int a,int b)
{
	if(!b)return 1;
	LL c=Pow(a,b>>1);
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
struct Matrix
{
	LL a[2][2];
}F[100002];
inline Matrix Mul(Matrix A,Matrix B)
{
	Matrix C;
	for(int i=0;i<2;++i)for(int j=0;j<2;C.a[i][j]%=mod,++j)for(int k=C.a[i][j]=0;k<2;++k)C.a[i][j]+=A.a[i][k]*B.a[k][j];
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
	Matrix a[400002];
	inline void build(int k,int l,int r)
	{
		if(l==r)return (void)(a[k]=F[l]);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r),a[k]=Mul(a[ls],a[rs]);
	}
	inline void modify(int k,int l,int r,int x)
	{
		if(l==r)return (void)(a[k]=F[l]);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(x<=mid)modify(ls,l,mid,x);
		else modify(rs,mid+1,r,x);
		a[k]=Mul(a[ls],a[rs]);
	}
}S;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld%lld%lld",&X[i],&v[i],&p[i][1]),F[i].a[0][0]=F[i].a[0][1]=p[i][0]=(1-(F[i].a[1][0]=F[i].a[1][1]=(p[i][1]*=Pow(100,mod-2))%=mod))%mod;
	for(int i=1;i<n;++i)
	{
		vec[++vec_t]=(aaa){i,1,0,X[i+1]-X[i],v[i]+v[i+1]},F[i].a[1][0]=0;
		if(v[i]<v[i+1])vec[++vec_t]=(aaa){i,0,0,X[i+1]-X[i],v[i+1]-v[i]},F[i].a[0][0]=0;
		if(v[i]>v[i+1])vec[++vec_t]=(aaa){i,1,1,X[i+1]-X[i],v[i]-v[i+1]},F[i].a[1][1]=0;
	}
	F[n].a[0][1]=F[n].a[1][0]=0,S.build(1,1,n),sort(vec+1,vec+vec_t+1,cmp);
	for(int i=1;i<=vec_t;++i)
	{
		F[0]=F[vec[i].x];
		for(int j=0;j<2;++j)for(int k=0;k<2;++k)F[vec[i].x].a[j][k]=(j==vec[i].o1 && k==vec[i].o2? p[vec[i].x][j]:0);
		S.modify(1,1,n,vec[i].x),(ans+=(((S.a[1].a[0][0]+S.a[1].a[0][1]+S.a[1].a[1][0]+S.a[1].a[1][1])*vec[i].a)%mod)*Pow(vec[i].b,mod-2))%=mod,F[vec[i].x]=F[0],F[vec[i].x].a[vec[i].o1][vec[i].o2]=p[vec[i].x][vec[i].o1],S.modify(1,1,n,vec[i].x);
	}
	return 0&printf("%lld",(ans+mod)%mod);
}