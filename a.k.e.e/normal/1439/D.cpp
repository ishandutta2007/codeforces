#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define pb push_back
#define mp make_pair
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void readint(T &x)
{
	int f=1;char c;x=0;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
int MOD;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
const int MAXN=505;

int n,m,f[MAXN],g[MAXN],fac[MAXN],ifac[MAXN];
int df[MAXN][MAXN],dg[MAXN][MAXN];

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n),readint(m),readint(MOD);
	fac[0]=1;for(int i=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%MOD;
	ifac[n]=qmi(fac[n],MOD-2);for(int i=n;i;--i)ifac[i-1]=1ll*ifac[i]*i%MOD;
	f[0]=1;g[0]=0;
	for(int i=1;i<=m;++i)
		for(int j=0;j<i;++j)
			inc(f[i],1ll*f[j]*f[i-1-j]%MOD*(i+1)%MOD*fac[i-1]%MOD*ifac[j]%MOD*ifac[i-1-j]%MOD),
			inc(g[i],(1ll*g[j]*f[i-1-j]%MOD*(i+1)+1ll*g[i-1-j]*f[j]%MOD*(i+1)
				+1ll*f[i-1-j]*f[j]%MOD*((1ll*j*(j+1)/2+1ll*(i-1-j)*(i-j)/2)%MOD))%MOD
				*fac[i-1]%MOD*ifac[j]%MOD*ifac[i-1-j]%MOD);
	df[0][0]=1;dg[0][0]=0;
	for(int i=1;i<=n+1;++i)
		for(int j=0;j<=m && j<=i;++j)
			for(int k=0;k<i && k<=j;++k)
				inc(df[i][j],1ll*df[i-k-1][j-k]*f[k]%MOD*fac[j]%MOD*ifac[k]%MOD*ifac[j-k]%MOD),
				inc(dg[i][j],(1ll*dg[i-k-1][j-k]*f[k]+1ll*df[i-k-1][j-k]*g[k])%MOD*fac[j]%MOD*ifac[k]%MOD*ifac[j-k]%MOD);
	printf("%d\n",dg[n+1][m]);
	return 0;
}