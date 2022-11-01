#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

int b,k,a[100005];

int main()
{
	scanf("%d%d",&b,&k);
	for (int i=1;i<=k;i++) scanf("%d",&a[i]);
	int ans=0,s=1;
	for (int i=k;i>=1;i--) ans^=a[i]*s%2,s=s*b%2;
	if (!ans) puts("even");
	else puts("odd");
	return 0;
}