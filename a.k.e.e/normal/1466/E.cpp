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
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
const int MOD=1000000007;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
const int MAXN=500005;

int n;
ll a[MAXN];
int cnt[63];
void solve()
{
	readint(n);
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;++i)
	{
		readint(a[i]);
		for(int j=0;j<60;++j)if(a[i]&(1ll<<j))++cnt[j];
	}
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		int s=0,t=0;
		for(int j=0;j<60;++j)
			if(a[i]&(1ll<<j))inc(s,(1ll<<j)%MOD*cnt[j]%MOD),inc(t,(1ll<<j)%MOD*n%MOD);
			else inc(t,(1ll<<j)%MOD*cnt[j]%MOD);
		inc(ans,1ll*s*t%MOD);
	}
	printf("%d\n",ans);
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