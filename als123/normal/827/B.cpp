#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=200005;
int n,k;
int bel[N];
int main()
{
	scanf("%d%d",&n,&k);
	if (k==2)
	{
		printf("%d\n",n-1);
		for (int u=2;u<=n;u++) printf("%d %d\n",u-1,u);
		return 0;
	}
	if (k==n-1)
	{
		printf("2\n");
		for (int u=2;u<=n;u++) printf("%d 1\n",u);
		return 0;
	}
	if (n%k==2)	printf("%d\n",2*((n-2)/k)+1);
	else if (n%k==1) printf("%d\n",2*((n-1)/k));
	else printf("%d\n",2*((n-1)/k+1));
	int id=n-k;
	for (int u=2;u<=id;u++)	printf("%d %d\n",u,max(1,u-k));
	int now=id+1;
	for (int u=id;u>=1;u--)
	{
		printf("%d %d\n",now,u);
		now++;if (now>n) break;
	}
	while (now<=n)	{printf("1 %d\n",now);now++;}
	return 0;
}