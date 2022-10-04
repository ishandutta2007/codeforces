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
const int MAXN=200005,N=200000;

int n,m;
int fac[MAXN],ifac[MAXN],a[MAXN],b[MAXN];
int fen[MAXN];
void add(int x,int d){for(;x<=N;x+=(x&-x))fen[x]+=d;}
int qs(int x){int s=0;for(;x;x-=(x&-x))s+=fen[x];return s;}
void solve()
{
	fac[0]=1;for(int i=1;i<=N;++i)fac[i]=1ll*fac[i-1]*i%MOD;
	ifac[N]=qmi(fac[N],MOD-2);for(int i=N;i;--i)ifac[i-1]=1ll*ifac[i]*i%MOD;
	readint(n),readint(m);
	for(int i=1,x;i<=n;++i)readint(x),++a[x];
	for(int i=1;i<=m;++i)readint(b[i]);
	int mul=1;
	for(int i=1;i<=N;++i)add(i,a[i]),mul=1ll*mul*ifac[a[i]]%MOD;
	int res=0;
	for(int i=1;i<=n;++i)
	{
		if(i>m)break;
		inc(res,1ll*qs(b[i]-1+(i==n&&n<m))*mul%MOD*fac[n-i]%MOD);
		if(!a[b[i]])break;
		mul=1ll*mul*a[b[i]]%MOD;
		--a[b[i]];
		add(b[i],-1);
	}
	printf("%d\n",res);
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;
	T=1;
	while(T--)solve();
	return 0;
}