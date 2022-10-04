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
const ll INF=0x3f3f3f3f3f3f3f3fll;
const int MAXN=200005;

int n;
ll a[MAXN],pre[MAXN];
void solve()
{
	readint(n);
	for(int i=1;i<=n;++i)readint(a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)pre[i]=pre[i-1]+a[i];
	if(pre[n]+a[n]*(n-2)<0){printf("INF\n");return;}
	if(pre[n]+a[1]*(n-2)>0){printf("INF\n");return;}
	ll res=-INF;
	for(int i=1;i<=n;++i)
	{
		ll sum=a[1]*(pre[n]-pre[i]);
		sum+=a[n]*pre[i];
		sum-=a[n]*a[1];
		sum-=a[i]*(pre[i]+a[n]*i);
		sum-=a[i]*(pre[n]-pre[i]+a[1]*(n-i));
		sum+=a[i]*(a[n]+a[1]);
		chkmax(res,sum);
	}
	printf("%lld\n",res);
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