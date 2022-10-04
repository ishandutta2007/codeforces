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
const int MAXN=500015,INF=0x3f3f3f3f;

int n;
ll a[MAXN],pa[MAXN];
int b[MAXN],fen[MAXN],val[MAXN],mv;
int dp[MAXN];
void md(int x,int d){for(++x;x<=n+1;x+=(x&-x))chkmax(fen[x],d);}
int qr(int x){int s=-INF;for(++x;x;x-=(x&-x))chkmax(s,fen[x]);return s;}
void solve()
{
	readint(n);
	for(int i=1;i<=n;++i)readint(a[i]);
	pa[0]=0;for(int i=1;i<=n;++i)pa[i]=(a[i]+=a[i-1]);
	sort(pa,pa+n+1);
	for(int i=0;i<=n;++i)b[i]=lower_bound(pa,pa+n+1,a[i])-pa;
	memset(fen,-0x3f,sizeof(int)*(n+5));
	memset(val,-0x3f,sizeof(int)*(n+5));
	mv=-INF;
	dp[0]=val[b[0]]=mv=0;
	md(b[0],0);
	for(int i=1;i<=n;++i)
	{
		dp[i]=qr(b[i]-1)+i;
		chkmax(dp[i],val[b[i]]);
		chkmax(dp[i],mv-i);
		md(b[i],dp[i]-i);
		chkmax(val[b[i]],dp[i]);
		chkmax(mv,dp[i]+i);
	}
	printf("%d\n",dp[n]);
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