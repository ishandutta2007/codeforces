#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>

using namespace std;
const int maxn = 10005;

int a[maxn],b[maxn],n,m;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("past.in","r",stdin);
		freopen("past.out","w",stdout);
	#endif
	scanf("%d %d",&n,&m);
	if (m>1) {puts("Yes");return 0;}
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++) scanf("%d",&b[i]);
	for (int i=1;i<=n;i++)
		a[i]?0:a[i]=b[m];
	for (int i=1;i<n;i++)
	if (a[i]>a[i+1]) {puts("Yes");return 0;}
	puts("No");
	return 0;
}