#include<bits/stdc++.h>
#define LL long long
#define mod 998244353
using namespace std;
int n,k,t=0,t1,t2;
LL ans=0;
int p[72],p1[2022],p2[2022],f[2022];
int dp[2022][2022];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void solve1()
{
	dp[0][0]=1;
	for(int i=1;i<=n+1;++i)
	{
		for(int j=1;j<=n;++j)(dp[i-1][j]+=dp[i-1][j-1])%=mod;
		for(int j=1;j<=i;++j)(dp[i][j]+=dp[i-j][j])%=mod;
	}
	for(int i=1;i<=n;++i)(ans+=dp[i][i])%=mod;
}
inline void solve2()
{
	f[0]=1;
	for(int i=1;((i*(i+1))>>1)<=n;++i)for(int j=((i*(i+1))>>1);j<=n;++j)(f[j]+=f[j-((i*(i+1))>>1)])%=mod;
	for(int i=1;i<=n;++i)(ans+=f[i])%=mod;
}
inline bool check()
{
	for(int i=1;i<=t;++i)p1[i]=p[i];
	t1=t,sort(p1+1,p1+t+1);
	for(int i=1,o;i<k;++i)
	{
		for(t2=o=0;t2<t1;)++t2,p2[t2]=p1[t2];
		for(int j=1;j<=t2;++j)o+=(t2-j+1)*p2[j];
		if(o>n)return 0;
		t1=0;
		for(int j=t2;j;--j)for(int k=1;k<=p2[j];++k)p1[++t1]=t2-j+1;
	}
	return 1;
}
inline bool dfs(int x)
{
	if(!check())return 0;
	++ans;
	for(int i=x,o;;++i)
	{
		p[++t]=i,o=dfs(i),--t;
		if(!o)return 1;
	}
}
inline void solve3()
{
	dfs(1),--ans;
}
int main()
{
	read(n),read(k);
	if(k==1)solve1();
	else if(k==2)solve2();
	else solve3();
	return 0&printf("%lld",ans);
}