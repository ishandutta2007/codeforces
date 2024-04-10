#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
const int MOD=998244353;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){(x+=y)>=MOD?x-=MOD:0;}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
const int MAXN=100005;

int n,a[MAXN],dp[2][MAXN];
int m,b[MAXN],fac[MAXN];

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(m);
	for(int i=1;i<=m;++i)readint(b[i]);
	for(int u=1;u<=m;u+=b[u])
	{
		if(u+b[u]-1>m)return 0*printf("0\n");
		for(int i=u;i<=u+b[u]-1;++i)
			if(b[i]!=b[u])return 0*printf("0\n");
		a[++n]=(b[u]>1);
	}
	dp[a[1]][1]=1+a[1];
	for(int i=2;i<=n;++i)
		if(!a[i])
		{
			for(int j=i-1;j;--j)
				inc(dp[0][j+1],dp[0][j]),
				inc(dp[0][j+1],dp[1][j]),
				inc(dp[1][j],dmy(dp[0][j]<<1)),
				dp[0][j]=0;
		}
		else
		{
			for(int j=i-1,u;j;--j)
				u=dmy(dp[0][j]<<1),
				inc(dp[1][j+1],u),
				inc(dp[1][j+1],dmy(dp[1][j]<<1)),
				inc(dp[1][j],u),
				dp[0][j]=0;
		}
	fac[0]=1;
	for(int i=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%MOD;
	int res=0;
	for(int i=1;i<=n;++i)
	{
		int t=1ll*fac[i]*(dp[0][i]+dp[1][i])%MOD;
		if((n-i)&1)inc(res,MOD-t);
		else inc(res,t);
	}
	printf("%d\n",res);
	return 0;
}