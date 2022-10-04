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
const int MAXN=500005,INF=0x3f3f3f3f;

int o,res[MAXN];
void check(int x)
{
	for(int i=1;i*i<=x;++i)
		if(x%i==0)res[++o]=i,res[++o]=x/i;
}
void solve()
{
	int n,m;readint(n),readint(m);
	o=0;
	check(__gcd(n-2,m));
	check(__gcd(n-1,m-1));
	check(__gcd(n,m-2));
	if((n+m)&1)res[++o]=2;
	sort(res+1,res+o+1);
	o=unique(res+1,res+o+1)-res-1;
	printf("%d",o);
	for(int i=1;i<=o;++i)printf(" %d",res[i]);
	putchar('\n');
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