#include<bits/stdc++.h>
#define LL long long
#define Mod 1000000007
using namespace std;
const int mod[3]={998244353,167772161,1004535809},G[3]={3,3,3},Gi[3]={332748118,55924054,334845270};
int k,o,len=65536,t=15;
LL n,res,M,ans=0,z;
int r[65542],A[65542],B[65542],C[65542],E[65542];
int w[3][65542],wi[3][65542],D[3][65542];
LL fac[65542],inv[65542];
inline void add(int &x,int y)
{
	if((x+=y)>=mod[o])x-=mod[o];
}
inline LL Pow(int a,int b,int mod)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=Pow(a,b>>1,mod);
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
inline void init()
{
	fac[0]=1;for(int i=1;i<=k;++i)fac[i]=(fac[i-1]*i)%Mod;
	inv[k]=Pow(fac[k],Mod-2,Mod);for(int i=k;i;--i)inv[i-1]=(inv[i]*i)%Mod;
	int len=65536,mid=(len>>1),W,Wi;
	for(o=0;o<3;++o)
	{
		W=Pow(G[o],(mod[o]-1)/len,mod[o]),Wi=Pow(Gi[o],(mod[o]-1)/len,mod[o]);
		w[o][mid]=wi[o][mid]=1;
		for(int i=mid+1;i<len;++i)w[o][i]=((LL)w[o][i-1]*W)%mod[o],wi[o][i]=((LL)wi[o][i-1]*Wi)%mod[o];
		for(int i=mid-1;i>=0;--i)w[o][i]=w[o][i<<1],wi[o][i]=wi[o][i<<1];
	}
	for(int i=1;i<len;++i)r[i]=((r[i>>1]>>1)|((i&1)<<t));
}
inline LL _C(int a,int b)
{
	return (((fac[a]*inv[b])%Mod)*inv[a-b])%Mod;
}
inline void NTT(int *A,bool O)
{
	for(int i=0;i<len;++i)if(i<r[i])swap(A[i],A[r[i]]);
	for(int i=1,x;i<len;i<<=1)for(int j=0;j<len;j+=(i<<1))for(int k=0;k<i;++k)x=((LL)(O? w[o][i+k]:wi[o][i+k])*A[i+j+k])%mod[o],add(A[i+j+k]=A[j+k],mod[o]-x),add(A[j+k],x);
}
inline int merge(int a,int b,int c)
{
	M=mod[0],res=a,z=(((((b-res)%mod[1])*Pow(M%mod[1],mod[1]-2,mod[1]))%mod[1])+mod[1])%mod[1],res+=z*M,M*=mod[1];
	return z=(((((c-res)%mod[2])*Pow(M%mod[2],mod[2]-2,mod[2]))%mod[2])+mod[2])%mod[2],(res+z*(M%Mod))%Mod;
}
inline void Mul(int *A,int *B,int m)
{
	LL t=Pow(2,m,Mod),tmp=1,iv;
	for(int i=0;i<len;++i)A[i]=(((tmp*A[i])%Mod)*inv[i])%Mod,B[i]=((LL)B[i]*inv[i])%Mod,(tmp*=t)%=Mod;
	for(o=0;o<3;++o)
	{
		for(int i=0;i<len;++i)D[o][i]=A[i],E[i]=B[i];
		NTT(D[o],1),NTT(E,1);
		for(int i=0;i<len;++i)D[o][i]=((LL)D[o][i]*E[i])%mod[o];
		NTT(D[o],0),iv=Pow(len,mod[o]-2,mod[o]);
		for(int i=0;i<len;++i)D[o][i]=(iv*D[o][i])%mod[o];
	}
	for(int i=0;i<len;++i)A[i]=((LL)merge(D[0][i],D[1][i],D[2][i])*fac[i])%Mod;
}
int main()
{
	scanf("%lld%d",&n,&k);
	if(n>k)return 0&puts("0");
	init();
	for(int i=0;i<len;++i)A[i]=(!i),B[i]=(i>0);
	for(int i=n,t=1;i;i>>=1,t<<=1)
	{
		if(i&1)
		{
			for(int j=0;j<len;++j)C[j]=B[j];
			Mul(A,C,t);
		}
		for(int j=0;j<len;++j)C[j]=B[j];
		Mul(B,C,t);
	}
	for(int i=0;i<=k;++i)(ans+=_C(k,i)*A[i])%=Mod;
	return 0&printf("%lld\n",ans);
}