#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
template <typename T> bool chkmin(T &x,T y){return y<x?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
/*const int MOD=1000000007;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
int inv(int x){return qmi(x,MOD-2);}*/
const int MAXN=9,INF=0x3f3f3f3f;

int n,m,a[9],b[9],c[9][9];
struct State
{
	int f[9];
	int hash()const
	{
		int res=0,cur=1;
		for(int i=1;i<=n;++i)res+=f[i]*cur,cur*=(a[i]+1);
		return res;
	}
};
int dp[9][9][16000][5];
State cals(int h)
{
	State s;
	for(int i=1;i<=n;++i)
		s.f[i]=h%(a[i]+1),h/=(a[i]+1);
	return s;
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n),readint(m);int chk=0;
	for(int i=1;i<=n;++i)readint(a[i]),chk+=a[i];
	for(int i=1;i<=m;++i)readint(b[i]),chk-=b[i];
	if(chk>0)return 0*printf("-1\n");
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			readint(c[i][j]);
	
	memset(dp,0x3f,sizeof(dp));
	int mul=1;
	for(int i=1;i<=n;++i)mul*=(a[i]+1);
	dp[1][1][mul-1][0]=0;
	for(int j=1;j<=m;++j)
	{
		for(int i=1;i<=n;++i)
			for(int s=0;s<mul;++s)
			{
				State t=cals(s);
				for(int r=0;r<=b[j];++r)
				{
					chkmin(dp[j][i+1][s][r],dp[j][i][s][r]);
					for(int k=1;k<=t.f[i] && k+r<=b[j];++k)
					{
						t.f[i]-=k;
						chkmin(dp[j][i+1][t.hash()][r+k],dp[j][i][s][r]+c[i][j]);
						t.f[i]+=k;
					}
				}
			}
		for(int s=0;s<mul;++s)
			for(int r=0;r<=b[j];++r)
				chkmin(dp[j+1][1][s][0],dp[j][n+1][s][r]);
	}
	printf("%d\n",dp[m+1][1][0][0]);
	return 0;
}