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
//nx+(n-1)y=a[i]
//y=a[i]-n(x+y)

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n);
	for(int i=1;i<=n;++i)readint(a[i]);
	if(n==1)return 0*printf("1 1\n0\n1 1\n0\n1 1\n%d\n",-a[1]);
	printf("1 %d\n",n);
	for(int i=1;i<=n;++i)printf("%lld ",-1ll*(a[i]/n+a[i]%n)*n);
	printf("\n2 %d\n",n);
	for(int i=2;i<=n;++i)printf("%lld ",1ll*(a[i]%n)*(n-1));
	printf("\n1 1\n");
	printf("%lld\n",-a[1]+1ll*(a[1]/n+a[1]%n)*n);
	return 0;
}