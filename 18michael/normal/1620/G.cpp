#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
#define mod 998244353
using namespace std;
int n,Mx;
LL ans=0;
short cnt[24][26],cnt1[8388608][26];
int one[8388608];
LL f[8388608],g[8388608];
char s[20002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int lowbit(int x)
{
	return x&(-x);
}
int main()
{
	read(n),Mx=(1<<n);
	for(int i=0,l;i<n;++i)
	{
		scanf("%s",s),l=strlen(s),g[1<<i]=i+1;
		for(int j=0;j<l;++j)++cnt[i][s[j]-'a'];
	}
	for(int i=1,i0;i<Mx;++i)
	{
		f[i]=((one[i]=one[i>>1]+(i&1))&1? 1:-1);
		if((i0=lowbit(i))==i)
		{
			for(int j=0;j<26;++j)f[i]=(f[i]*((cnt1[i][j]=cnt[one[i-1]][j])+1))%mod;
			continue;
		}
		for(int j=0;j<26;++j)f[i]=(f[i]*((cnt1[i][j]=min(cnt1[i0][j],cnt1[i^i0][j]))+1))%mod;
		g[i]=g[i0]+g[i^i0];
	}
	for(int i=1;i<Mx;i<<=1)for(int j=0;j<Mx;j+=(i<<1))for(int k=0;k<i;++k)(f[i+j+k]+=f[j+k])%=mod;
	for(int i=1;i<Mx;++i)ans^=((f[i]+mod)%mod)*g[i]*one[i];
	return 0&printf("%lld",ans);
}