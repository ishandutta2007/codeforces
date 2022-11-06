#include<bits/stdc++.h>
using namespace std;
#define NN 500000
#define mod 998244353
int n,m,inv2,c[NN],d[NN],A[NN],B[NN],C[NN],D[NN],r[NN];
int pw(int a,int b){int res=1;for(;b;b>>=1,a=1ll*a*a%mod)if(b&1)res=1ll*res*a%mod;return res;}
void ntt(int *x,int nn,int f)
{
	int N=1,l=0;for(;N<nn;N<<=1)l++;
	for(int i=0;i<N;i++)r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
	for(int i=1;i<N;i++)if(i<r[i])swap(x[i],x[r[i]]);
	for(int i=1;i<N;i<<=1)
	{
		int wn=pw(3,(mod-1)/(i<<1));
		for(int j=0;j<N;j+=(i<<1))
		{
			int w=1;
			for(int k=0;k<i;k++,w=1ll*w*wn%mod)
			{
				int u=x[j+k],v=1ll*x[i+j+k]*w%mod;
				x[j+k]=(u+v)%mod;x[i+j+k]=(u-v+mod)%mod;
			}
		}
	}
	if(f==-1)
	{
		reverse(x+1,x+nn);
		for(int i=0,inv=pw(N,mod-2);i<N;i++)x[i]=1ll*x[i]*inv%mod;
	}
}
void Inv(int *a,int *b,int len)
{
	if(len==1){b[0]=pw(a[0],mod-2);return;}
	Inv(a,b,len>>1);
	for(int i=0;i<len;i++)A[i]=a[i],B[i]=b[i];
	ntt(A,len<<1,1);ntt(B,len<<1,1);
	for(int i=0;i<(len<<1);i++)A[i]=1ll*A[i]*B[i]%mod*B[i]%mod;
	ntt(A,len<<1,-1);
	for(int i=0;i<len;i++)b[i]=(b[i]+b[i]+mod-A[i])%mod;
	for(int i=0;i<(len<<1);i++)A[i]=B[i]=0;
}
void Sqrt(int *a,int *b,int len)
{
	if(len==1){b[0]=a[0];return;}
	Sqrt(a,b,len>>1);
	for(int i=0;i<=len;i++)C[i]=a[i];
	Inv(b,D,len);
	ntt(C,len<<1,1);ntt(D,len<<1,1);
	for(int i=0;i<(len<<1);i++)D[i]=1ll*D[i]*C[i]%mod;
	ntt(D,len<<1,-1);
	for(int i=0;i<len;i++)b[i]=1ll*(D[i]+b[i])%mod*inv2%mod;
	for(int i=0;i<=(len<<1);i++)C[i]=D[i]=0;
}
int main()
{
	scanf("%d%d",&n,&m);inv2=pw(2,mod-2);
	for(int i=1;i<=n;i++){int x;scanf("%d",&x);d[x]++;}
	int nn=1;while(nn<=m)nn<<=1;
	for(int i=0;i<nn;i++)d[i]=(-4*d[i]+mod)%mod;d[0]++;
	Sqrt(d,c,nn);c[0]=(c[0]+1)%mod;
	for(int i=0;i<nn;i++)d[i]=0;
	Inv(c,d,nn);
	for(int i=0;i<=m;i++)d[i]=(d[i]+d[i])%mod;
	for(int i=1;i<=m;i++)printf("%d\n",d[i]);
	return 0; 
}