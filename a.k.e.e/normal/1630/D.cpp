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
const int INF=0x3f3f3f3f;

int n,m;
int a[MAXN],b[MAXN],d;
ll work()
{
	ll res=0;
	for(int i=1;i<=d;++i)
	{
		int w=0;
		int best=INF;
		ll sum=0;
		for(int j=i;j<=n;j+=d)
		{
			if(a[j]<0)w^=1;
			sum+=abs(a[j]);
			chkmin(best,abs(a[j]));
		}
		if(w)sum-=2*best;
		res+=sum;
	}
	return res;
}
void solve()
{
	readint(n),readint(m);
	for(int i=1;i<=n;++i)readint(a[i]);
	d=0;
	for(int i=1;i<=m;++i)readint(b[i]),d=__gcd(d,b[i]);
	ll res=work();
	for(int i=1;i<=d;++i)a[i]=-a[i];
	chkmax(res,work());
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