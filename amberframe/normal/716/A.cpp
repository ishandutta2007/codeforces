#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <vector>
using namespace std;

typedef long long LL;
const int maxn = 100005;

int n,c,a[maxn],cnt=1;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("computer.in","r",stdin);
		freopen("computer.out","w",stdout);
	#endif
	scanf("%d %d",&n,&c);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=2;i<=n;i++)
	if (a[i]-a[i-1]>c) cnt=1;
	else ++cnt;
	printf("%d",cnt);
	return 0;
}