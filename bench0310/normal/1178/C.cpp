#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long w,h;
	scanf("%I64d%I64d",&w,&h);
	long long mod=998244353;
	long long res=1;
	for(long long i=0;i<w+h;i++)
    {
        res*=2;
        if(res>=mod) res%=mod;
    }
    printf("%I64d\n",res);
	return 0;
}