//djq txdy
#include<cstdio>
using namespace std;
#define N 523
#define ll long long
int k,n,m,as;
int s[N][2];
ll v[N][N],v2[N][N];
int main()
{
	scanf("%d",&k);n=1<<k;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%lld",&v[i][j]);
	scanf("%d",&m);for(int i=1;i<=m;i++)scanf("%d%d",&s[i][0],&s[i][1]);
	for(int d=0;d<k;d++)
	{
		for(int t=1;t<=m;t++)
		{
			int dx=(s[t][0]-1)<<d,dy=(s[t][1]-1)<<d;
			for(int i=0;i<n;i++)for(int j=0;j<n;j++)v2[(i+dx)&(n-1)][(j+dy)&(n-1)]^=v[i][j];
		}
		for(int i=0;i<n;i++)for(int j=0;j<n;j++)v[i][j]=v2[i][j],v2[i][j]=0;
	}
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)as+=!!v[i][j];
	printf("%d\n",as);
}