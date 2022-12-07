#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=100005;
int a[N],b[N];
int n;
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=n;u++) scanf("%d",&a[u]);
	for (int u=1;u<=n;u++) scanf("%d",&b[u]);
	for (int u=n;u>=1;u--) a[u]=a[u]-a[u-1];
	for (int u=n;u>=1;u--) b[u]=b[u]-b[u-1];
	if (a[1]!=b[1])	{printf("No\n");return 0;}
	sort(a+1,a+1+n);sort(b+1,b+1+n);
	for (int u=1;u<=n;u++)
	{
		if (a[u]!=b[u])
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}