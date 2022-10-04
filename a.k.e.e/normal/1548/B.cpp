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
const int MAXN=200005,MAXK=19;

int n,res;
ll a[MAXN],b[MAXN];
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int _log2[MAXN];
ll f[MAXN][MAXK];
ll qgcd(int l,int r)
{
	int t=_log2[r-l+1];
	return gcd(f[l][t],f[r-(1<<t)+1][t]);
}
void solve()
{
	readint(n);
	for(int i=1;i<=n;++i)readint(a[i]);
	res=1;
	for(int i=1;i<n;++i)b[i]=abs(a[i]-a[i+1]);
	_log2[0]=-1;
	for(int i=1;i<n;++i)f[i][0]=b[i],_log2[i]=_log2[i>>1]+1;
	for(int j=1;j<MAXK;++j)
		for(int i=1;i+(1<<j)-1<n;++i)
			f[i][j]=gcd(f[i][j-1],f[i+(1<<j-1)][j-1]);
	for(int r=1,l=1;r<n;++r)
	{
		while(l<=r && qgcd(l,r)==1)++l;
		chkmax(res,r-l+2);
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
	readint(T);
	while(T--)solve();
	return 0;
}