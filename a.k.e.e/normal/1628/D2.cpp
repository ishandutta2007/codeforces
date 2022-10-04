#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define pb push_back
#define mp make_pair
template <typename T> bool chkmin(T &x,T y){return y<x?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template <typename T> void readint(T &x)
{
	int f=1;char c;x=0;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
const int MOD=1000000007;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
const int MAXN=1000005,INV2=(MOD+1)/2;

int n,m,W,fac[MAXN],ifac[MAXN];
void solve()
{
	readint(n),readint(m),readint(W);
	fac[0]=1;for(int i=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%MOD;
	ifac[n]=qmi(fac[n],MOD-2);for(int i=n;i;--i)ifac[i-1]=1ll*ifac[i]*i%MOD;
	int pw2=1,res=0;
	for(int i=1;i<=m;++i)
	{
		if(m<n)inc(res,1ll*pw2*i%MOD*fac[n-i-1]%MOD*ifac[m-i]%MOD*ifac[n-m-1]%MOD);
		else if(i==m)inc(res,1ll*pw2*i%MOD);
		pw2=dmy(pw2<<1);
	}
	res=1ll*res*qmi(2,MOD-n)%MOD*W%MOD;
	printf("%d\n",res);
/*	dp[0][0]=0;
	for(int i=1;i<=n;++i)
	{
		dp[i][0]=dmy(dp[i-1][0]+1);
		for(int j=1;j<=i;++j)
			dp[i][j]=1ll*(dp[i-1][j]+dp[i-1][j-1])*INV2%MOD;
	}
	printf("%lld\n",1ll*dp[n][n-m]*W%MOD);*/
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}