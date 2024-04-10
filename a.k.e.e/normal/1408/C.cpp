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
template <typename T> void chkmin(T &x,T y){x>y?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
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
const int MAXN=100005;

int n,a[MAXN];
double f[2][MAXN];
void solve()
{
	readint(n),readint(a[n+1]);
	for(int i=1;i<=n;++i)readint(a[i]);
	for(int i=1;i<=n+1;++i)f[0][i]=f[0][i-1]+(a[i]-a[i-1])*(1.0/i);
	f[1][n+1]=0;
	for(int i=n;i>=0;--i)f[1][i]=f[1][i+1]+(a[i+1]-a[i])*(1.0/(n-i+1));
	int p=0;
	for(int i=1;i<=n+1;++i)if(f[0][i]>f[1][i]){p=i;break;}
	printf("%.9lf\n",((a[p]-a[p-1])+f[0][p-1]*p+f[1][p]*(n-p+2))/(n+2));
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