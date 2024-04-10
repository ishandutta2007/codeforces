#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const double eps=1e-7;
const int N=105;
const int M=10005;
int n;
double x;
double f[N][M];
int a[N];
double sum=0;
int S;
int main()
{
	memset(f,0,sizeof(f));
	scanf("%d%lf",&n,&x);
	f[0][0]=1;
	for (int u=1;u<=n;u++) 
	{
		scanf("%d",&a[u]);
		sum=sum+a[u];S=S+a[u];
		
		for (int j=u;j>=1;j--)
		for (int i=S;i>=a[u];i--)
		f[j][i]+=f[j-1][i-a[u]];
	}
	
	double ans=0;
	double now=1;
	for (int k=0;k<n;k++)
	{
		if (k==0) now=1;
		else now=now/k*(n-k+1);
		for (int i=0;i<=S;i++)
		{
		//	if (f[k][i]>eps) printf("%d %d %lf %lf %lf\n",k,i,f[k][i],min((sum-i)/(n-k),(1.0*n/(n-k)+1)*(x/2)));
			ans=ans+f[k][i]/now*min((sum-i)/(n-k),(1.0*n/(n-k)+1)*(x/2));
		}
	}
	printf("%.8lf\n",ans);
	return 0;
}