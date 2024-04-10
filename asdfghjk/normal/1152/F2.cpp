#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int md=1000000007;
int n,K,m,i,j,k,ans,num[100],g[250][250],h[250][250],c[250][250];
void Add(int &x,int y)
{
	x=(x+y)%md;
}
void mult(int a[250][250],int b[250][250])
{
	for(int i=0;i<(K+1)*(1<<m);++i)
		for(int j=0;j<(K+1)*(1<<m);++j)
			c[i][j]=0;
	for(int i=0;i<(K+1)*(1<<m);++i)
		for(int j=0;j<(K+1)*(1<<m);++j)
			for(int k=0;k<(K+1)*(1<<m);++k)
				c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j])%md;
	for(int i=0;i<(K+1)*(1<<m);++i)
		for(int j=0;j<(K+1)*(1<<m);++j)
			a[i][j]=c[i][j];
}
int main()
{
	scanf("%d%d%d",&n,&K,&m);
	for(i=1;i<(1<<m);++i)
		num[i]=num[i^(i&-i)]+1;
	for(j=0;j<=K;++j)
		for(k=0;k<(1<<m);++k)
		{
			Add(g[j*(1<<m)+k][j*(1<<m)+((k<<1)&((1<<m)-1))],1);
			if(j<K)
				Add(g[j*(1<<m)+k][(j+1)*(1<<m)+((k<<1|1)&((1<<m)-1))],num[k]+1);
		}
	h[0][0]=1;
	while(n)
	{
		if(n&1)
			mult(h,g);
		mult(g,g);
		n>>=1;
	}
	for(k=0;k<(1<<m);++k)
		ans=(ans+h[0][K*(1<<m)+k])%md;
	printf("%d",ans);
	return 0;
}