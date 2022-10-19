#include<bits/stdc++.h>
#define Mx 1700000
#define LL long long
using namespace std;
int n,q,mod,phi;
int a[100002];
LL pw[12][Mx+2];
vector<int> vec;
inline LL Pow(LL a,int b)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=Pow(a,(b>>1));
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
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
	LL sum[400002],laz[400002];
	int tim[400002][12];
	inline void pushup(int k,int ls,int rs)
	{
		sum[k]=(sum[ls]+sum[rs])%mod;
	}
	inline void pushdown(int k,int ls,int rs)
	{
		for(int i=0;i<vec.size();++i)(sum[ls]*=pw[i][tim[k][i]])%=mod,tim[ls][i]+=tim[k][i],(sum[rs]*=pw[i][tim[k][i]])%=mod,tim[rs][i]+=tim[k][i],tim[k][i]=0;
		(sum[ls]*=laz[k])%=mod,(laz[ls]*=laz[k])%=mod,(sum[rs]*=laz[k])%=mod,(laz[rs]*=laz[k])%=mod,laz[k]=1;
	}
	inline void modify(int k,int d,int o,int z)
	{
		sum[k]=(z? 1:(sum[lson(k)]+sum[rson(k)])%mod);
		for(int i=0;i<vec.size();++i)
		{
			for(;!(d%vec[i]);d/=vec[i])tim[k][i]+=o;
			(sum[k]*=pw[i][tim[k][i]])%=mod;
		}
		(sum[k]*=((laz[k]*=(~o? d:Pow(d,phi-1)))%=mod))%=mod;
	}
	inline void build(int k,int l,int r)
	{
		laz[k]=1;
		if(l==r)return modify(k,a[l],1,1);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r),pushup(k,ls,rs);
	}
	inline void mul(int k,int l,int r,int l1,int r1,int d)
	{
		if(l>=l1 && r<=r1)return modify(k,d,1,l==r);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		pushdown(k,ls,rs);
		if(r1<=mid)mul(ls,l,mid,l1,r1,d);
		else if(l1>mid)mul(rs,mid+1,r,l1,r1,d);
		else mul(ls,l,mid,l1,mid,d),mul(rs,mid+1,r,mid+1,r1,d);
		pushup(k,ls,rs);
	}
	inline void div(int k,int l,int r,int x,int d)
	{
		if(l==r)return modify(k,d,-1,1);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		pushdown(k,ls,rs);
		if(x<=mid)div(ls,l,mid,x,d);
		else div(rs,mid+1,r,x,d);
		pushup(k,ls,rs);
	}
	inline int query(int k,int l,int r,int l1,int r1)
	{
		if(l>=l1 && r<=r1)return sum[k];
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		pushdown(k,ls,rs);
		if(r1<=mid)return query(ls,l,mid,l1,r1);
		if(l1>mid)return query(rs,mid+1,r,l1,r1);
		return (query(ls,l,mid,l1,mid)+query(rs,mid+1,r,mid+1,r1))%mod;
	}
}S;
int main()
{
	scanf("%d%d",&n,&mod),phi=q=mod;
	for(int i=2;i*i<=q;++i)if(!(q%i))for(phi=phi/i*(i-1),vec.push_back(i);!(q%i);q/=i);
	if(q>1)phi=phi/q*(q-1),vec.push_back(q);
	for(int i=0;i<vec.size();++i)
	{
		pw[i][0]=1;
		for(int j=1;j<=Mx;++j)pw[i][j]=(pw[i][j-1]*vec[i])%mod;
	}
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	S.build(1,1,n),scanf("%d",&q);
	for(int o,x,y,z;q--;)
	{
		scanf("%d%d%d",&o,&x,&y);
		if(o==1)scanf("%d",&z),S.mul(1,1,n,x,y,z);
		else if(o==2)S.div(1,1,n,x,y);
		else printf("%d\n",S.query(1,1,n,x,y));
	}
	return 0;
}