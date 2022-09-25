#include<cstdio>
using namespace std;
#define N 200050
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int n,v[N],is[N*2],su[N],g[N];
long long as;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&v[i]),g[i]=gcd(i,n);
	for(int i=1;i<=n;i++)if(!(n%i))
	{
		for(int j=1;j<=n;j++)is[j]=is[j+n]=su[j]=0;
		for(int j=1;j<n;j++)su[j]=(g[j]==g[i])+su[j-1];
		for(int j=1;j<=g[i];j++)
		{
			int mx=0;
			for(int k=j;k<=n;k+=g[i])if(mx<v[k])mx=v[k];
			for(int k=j;k<=n;k+=g[i])if(mx==v[k])is[k]=is[n+k]=1;
		}
		for(int j=n*2-1;j>=1;j--)is[j]=is[j]?is[j+1]+1:0;
		for(int j=1;j<=n;j++)as+=su[is[j]>=n?n-1:is[j]];
	}
	printf("%lld\n",as);
}