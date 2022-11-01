#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,l,r;
	scanf("%d%d%d",&n,&l,&r);
	long long a=0;
	long long b=0;
	for(int i=0;i<l;i++) a+=(1ll<<i);
	for(int i=0;i<n-l;i++) a++;
	for(int i=0;i<r;i++) b+=(1ll<<i);
	for(int i=0;i<n-r;i++) b+=(1ll<<(r-1));
	printf("%I64d %I64d\n",a,b);
	return 0;
}