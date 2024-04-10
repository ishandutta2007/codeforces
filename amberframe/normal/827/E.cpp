#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <vector>

using namespace std;
typedef long long LL;
typedef unsigned int u32;
#define pb push_back
const int maxn = 4000005;
const int mod = 998244353; 

namespace FFT {
	int inc(int u,int v){u+=v;return u%mod;}
	int dec(int u,int v){u-=v;return u%mod;}
	LL fpm(LL p,LL k)
	{
		LL res=1ll;
		while (k<0) k+=mod-1;
		while (k) {
			if (k&1) (res*=p)%=mod;
			(p*=p)%=mod;k>>=1;
		}
		return res;
	}
	
	int rv[maxn],_[maxn];
	void ntt(int *f,int len,int idft)
	{
		for (int i=1;i<len;i++)
			rv[i]=rv[i>>1]>>1|(i&1?len>>1:0);
		for (int i=1;i<len;i++)
			if (rv[i]<i) swap(f[rv[i]],f[i]);
		for (int p=2;p<=len;p<<=1)
		{
			int wn=fpm(3,(mod-1)/p*idft);_[0]=1;
			for (int i=1;i<p>>1;i++)
				_[i]=(LL)_[i-1]*wn%mod;
			for (int i=0;i<len;i+=p)
			{
				int *w=_;
				for (int j=i;j<i+p/2;j++)
				{
					int u=f[j],v=(LL)f[j+p/2]*(*w++)%mod;
					f[j]=inc(u,v);f[j+p/2]=dec(u,v);
				}
			}
		}
		if (idft==1) return ;
		int inc=fpm(len,-1);
		for (int i=0;i<len;i++)
			f[i]=(LL)f[i]*inc%mod;
	}
}

using FFT::ntt;

char str[maxn];int ans[maxn];
int f[maxn],g[maxn],h[maxn],L,n,o[maxn];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("string.in","r",stdin);
		//freopen("string.out","w",stdout);
	#endif
	int T;for (scanf("%d",&T);T--;) {
		scanf("%d %s",&n,str+1);L=1;
		while (L<=(n<<1)) L<<=1;
		memset(f,0,L<<2);memset(g,0,L<<2);
		for (int i=1;i<=n;i++)
			f[n-i]=(str[i]=='V'),
			g[i]=(str[i]=='K');
		ntt(f,L,1);ntt(g,L,1);
		for (int i=0;i<L;i++)
			h[i]=(LL)f[i]*g[i]%mod;
		ntt(h,L,-1);ans[0]=0;
		
		for (int i=1;i<=n;i++)
			o[i]=(h[n+i]==0&&h[n-i]==0);
		for (int i=1;i<=n;i++)
		for (int j=i<<1;j<=n;j+=i) o[i]&=o[j];
		for (int i=1;i<=n;i++)
			if (o[i]) ans[++ans[0]]=i;
		printf("%d\n",ans[0]);
		for (int i=1;i<=ans[0];i++)
			printf("%d ",ans[i]);puts("");
	}
	return 0;
}