#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=100005;
int n,m;
int tot;
int x[N],y[N];
int gcd (int x,int y)	{return x==0?y:gcd(y%x,x);}
int main()
{
	scanf("%d%d",&n,&m);
	if (m<n-1)	{printf("Impossible\n");return 0;}
	for (int u=2;u<=n;u++)	{tot++;x[tot]=1;y[tot]=u;}
	for (int u=n;u>=2;u--)
	{
		if (tot>=m) break;
		for (int i=2;i<u;i++)
			if (gcd(u,i)==1)
			{
				tot++;
				x[tot]=u;y[tot]=i;
				if (tot>=m) break;
			}
	}
	if (tot<m) printf("Impossible\n");
	else
	{
		printf("Possible\n");
		for (int u=1;u<=tot;u++)
			printf("%d %d\n",x[u],y[u]);
	}
	return 0;
}