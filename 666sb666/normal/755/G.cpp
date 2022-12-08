#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
#define GC getchar()
#define PC putchar
inline void read(int&n)
{int x=0,f=1;char ch=GC;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=GC;}while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=GC;n=x*f;}
int outputarray[20];
inline void write(int k)
{int num=0;if(k<0)PC('-'),k=-k;do{outputarray[++num]=k%10,k/=10;}while(k);while(num)PC(outputarray[num--]+'0');puts("");}
const int N=1<<16,mod=998244353;
typedef long long LL;
int n,k,seq[100],len=0,p;
LL a[N],b[N],c[N],d[N],e[N],f[N],g[N],h[N],x[N],y[N],z[N],u[N];
inline LL powmod(LL a,LL b){LL ans=1;while(b){if(b&1)ans=ans*a%mod;a=a*a%mod;b>>=1;}return ans;}
inline LL inv(LL x){return powmod(x,mod-2);}
inline void trans(LL*a,LL*b,LL*c){for(int i=0;i<=k;i++)c[i]=((b[i]+(i>0?b[i-1]:0))%mod+(i>0?a[i-1]:0))%mod;}
inline void transform(int n,LL*x,int type)
{
	for(int i=0,j=0;i<n;i++)
	{
		if(i>j)swap(x[i],x[j]);
		for(int k=n>>1;(j^=k)<k;k>>=1);
	}
	for(int i=2;i<=n;i<<=1)
	{
		int m=i>>1;
		LL wn=powmod(3,(mod-1)/i),w=1;
		if(type)wn=inv(wn);
		for(int k=0;k<m;k++)
		{
			for(int j=0;j<n;j+=i)
			{
				LL z=x[j+k+m]*w%mod;
				x[j+k+m]=(x[j+k]-z+mod)%mod;
				x[j+k]=(x[j+k]+z)%mod;
			}
			w=w*wn%mod;
		}
	}
	if(type)
	{
		LL nn=inv(n);
		for(int i=0;i<n;i++)x[i]=x[i]*nn%mod;
	}
}
int main()
{
	read(n),read(k);
	b[0]=1;
	trans(a,b,c);
	memcpy(a,b,sizeof(a));memcpy(b,c,sizeof(a));
	trans(a,b,c);
	memcpy(a,b,sizeof(a));memcpy(b,c,sizeof(a));
	trans(a,b,c);
	if(n==1){for(int i=1;i<=k;i++)printf("%I64d ",a[i]);puts("");return 0;}
	if(n==2){for(int i=1;i<=k;i++)printf("%I64d ",b[i]);puts("");return 0;}
	if(n==3){for(int i=1;i<=k;i++)printf("%I64d ",c[i]);puts("");return 0;}
	int m=n;
	while(m>5)
	{
		if(m%2)seq[++len]=2,seq[++len]=1;
		else seq[++len]=1;
		m/=2;
	}
	while(m>3)seq[++len]=2,m--;
	reverse(seq+1,seq+len+1);
	p=1;while(p<(2*k+1))p<<=1;
	for(int i=1;i<=len;i++)
	{
		if(seq[i]==1)
		{
			memcpy(x,a,sizeof(a));
			memcpy(y,b,sizeof(a));
			memcpy(z,c,sizeof(a));
			transform(p,x,0);
			transform(p,y,0);
			transform(p,z,0);
			for(int i=0;i<p;i++)d[i]=x[i]*x[i]%mod,e[i]=y[i]*y[i]%mod,f[i]=z[i]*z[i]%mod,g[i]=x[i]*y[i]%mod,h[i]=y[i]*z[i]%mod;
			transform(p,d,1);
			transform(p,e,1);
			transform(p,f,1);
			transform(p,g,1);
			transform(p,h,1);
			for(int i=0;i<=k;i++)a[i]=e[i];
			for(int i=0;i<k;i++)a[i+1]=(a[i+1]+d[i])%mod;
			for(int i=0;i<=k;i++)b[i]=h[i];
			for(int i=0;i<k;i++)b[i+1]=(b[i+1]+g[i])%mod;
			for(int i=0;i<=k;i++)c[i]=f[i];
			for(int i=0;i<k;i++)c[i+1]=(c[i+1]+e[i])%mod;
		}
		if(seq[i]==2)
		{
			trans(b,c,u);
			memcpy(a,b,sizeof(a));
			memcpy(b,c,sizeof(a));
			memcpy(c,u,sizeof(a));
		}
	}
	for(int i=1;i<=k;i++)printf("%I64d ",c[i]);puts("");
	return 0;
}