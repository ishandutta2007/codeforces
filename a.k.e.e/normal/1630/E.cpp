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
const int MOD=998244353;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
const int MAXN=1000005;

int n,m,o;
int cnt[MAXN],a[MAXN];
int f[MAXN],fac[MAXN],ifac[MAXN],inv[MAXN];
void solve()
{
	readint(n);
	fac[0]=1;for(int i=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%MOD;
	ifac[n]=qmi(fac[n],MOD-2);for(int i=n;i;--i)ifac[i-1]=1ll*ifac[i]*i%MOD,inv[i]=1ll*ifac[i]*fac[i-1]%MOD;
	memset(cnt,0,sizeof(int)*(n+3));
	for(int i=1,x;i<=n;++i)readint(x),++cnt[x];
	m=0;
	for(int i=1;i<=n;++i)if(cnt[i])a[++m]=cnt[i];
	if(m==1)
	{
		printf("1\n");
		return;
	}
	o=0;
	for(int i=1;i<=m;++i)o=__gcd(o,a[i]);
	for(int i=1;i<=o;++i)f[i]=1;

	int rep=0,req=0;
	for(int i=1;i<=o;++i)
	{
		if(o%i)continue;
		int t=1ll*n/i*(n/i-1)%MOD,mul=1;
		for(int j=1;j<=m;++j)
			inc(t,MOD-1ll*a[j]/i*(a[j]/i-1)%MOD),
			mul=1ll*mul*ifac[a[j]/i]%MOD;
		int p=1ll*fac[n/i-2]*t%MOD*mul%MOD*i%MOD;
		int q=1ll*fac[n/i-1]*mul%MOD;
		inc(rep,1ll*p*f[i]%MOD);
		inc(req,1ll*q*f[i]%MOD);
		for(int j=2*i;j<=o;j+=i)
			if(o%j==0)inc(f[j],MOD-1ll*f[i]*inv[j/i]%MOD);
	}
	int fin=1ll*rep*qmi(req,MOD-2)%MOD;
	printf("%d\n",fin);
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