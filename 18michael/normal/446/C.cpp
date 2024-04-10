#include<cstdio>
#define half 400000
#define Mx 800000
#define LL long long
#define mod 1000000009
int n,m,x,y,opt;
LL a[300002],f[800002];
struct aaa
{
	LL val,lazy1,lazy2;
}arr[1200002]={};
inline int lson(int x)
{
	return (x<<1);
}
inline int rson(int x)
{
	return ((x<<1)|1);
}
inline void build(int k,int l,int r)
{
	if(l==r)
	{
		arr[k].val=a[l];
		return ;
	}
	int ls=lson(k),rs=rson(k),mid=((l+r)>>1);
	build(ls,l,mid),build(rs,mid+1,r);
	arr[k].val=(arr[ls].val+arr[rs].val)%mod;
}
inline void modify(int k,int l,int r,int l1,int r1,int t,LL d1,LL d2)
{
	if(l>=l1 && r<=r1)
	{
		arr[k].lazy1=(arr[k].lazy1+d1)%mod;
		arr[k].lazy2=(arr[k].lazy2+d2)%mod;
		return ;
	}
	int ls=lson(k),rs=rson(k),mid=((l+r)>>1);
	arr[k].val=(arr[k].val+((arr[k].lazy1*(f[half+r+3]-f[half+l+2]))%mod)+((arr[k].lazy2*(f[half+r+2]-f[half+l+1]))%mod)+f[half+t+r1-l1+2]-f[half+t+1])%mod;
	arr[ls].lazy1=(arr[ls].lazy1+arr[k].lazy1)%mod,arr[ls].lazy2=(arr[ls].lazy2+arr[k].lazy2)%mod;
	arr[rs].lazy1=(arr[rs].lazy1+arr[k].lazy1)%mod,arr[rs].lazy2=(arr[rs].lazy2+arr[k].lazy2)%mod;
	arr[k].lazy1=arr[k].lazy2=0;
	if(r1<=mid)
	{
		modify(ls,l,mid,l1,r1,t,d1,d2);
		return ;
	}
	if(l1>mid)
	{
		modify(rs,mid+1,r,l1,r1,t,d1,d2);
		return ;
	}
	modify(ls,l,mid,l1,mid,t,d1,d2),modify(rs,mid+1,r,mid+1,r1,mid+t-l1+1,d1,d2);
}
inline LL query(int k,int l,int r,int l1,int r1)
{
	if(l>=l1 && r<=r1)return (arr[k].val+((arr[k].lazy1*(f[half+r+3]-f[half+l+2]))%mod)+((arr[k].lazy2*(f[half+r+2]-f[half+l+1]))%mod))%mod;
	int ls=lson(k),rs=rson(k),mid=((l+r)>>1);
	arr[k].val=(arr[k].val+((arr[k].lazy1*(f[half+r+3]-f[half+l+2]))%mod)+((arr[k].lazy2*(f[half+r+2]-f[half+l+1]))%mod))%mod;
	arr[ls].lazy1=(arr[ls].lazy1+arr[k].lazy1)%mod,arr[ls].lazy2=(arr[ls].lazy2+arr[k].lazy2)%mod;
	arr[rs].lazy1=(arr[rs].lazy1+arr[k].lazy1)%mod,arr[rs].lazy2=(arr[rs].lazy2+arr[k].lazy2)%mod;
	arr[k].lazy1=arr[k].lazy2=0;
	if(r1<=mid)return query(ls,l,mid,l1,r1);
	if(l1>mid)return query(rs,mid+1,r,l1,r1);
	return (query(ls,l,mid,l1,mid)+query(rs,mid+1,r,mid+1,r1))%mod;
}
inline void init()
{
	f[half+1]=f[half+2]=1;
	for(int i=half+3;i<=Mx;++i)
		f[i]=(f[i-1]+f[i-2])%mod;
	for(int i=half;i>=0;--i)
		f[i]=(f[i+2]-f[i+1])%mod;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	build(1,1,n);
}
int main()
{
	init();
	while(m--)
	{
		scanf("%d%d%d",&opt,&x,&y);
		if(opt==1)modify(1,1,n,x,y,1,f[half-x+1],f[half-x]);
		else printf("%lld\n",(query(1,1,n,x,y)+mod)%mod);
	}
	return 0;
}