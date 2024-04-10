#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
typedef long long LL;
const int maxn = 1500005;
const int mod = 998244353;
const int inf = 1<<28;

LL QuickPow(LL p,LL k)
{
	LL res=1ll;
	while (k<0) k+=mod-1;
	while (k) {
		if (k&1) (res*=p)%=mod;
		(p*=p)%=mod;k>>=1;
	}
	return res;
}
int rv[maxn],f[maxn],g[maxn];
int inc(int u,int v) {u+=v;u>=mod?u-=mod:0;return u;}
int dec(int u,int v) {u-=v;u<0?u+=mod:0;return u;}
void fft(int *f,int len,int idft)
{
	for (int i=1;i<len;i++)
		if (rv[i]<i) swap(f[rv[i]],f[i]);
	for (int p=2;p<=len;p<<=1)
	{
		int wn=QuickPow(3,(mod-1)/p*idft);
		for (int i=0;i<len;i+=p)
		{
			int w=1;
			for (int j=i;j<i+p/2;j++)
			{
				int u=f[j],v=(LL)f[j+p/2]*w%mod;
				f[j]=inc(u,v);f[j+p/2]=dec(u,v);
				w=(LL)w*wn%mod;
			}
		}
	}
	if (idft==1) return ;
	int inc=QuickPow(len,-1);
	for (int i=0;i<len;i++)
		f[i]=(LL)f[i]*inc%mod;
}
char s[maxn],t[maxn];int n,m,K,len,ans,w[maxn];
void solve(char ch)
{
	memset(f,0,sizeof(int)*len);
	memset(g,0,sizeof(int)*len);
	for (int i=0;i<m;i++) g[m-i]=(t[i]==ch);
	for (int i=0,las=-inf;i<n;i++)
	{
		if (s[i]==ch) las=i;
		if (i-las<=K) f[i]=1;
	}
	for (int i=n-1,las=inf;i>=0;i--)
	{
		if (s[i]==ch) las=i;
		if (las-i<=K) f[i]=1;
	}
	fft(f,len,1);fft(g,len,1);
	for (int i=0;i<len;i++)
		f[i]=(LL)f[i]*g[i]%mod;
	fft(f,len,-1);
	for (int i=0;i<n;i++)
		w[i]=inc(w[i],f[m+i]);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("biology.in","r",stdin);
		freopen("biology.out","w",stdout);
	#endif
	scanf("%d %d %d",&n,&m,&K);
	scanf("%s %s",s,t);
	len=1;while (len<n+m) len<<=1;
	for (int i=1;i<len;i++)
		rv[i]=(rv[i>>1]>>1)|(i&1?len>>1:0);
	solve('A');solve('G');solve('C');solve('T');
	for (int i=0;i<n;i++) ans+=(w[i]==m);
	printf("%d",ans);
	return 0;
}