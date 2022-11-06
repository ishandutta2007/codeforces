#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005,P=998244353;
int n,m,k,l,ans,fac[N],ifac[N],f[N*4],g[N*4],h[N*4],r[N*4],w[N*4];
inline int pls(int a,int b){a+=b;return a>=P?a-P:a;}
inline int pw(int a,int b){int r=1;for(;b;b>>=1,a=1ll*a*a%P)if(b&1)r=1ll*r*a%P;return r;}
inline void ntt(int n,int*a,int f)
{
	int l=1;while((1<<l)<n)l++;
	for(int i=1;i<n;i++)r[i]=r[i>>1]>>1|(i&1)<<(l-1);
	for(int i=0;i<n;i++)if(i<r[i])swap(a[i],a[r[i]]);
	for(int i=2;i<=n;i<<=1)
	{
		int wn=pw(3,f==1?(P-1)/i:P-1-(P-1)/i);
		for(int j=w[0]=1;j<(i>>1);j++)w[j]=1ll*w[j-1]*wn%P;
		for(int j=0;j<n;j+=i)
		{
			int*x=a+j,*y=a+j+(i>>1);
			for(int k=0;k<(i>>1);k++){int v=1ll*y[k]*w[k]%P;y[k]=pls(x[k],P-v);x[k]=pls(x[k],v);}
		}
	}
	if(f==-1)for(int i=0,iv=pw(n,P-2);i<n;i++)a[i]=1ll*a[i]*iv%P;
}
int main()
{
	scanf("%d%d%d",&n,&k,&l);m=n*2+1;
	for(int i=fac[0]=1;i<=m;i++)fac[i]=1ll*fac[i-1]*i%P;
	ifac[m]=pw(fac[m],P-2);
	for(int i=m;i;i--)ifac[i-1]=1ll*ifac[i]*i%P;
	for(int i=k;i<=n;i++)f[i]=ifac[i];
	for(int i=0;i<=n;i++)g[i]=1ll*(i&1?P-1:1)*ifac[i]%P;
	int nn=1;while(nn<=2*n+2)nn<<=1;ntt(nn,f,1);ntt(nn,g,1);
	for(int i=0;i<nn;i++)f[i]=1ll*f[i]*g[i]%P;ntt(nn,f,-1);
	for(int i=0,t=1;i<=n;i++,t=t*2%P)h[i]=1ll*fac[i]*fac[i]%P*t%P*ifac[i*2+1]%P*ifac[n-i]%P;
	for(int i=k;i<=n;i++)ans=(ans+1ll*f[i]*h[i])%P;
	printf("%d\n",1ll*ans*fac[n]%P*l%P);
	return 0;
}