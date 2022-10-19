#include<cstdio>
#include<vector>
#define LL long long
#define mod 1000000007
using namespace std;
int n;
int siz[100002];
LL tmp[2];
LL dp[100002][2];
vector<int> vec[100002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void dfs(int x)
{
	siz[x]=dp[x][1]=1,dp[x][0]=0;
	LL a=1,b0=1,b1=0;
	for(int i=0,v;i<vec[x].size();++i)
	{
		v=vec[x][i],dfs(v),siz[x]+=siz[v];
		tmp[0]=dp[x][0],tmp[1]=dp[x][1];
		dp[x][0]=(dp[x][0]+tmp[0]*dp[v][0]+tmp[1]*dp[v][1])%mod;
		dp[x][1]=(dp[x][1]+tmp[0]*dp[v][1]+tmp[1]*dp[v][0])%mod;
		a=(a*(dp[v][0]+1))%mod,tmp[0]=b0,tmp[1]=b1;
		b0=(b0+tmp[1]*dp[v][1])%mod,b1=(b1+tmp[0]*dp[v][1])%mod;
	}
	dp[x][0]=((dp[x][0]<<1)-b1+mod)%mod,dp[x][1]=((dp[x][1]<<1)-a+mod)%mod;
}
int main()
{
	read(n);for(int i=1;i<=n;++i)vec[i].clear();
	for(int i=2,x;i<=n;++i)read(x),vec[x].push_back(i);
	dfs(1),printf("%lld\n",(dp[1][0]+dp[1][1])%mod);
	return 0;
}