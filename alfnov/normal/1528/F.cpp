#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int powdv(int x,int y)
{
	if(y<=0)return 1;
	int ans=1;
	while(y)
	{
		if(y&1)ans=1ll*ans*x%mod;
		y>>=1;
		x=1ll*x*x%mod;
	}
	return ans;
}
int a[1<<19],b[1<<19],c[1<<19],ap[1<<19],bp[1<<19],cp[1<<19],z[1<<19],fc[1<<19];
void ntt(int *c,int *d,int n,int zf)
{
	if(n==1)
	{
		*d=*c;
		return;
	}
	int m=n>>1;
	for(int i=0;i<m;i++)z[i]=c[i<<1],z[i+m]=c[i<<1|1];
	for(int i=0;i<n;i++)c[i]=z[i];
	ntt(c,d,m,zf);
	ntt(c+m,d+m,m,zf);
	int o1=powdv(3,(mod-1)/n),o=1;
	if(zf==-1)o1=powdv(o1,mod-2);
	for(int i=0;i<m;i++)
	{
		int a1=d[i],a2=d[i+m];
		d[i]=(a1+1ll*o*a2)%mod,d[i+m]=(a1-1ll*o*a2)%mod;
		o=1ll*o*o1%mod;
	}
	for(int i=0;i<m;i++)z[i<<1]=c[i],z[i<<1|1]=c[i+m];
	for(int i=0;i<n;i++)c[i]=z[i];
}
int main()
{
	int k,n;
	cin>>k>>n;
	int len=1<<18;
	if(n<=100)len=1<<10;
	fc[0]=1;
	for(int i=1;i<=n;i++)fc[i]=1ll*fc[i-1]*i%mod;
	for(int i=0;i<=n;i++)
	{
		a[i]=1ll*powdv(i,n)*powdv(fc[i],mod-2)%mod;
		b[i]=1ll*powdv(-1,i)*powdv(fc[i],mod-2)%mod;
	}
	ntt(a,ap,len,1);
	ntt(b,bp,len,1);
	for(int i=0;i<len;i++)cp[i]=1ll*ap[i]*bp[i]%mod;
	ntt(cp,c,len,-1);
	for(int i=0;i<=n;i++)c[i]=(1ll*powdv(len,mod-2)*c[i]%mod+mod)%mod;
	int ans=0,gg=1;
	for(int i=1;i<=n;i++)
	{
		gg=1ll*gg*(k-i+1)%mod;
		ans+=1ll*c[i]*gg%mod*powdv(k+1,k-i)%mod;
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}