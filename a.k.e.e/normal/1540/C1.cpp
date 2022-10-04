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
const int MAXN=105;

int n,m,c[MAXN],b[MAXN],x[MAXN];
int f[MAXN][MAXN*MAXN];

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n);
	for(int i=1;i<=n;++i)readint(c[i]);
	for(int i=2;i<=n;++i)readint(b[i]),b[i]+=b[i-1];
	readint(m);
	for(int i=1;i<=m;++i)readint(x[i]);
	int sum=0,pre=0;
	f[0][0]=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=max(sum,0);j<=pre;++j)
			for(int k=0;k<=c[i];++k)
				inc(f[i][j+k],f[i-1][j]);
		sum+=b[i]+x[1];
		pre+=c[i];
	}
	int res=0;
	for(int j=max(sum,0);j<=pre;++j)
		inc(res,f[n][j]);
	printf("%d\n",res);
	return 0;
}