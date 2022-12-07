#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=105;
int a[N];
int n,k;
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&k);
		for (int u=1;u<=n;u++) scanf("%d",&a[u]);
		for (int u=1;u<n;u++)
		{
			int t=min(a[u],k);
			a[u]=a[u]-t;
			k=k-t;
			a[n]+=t;
		}
		for (int u=1;u<=n;u++) printf("%d ",a[u]);
		printf("\n");
	}
	return 0;
}