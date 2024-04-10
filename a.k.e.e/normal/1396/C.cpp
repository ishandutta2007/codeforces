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
const int MAXN=1000005;

int n;
ll r1,r2,r3,d,a[MAXN];
ll e[MAXN],f[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n),readint(r1),readint(r2),readint(r3),readint(d);
	for(int i=1;i<=n;++i)readint(a[i]);
	ll sum=(2*n-1)*d;
	for(int i=1;i<=n;++i)e[i]=r1*a[i]+r3-min(min(r2+r1,r1*(a[i]+2)),r1*a[i]+r3)-d,sum+=min(min(r2+r1,r1*(a[i]+2)),r1*a[i]+r3);
	f[1]=e[1];
	for(int i=2;i<=n;++i)f[i]=min(f[i-2],f[i-1]+e[i]);
	for(int i=1;i<n;++i)chkmin(f[n],f[i]+e[n]);
	chkmin(f[n],d);
	printf("%lld\n",f[n]+sum);
	return 0;
}