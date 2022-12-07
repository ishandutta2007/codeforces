#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const LL  N=105;
LL s[N][N];
LL a[N],b[N];
LL n,m;
int main()
{
	scanf("%lld%lld",&n,&m);
	LL suma=0,sumb=0;
	for (LL u=1;u<=n;u++) 
	{
		scanf("%lld",&a[u]);
		suma=suma^a[u];
	}
	for (LL u=1;u<=m;u++) 
	{
		scanf("%lld",&b[u]);
		sumb=sumb^b[u];
	}
	if (suma!=sumb)	{printf("NO\n");return 0;}
	printf("YES\n");
	for (LL u=1;u<n;u++) s[u][1]=a[u];
	for (LL u=2;u<=m;u++) s[n][u]=b[u];
	s[n][1]=(b[1]^suma^a[n]);
	for (LL u=1;u<=n;u++)
	{
		for (LL i=1;i<=m;i++)
			printf("%lld ",s[u][i]);
		printf("\n");
	}
	return 0;
}