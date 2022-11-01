#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=100005;

int n,a[N],b[N];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	if (a[1]!=b[1]||a[n]!=b[n]) {puts("No");return 0;}
	for (int i=n;i>1;i--) a[i]-=a[i-1],b[i]-=b[i-1];
	std::sort(a+1,a+n+1);std::sort(b+1,b+n+1);
	for (int i=1;i<=n;i++)
		if (a[i]!=b[i]) {puts("No");return 0;}
	puts("Yes");
	return 0;
}