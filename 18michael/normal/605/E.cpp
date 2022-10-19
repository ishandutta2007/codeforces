#include<bits/stdc++.h>
#define eps 1e-15
#define inf 0x3f3f3f3f
using namespace std;
int n,num;
double f[1002],g[1002],h[1002]={};
double p[1002][1002];
bool vis[1002]={};
int main()
{
	scanf("%d",&n),f[0]=inf+1;
	for(int i=1;i<=n;++i)
	{
		f[i]=(i==n? 0:inf),g[i]=1;
		for(int j=1;j<=n;++j)scanf("%lf",&p[i][j]),p[i][j]/=100;
	}
	for(int i=1;i<=n;++i)
	{
		num=0;
		for(int j=1;j<=n;++j)if(!vis[j] && f[j]<f[num])num=j;
		vis[num]=1;
		for(int j=1;j<=n;++j)if(!vis[j])h[j]+=f[num]*p[j][num]*g[j],g[j]*=1-p[j][num],f[j]=(fabs(1-g[j])<eps? inf:(h[j]+1)/(1-g[j]));
	}
	return 0&printf("%.15lf",f[1]);
}