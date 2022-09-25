#include<cstdio>
using namespace std;
#define N 105
typedef unsigned long long ull;

typedef __uint128_t L;

struct FastMod {
  ull b, m;

  FastMod(ull b) : b(b), m(ull((L(1) << 64) / b)) {}

  ull operator()(ull a) {
    ull q = (ull) ((L(m) * a) >> 64);
    ull r = a - q * b;  // can be proven that 0 <= r < 2*b
    return r >= b ? r - b : r;
  }
} R(2);
int n,m,k,p,f[N][N],g[N][N],c[N][N];
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&p);
	R=FastMod(p);
	int tp=1;
	for(int i=1;i<=n;i++)tp=R(1ll*tp*i),f[i][1]=tp;
	for(int i=0;i<=n;i++)c[i][0]=c[i][i]=1;
	for(int i=2;i<=n;i++)for(int j=1;j<i;j++)c[i][j]=R(c[i-1][j]+c[i-1][j-1]);
	for(int i=2;i<=m;i++)
	{
		f[0][0]=1;
		for(int j=0;j<n;j++)
		for(int a=0;a<=j;a++)if(f[j][a])
		for(int l=0;j+l<n;l++)
		for(int b=0;a+b<=k&&b<=l;b++)if(f[l][b])
		g[j+l+1][a+b]=R(g[j+l+1][a+b]+1ll*R(1ll*f[j][a]*f[l][b])*c[j+l][j]);
		for(int j=1;j<=n;j++)
		for(int l=0;l<=k;l++)
		f[j][l]=g[j][l],g[j][l]=0;
	}
	printf("%d\n",f[n][k]);
}