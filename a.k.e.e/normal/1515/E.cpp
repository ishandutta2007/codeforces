#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
int MOD;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
const int MAXN=405;

int n,f[2][MAXN][MAXN][2],g[2][MAXN];

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n),readint(MOD);
	f[1][1][1][1]=1;
	for(int i=2;i<=n;++i)
	{
		memset(f[i&1],0,sizeof(f[i&1]));
		memset(g[i&1],0,sizeof(g[i&1]));
		for(int j=0;j<i;++j)
		{
			for(int k=0;k<=j;++k)
				inc(f[i&1][j+1][k+1][0],f[(i&1)^1][j][k][0]),
				inc(g[i&1][j],f[(i&1)^1][j][k][0]),
				inc(f[i&1][j+1][k+1][0],f[(i&1)^1][j][k][1]),
				inc(f[i&1][j+1][k+1][1],MOD-f[(i&1)^1][j][k][1]),
				inc(f[i&1][j+1][1][1],f[(i&1)^1][j][k][1]),
				inc(g[i&1][j],f[(i&1)^1][j][k][1]);
			inc(f[i&1][j+1][1][1],g[(i&1)^1][j]);
		}
		for(int j=0;j<=i;++j)
			for(int k=1;k<j;++k)
				for(int u=0;u<=1;++u)
					inc(f[i&1][j][k+1][u],f[i&1][j][k][u]);
	}
	int ans=0;
	for(int j=0;j<=n;++j)
		for(int k=1;k<=j;++k)
			for(int u=0;u<=1;++u)
				inc(ans,f[n&1][j][k][u]);
	printf("%d\n",ans);
	return 0;
}