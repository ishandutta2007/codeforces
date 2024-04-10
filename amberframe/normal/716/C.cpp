#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <vector>
using namespace std;

typedef long long LL;
const int maxn = 100005;
LL n;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("root.in","r",stdin);
		freopen("root.out","w",stdout);
	#endif
	scanf("%lld",&n);puts("2");
	for (LL i=2;i<=n;i++) {
		printf("%lld\n",i*(i+1)*(i+1)-(i-1));
	}
	return 0;
}