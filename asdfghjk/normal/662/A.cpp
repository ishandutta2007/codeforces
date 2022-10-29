#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1000005,md=998244353;
typedef long long ll;
int n,i,j,k,e,p[N],lmt,len,rt[N],ome[N],rome[N],g[N],h[N],w1[N],w2[N],inv[N];
ll a[N],b[N],w,xxj[65];
inline void Read(ll &x)
{
	char c;
	while((c=getchar())<'0'||c>'9');
	x=c-'0';
	while((c=getchar())>='0'&&c<='9')
		x=x*10+c-'0';
}
void ntt(int a[N],bool t)
{
	for(int i=0;i<len;++i)
		if(i<rt[i])
			swap(a[i],a[rt[i]]);
	for(int l=2;l<=len;l<<=1)
	{
		int m=l>>1;
		for(int i=0;i<len;i+=l)
			for(int j=0;j<m;++j)
			{
				int w=1ll*(t?ome[len/l*j]:rome[len/l*j])*a[i+j+m]%md;
				a[i+j+m]=(a[i+j]-w+md)%md;
				a[i+j]=(a[i+j]+w)%md;
			}
	}
	if(!t)
		for(int i=0;i<len;++i)
			a[i]=1ll*a[i]*inv[len]%md;
}
void merge(int l,int r)
{
	if(l==r)
	{
		p[l]=2;
		return;
	}
	int mid=(l+r)/2,i;
	merge(l,mid);
	merge(mid+1,r);
	lmt=0;
	while((1<<lmt)<=r-l+1)
		++lmt;
	len=1<<lmt;
	ome[0]=rome[0]=1;
	for(i=1;i<len;++i)
	{
		rt[i]=0;
		for(j=0;j<lmt;++j)
			if((1<<j)&i)
				rt[i]|=1<<(lmt-j-1);
		ome[i]=1ll*ome[i-1]*w1[len]%md,rome[i]=1ll*rome[i-1]*w2[len]%md;
	}
	for(i=0;i<len;++i)
		g[i]=h[i]=0;
	for(i=l;i<=mid;++i)
		g[i-l]=p[i];
	for(i=mid+1;i<=r;++i)
		h[i-mid-1]=p[i];
	ntt(g,true);
	ntt(h,true);
	for(i=0;i<len;++i)
		g[i]=1ll*g[i]*h[i]%md;
	ntt(g,false);
	for(i=0;i<len;++i)
	{
		g[i+1]+=g[i]/10;
		g[i]%=10;
	}
	for(i=l;i<=r;++i)
		p[i]=g[i-l];
	/*printf("%d %d\n",l,r);
	for(i=l;i<=r;++i)
		printf("%d ",p[i]);
	puts("");*/
}
inline int pw(int a,int b)
{
	int rtn=1;
	while(b)
	{
		if(b&1)
			rtn=1ll*rtn*a%md;
		a=1ll*a*a%md;
		b>>=1;
	}
	return rtn;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		Read(a[i]);
		Read(b[i]);
		b[i]^=a[i];
		w^=a[i];
	}
	e=0;
	for(i=1;i<=n;++i)
	{
		for(j=60;j>=0;--j)
			if((1ll<<j)&b[i])
			{
				if(!xxj[j])
				{
					xxj[j]=b[i];
					break;
				}
				b[i]^=xxj[j];
			}
		if(b[i]==0)
			++e;
	}
	for(j=60;j>=0;--j)
		if((1ll<<j)&w)
		{
			if(!xxj[j])
			{
				printf("1/1");
				return 0;
			}
			w^=xxj[j];
		}
	if(n-e==0)
	{
		printf("0/1");
		return 0;
	}
	for(i=1;i<=2*(n-e);++i)
	{
		w1[i]=pw(3,(md-1)/i),w2[i]=pw(w1[i],md-2);
		if(i==1)
			inv[i]=1;
		else
			inv[i]=1ll*inv[md%i]*(md-md/i)%md;
	}
	merge(1,n-e);
	for(i=n-e;p[i]==0;--i);
	for(;i>=2;--i)
		printf("%d",p[i]);
	printf("%d/",p[i]-1);
	for(i=n-e;p[i]==0;--i);
	for(;i>=1;--i)
		printf("%d",p[i]);
	return 0;
}