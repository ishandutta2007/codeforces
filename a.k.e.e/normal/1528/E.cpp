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
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
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
int inv(int x){return qmi(x,MOD-2);}
const int MAXN=1000005;

int n,f[MAXN],p[MAXN];

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n);
	if(n==1)return 0*printf("5\n");
	f[0]=1;p[0]=1;
	f[1]=2;p[1]=3;
	for(int i=2;i<=n;++i)
		f[i]=(1ll*f[i-1]*p[i-2]+1ll*f[i-1]*(f[i-1]+1)/2+f[i-1])%MOD,
		p[i]=dmy(p[i-1]+f[i]);
	int ans=dmy(f[n]-f[n-1]+MOD);
	inc(ans,1ll*p[n-2]*(p[n-2]+1)/2%MOD*f[n-1]%MOD);
	inc(ans,1ll*f[n-1]*(f[n-1]+1)/2%MOD*p[n-2]%MOD);
	inc(ans,1ll*f[n-1]*(f[n-1]+1)%MOD*(f[n-1]+2)%MOD*inv(6)%MOD);
	ans=dmy(ans<<1);
	for(int i=0;i<n;++i)inc(ans,1ll*(f[i]-f[i-1]+MOD)*f[n-i-1]%MOD);
	printf("%d\n",ans);
	return 0;
}