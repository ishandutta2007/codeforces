#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
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
inline int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
const int MAXN=55;

int n;

int main()
{
	#ifndef ONLINE_JUDGE
//	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
			printf("%lld ",(i&1)?(1ll<<(i+j)):0);
		putchar('\n');
	}
	fflush(stdout);
	
	int Q;
	readint(Q);
	while(Q--)
	{
		ll s;
		readint(s);
		for(int i=3,x=1,y=1;i<=2*n;++i)
		{
			printf("%d %d\n",x,y);
			if(s&(1ll<<i))
			{
				if(x&1)++y;
				else ++x;
			}
			else if(x&1)++x;
			else ++y;
		}
		printf("%d %d\n",n,n);
		fflush(stdout);
	}
	return 0;
}