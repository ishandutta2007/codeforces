#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=100005,md=1000000007;
int n,m,i,j,k,x,a[N],c[N+105][105],w[105][N];
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
		scanf("%d",a+i);
	c[0][0]=1;
	for(i=1;i<=n+100;++i)
	{
		c[i][0]=1;
		for(j=1;j<=i&&j<=100;++j)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%md;
	}
	while(m--)
	{
		scanf("%d%d%d",&i,&j,&k);
		w[k][i]=(w[k][i]+1)%md;
		for(x=k;x>=0;--x)
			w[x][j+1]=(w[x][j+1]-c[j-i+k-x][k-x]+md)%md;
	}
	for(x=100;x>=0;--x)
		for(i=1;i<=n;++i)
			w[x][i]=(1ll*w[x][i]+w[x+1][i]+w[x][i-1])%md;
	for(i=1;i<=n;++i)
		printf("%d ",(w[0][i]+a[i])%md);
	return 0;
}