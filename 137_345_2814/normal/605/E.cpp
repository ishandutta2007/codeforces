#include<cstdio>
using namespace std;
#define N 1050
int s[N][N],n,vis[N];
double as[N],ls[N];
int main()
{
	scanf("%d",&n);
	if(n==1){printf("0\n");return 0;}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	scanf("%d",&s[i][j]);
	for(int i=1;i<n;i++)as[i]=0,ls[i]=1-s[i][n]/100.0;
	vis[n]=1;
	for(int i=1;i<n;i++)
	{
		int su=1;
		for(int j=1;j<=n;j++)if((as[su]+1)/(1-ls[su])>(as[j]+1)/(1-ls[j])&&!vis[j])su=j;
		vis[su]=1;
		for(int j=1;j<=n;j++)if((as[su]+1)/(1-ls[su])<(as[j]+1)/(1-ls[j]))
		as[j]+=ls[j]*s[j][su]/100*(as[su]+1)/(1-ls[su]),ls[j]-=ls[j]*s[j][su]/100;
	}
	printf("%.10lf\n",(as[1]+1)/(1-ls[1]));
}