#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=200005;

int n,k,a[N],stack[N];

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	std::sort(a+1,a+n+1);
	int top=0;
	for (int i=1;i<=n;i++)
	{
		while (top&&a[i]>stack[top]&&a[i]<=stack[top]+k) top--;
		stack[++top]=a[i];
	}
	printf("%d",top);
	return 0;
}