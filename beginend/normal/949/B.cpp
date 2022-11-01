#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

LL n;
int q;

LL solve(LL x)
{
	if (x&1) return (x+1)/2;
	else return solve(n*2-1-(n*2-2-x)/2);
}

int main()
{
	scanf("%I64d%d",&n,&q);
	while (q--)
	{
		LL x;scanf("%I64d",&x);
		printf("%I64d\n",solve(x));
	}
	return 0;
}