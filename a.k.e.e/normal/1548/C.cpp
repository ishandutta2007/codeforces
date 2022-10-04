#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
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
const int MOD=1000000007,INV3=(MOD+1)/3;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
const int MAXN=3000005;

int n,Q,a[MAXN],fac[MAXN],ifac[MAXN],b[MAXN],f[MAXN];

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n),readint(Q);
	const int N=3*n+3;
	fac[0]=1;for(int i=1;i<=N;++i)fac[i]=1ll*fac[i-1]*i%MOD;
	ifac[N]=qmi(fac[N],MOD-2);for(int i=N;i;--i)ifac[i-1]=1ll*ifac[i]*i%MOD;
	for(int i=1;i<=3*n+3;++i)b[i+1]=1ll*fac[3*n+3]*ifac[i]%MOD*ifac[3*n+3-i]%MOD;
//for(int i=2;i<=3*n+4;++i)cerr<<b[i]<<" ";cerr<<endl;
	for(int i=2;i<=3*n+4;++i)f[i]=1ll*(b[i]-(f[i-2]+3ll*f[i-1])%MOD+MOD)*INV3%MOD;
	while(Q--)
	{
		int x;
		readint(x);
		printf("%d\n",f[x+2]);
	}
	return 0;
}