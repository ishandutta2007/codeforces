#include<bits/stdc++.h>
#define LL long long
#define mod 1000000007
using namespace std;
int p,X,l,t=0,i0=0,i1=1;
LL tmp,res,ans;
int A[3332];
LL f[2][3332][2][2];
char s[1002];
inline LL C(LL x)
{
	return ((x*(x-1))>>1)%mod;
}
int main()
{
	scanf("%d%d%s",&p,&X,s+1),l=strlen(s+1);
	for(int i=1;i<=l;++i)s[i]^=48;
	for(int i=1;i<l+1-i;++i)swap(s[i],s[l+1-i]);
	for(;l;)
	{
		tmp=0,res=1;
		for(int i=1;i<=l;++i)tmp=(tmp+res*s[i])%p,res=(res*10)%p;
		A[++t]=tmp,tmp=0;
		for(int i=l;i;--i)tmp=tmp*10+s[i],s[i]=tmp/p,tmp%=p;
		for(;l && !s[l];--l);
	}
	f[0][0][1][0]=1;
	for(int i=t;i;--i,i0^=1,i1^=1)
	{
		for(int j=0;j<=t;++j)
			for(int k=0;k<2;++k)
				for(int l=0;l<2;++l)
					f[i1][j][k][l]=0;
		for(int j=0;j<=t;++j)
		{
			if(f[i0][j][0][0])
			{
				(f[i1][j][0][0]+=f[i0][j][0][0]*C(p+1))%=mod,--p;
				(f[i1][j][0][1]+=f[i0][j][0][0]*C(p+1))%=mod,++p;
			}
			if(f[i0][j][0][1])
			{
				(f[i1][j+1][0][0]+=f[i0][j][0][1]*C(p))%=mod,++p;
				(f[i1][j+1][0][1]+=f[i0][j][0][1]*C(p))%=mod,--p;
			}
			if(f[i0][j][1][0])
			{
				(f[i1][j][0][0]+=f[i0][j][1][0]*C(A[i]+1))%=mod,(f[i1][j][1][0]+=f[i0][j][1][0]*(A[i]+1))%=mod,--A[i];
				(f[i1][j][0][1]+=f[i0][j][1][0]*C(A[i]+1))%=mod,(f[i1][j][1][1]+=f[i0][j][1][0]*(A[i]+1))%=mod,++A[i];
			}
			if(f[i0][j][1][1])
			{
				(f[i1][j+1][0][0]+=f[i0][j][1][1]*(C(p)-C(p-A[i])))%=mod,(f[i1][j+1][1][0]+=f[i0][j][1][1]*(p-1-A[i]))%=mod,++p;
				(f[i1][j+1][0][1]+=f[i0][j][1][1]*(C(p)-C(p-A[i])))%=mod,(f[i1][j+1][1][1]+=f[i0][j][1][1]*(p-1-A[i]))%=mod,--p;
			}
		}
	}
	for(int i=X;i<=t;++i)(ans+=f[i0][i][0][0]+f[i0][i][1][0])%=mod;
	return 0&printf("%lld",(ans+mod)%mod);
}