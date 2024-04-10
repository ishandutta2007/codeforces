#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
typedef long long LL;

bool prime(int n) {
	for (int i=2;i*i<=n;i++)
	if (n%i==0) return false;
	return true;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("taxes.in","r",stdin);
		freopen("taxes.out","w",stdout);
	#endif
	int n;scanf("%d",&n);
	if (n<=3) puts("1");
	else if (n%2==0) puts("2");
	else if (prime(n)) puts("1");
	else if (prime(n-2)) puts("2");
	else puts("3");
	return 0;
}