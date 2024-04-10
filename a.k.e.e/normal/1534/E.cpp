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
template <typename T> bool chkmin(T &x,T y){return y<x?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
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
int inv(int x){return qmi(x,MOD-2);}
const int MAXN=505;

int N,n,k,L,w,res,inp;
void solve(int n,int k)
{
	if(n>2*L)
	{
		vector<int> v;
		for(int i=N;i && v.size()<k-L;--i)if(i>n || i<=n-2*L)v.pb(i);
		putchar('?');for(auto i:v)printf(" %d",i);for(int i=n-L+1;i<=n;++i)printf(" %d",i);putchar('\n');fflush(stdout);
		readint(inp);res^=inp;
		putchar('?');for(auto i:v)printf(" %d",i);for(int i=n-2*L+1;i<=n-L;++i)printf(" %d",i);putchar('\n');fflush(stdout);
		readint(inp);res^=inp;
		return solve(n-2*L,k);
	}
	putchar('?');for(int i=1;i<=n/2;++i)printf(" %d",i);for(int i=n+1;i<=n+k-n/2;++i)printf(" %d",i);putchar('\n');fflush(stdout);
	readint(inp);res^=inp;
	putchar('?');for(int i=n/2+1;i<=n;++i)printf(" %d",i);for(int i=n+1;i<=n+k-n/2;++i)printf(" %d",i);putchar('\n');fflush(stdout);
	readint(inp);res^=inp;
}

int main()
{
	#ifdef LOCAL
//	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n),readint(k);N=n;
	if((n&1) && !(k&1))
	{
		printf("-1\n");
		fflush(stdout);
		return 0;
	}
	if(n==k)
	{
		putchar('?');for(int i=1;i<=n;++i)printf(" %d",i);putchar('\n');fflush(stdout);
		readint(inp);res^=inp;
		printf("! %d\n",res);
		return 0;
	}
	L=min(k,n-k);
	if(k&1)w=n&1;
	else w=(1+(n-k+2*L-1)/(2*L)*2<(n+2*L-1)/(2*L)*2);
	if(w)
	{
		putchar('?');for(int i=n-k+1;i<=n;++i)printf(" %d",i);putchar('\n');fflush(stdout);
		readint(inp);res^=inp;
		n-=k;
	}
	solve(n,k);
	printf("! %d\n",res);
	return 0;
}