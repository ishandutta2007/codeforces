#include<cstdio>
#define LL long long
int n,x,mx=1,t=-1,G=3,Gi,mod,sum=0;
LL inv;int a[2097155],r[2097155];
LL b[2097155],c[2097155],d[2097155];
inline void swap(LL &a,LL &b)
{
	LL c=a;a=b,b=c;
}
inline LL Pow(LL a,int b)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=Pow(a,(b>>1));
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
inline void NTT(LL A[],int type)
{
	LL Wn,w,x,y;
	for(int i=0;i<mx;++i)if(i<r[i])swap(A[i],A[r[i]]);
	for(int mid=1;mid<mx;mid<<=1)
	{
		Wn=Pow(type==1? G:Gi,(mod-1)/(mid<<1));
		for(int j=0;j<mx;j+=(mid<<1))
		{
			w=1;
			for(int k=0;k<mid;++k,w=(w*Wn)%mod)x=A[j+k],y=(w*A[j+k+mid])%mod,A[j+k]=(x+y)%mod,A[j+k+mid]=(x-y)%mod;
		}
	}
}
inline void MUL(LL A[],LL B[])
{
	while(mx<=n+n)mx<<=1,++t;
	for(int i=1;i<mx;++i)r[i]=((r[i>>1]>>1)|((i&1)<<t));
	NTT(A,1),NTT(B,1);
	for(int i=0;i<=mx;++i)A[i]=(A[i]*B[i])%mod;
	NTT(A,-1),inv=Pow(mx,mod-2);
	for(int i=0;i<=n+n;++i)A[i]=(((A[i]*inv)%mod)+mod)%mod;
}
inline LL merge(LL a,LL b)
{
	return (((((b-a)*inv)%1004535809)+1004535809)%1004535809)*998244353+a;
}
int main()
{
	scanf("%d%d",&n,&x),b[0]=1;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),++b[sum+=(a[i]=(a[i]<x))];
	for(int i=0;i<=n;++i)d[n-i]=c[i]=b[i];
	mod=998244353,Gi=332748118,MUL(b,d);
	for(int i=0;i<=n;++i)d[n-i]=c[i];
	for(int i=n+1;i<mx;++i)d[i]=0;
	mod=1004535809,Gi=334845270,MUL(c,d);
	b[n]=c[n]=1LL*n*(n+1)/2,inv=Pow(998244353,1004535807);
	for(int i=0;i<n;++i)b[n]=(b[n]-b[i])%998244353,c[n]=(c[n]-c[i])%1004535809;
	b[n]=(b[n]+998244353)%998244353,c[n]=(c[n]+1004535809)%1004535809;
	for(int i=n;~i;--i)printf("%lld ",merge(b[i],c[i]));
	return 0;
}