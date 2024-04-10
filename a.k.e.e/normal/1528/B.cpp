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

int f[MAXN],a[MAXN];

int main()
{
	#ifdef LOCAL
//	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int n;
	readint(n);
	for(int i=1;i<=n;++i)
		for(int j=i*2;j<=n;j+=i)
			++a[j];
	f[0]=1;
	int cur=1;
	for(int i=1;i<=n;++i)
		f[i]=dmy(cur+a[i]),
		inc(cur,f[i]);
	printf("%d\n",f[n]);
	return 0;
}