#include<bits/stdc++.h>
using namespace std;
const int N=505;
#define ll long long
int n,x[N];ll q[N],d[N][N],e[N][N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%lld",&e[i][j]);
	for(int i=1;i<=n;i++)scanf("%d",&x[i]);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)d[i][j]=e[x[n-i+1]][x[n-j+1]];
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		for(int i=1;i<=k;i++)for(int j=1;j<=k;j++)q[n-k+1]+=d[i][j];
	}
	for(int i=1;i<=n;i++)printf("%lld ",q[i]);
	return 0;
}