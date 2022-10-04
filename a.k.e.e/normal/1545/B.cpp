#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define pb push_back
#define mp make_pair
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
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
const int MAXN=100005;

int n,a[MAXN],fac[MAXN],ifac[MAXN];
char str[MAXN];
void solve()
{
	readint(n);scanf("%s",str+1);
	fac[0]=1;for(int i=1;i<=n;++i)a[i]=str[i]-'0',fac[i]=1ll*fac[i-1]*i%MOD;
	ifac[n]=qmi(fac[n],MOD-2);for(int i=n;i;--i)ifac[i-1]=1ll*ifac[i]*i%MOD;
	int c1=0,c2=0;
	for(int i=n;i;--i)
		if(a[i]==1&&a[i-1]==1)a[i]=a[i-1]=-1,++c1;
		else if(!a[i])++c2;
	printf("%d\n",1ll*fac[c1+c2]*ifac[c1]%MOD*ifac[c2]%MOD);
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