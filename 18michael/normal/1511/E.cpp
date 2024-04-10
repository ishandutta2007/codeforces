#include<bits/stdc++.h>
#define LL long long
#define Mx 300000
#define mod 998244353
using namespace std;
int n,m,t,w=0;LL ans=0;
LL pw[300002],f[300002];
string s[300002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	f[0]=f[1]=0,pw[0]=1;
	for(int i=1;i<=Mx;++i)pw[i]=(pw[i-1]<<1)%mod;
	for(int i=2;i<=Mx;++i)f[i]=(f[i-1]+f[i-2]*2+pw[i-2])%mod;
	read(n),read(m);
	for(int i=0;i<n;++i)
	{
		cin>>s[i];
		for(int j=0;j<m;++j)w+=(s[i][j]=='o');
	}
	for(int i=0;i<n;++i)
	{
		t=0;
		for(int j=0;j<m;++j)
		{
			if(s[i][j]=='o')++t;
			else ans=(ans+f[t]*pw[w-t])%mod,t=0;
		}
		ans=(ans+f[t]*pw[w-t])%mod;
	}
	for(int i=0;i<m;++i)
	{
		t=0;
		for(int j=0;j<n;++j)
		{
			if(s[j][i]=='o')++t;
			else ans=(ans+f[t]*pw[w-t])%mod,t=0;
		}
		ans=(ans+f[t]*pw[w-t])%mod;
	}
	return 0&printf("%lld",ans);
}