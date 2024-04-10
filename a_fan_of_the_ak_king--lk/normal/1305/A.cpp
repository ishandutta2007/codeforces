#include<bits/stdc++.h>
using namespace std;
const int M=1000000007,P=998244353;
const int N=100005,E=262144;
#define inf 2147483647
int n,i,j,a[N],b[N],t;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
			scanf("%d",&a[i]);
		for(i=1;i<=n;++i)
			scanf("%d",&b[i]);
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		for(i=1;i<=n;++i)
			printf("%d ",a[i]);
		printf("\n");
		for(i=1;i<=n;++i)
			printf("%d ",b[i]);
		printf("\n");
	}
}