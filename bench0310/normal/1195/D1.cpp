#include <bits/stdc++.h>

using namespace std;

const long long mod=998244353;
long long res=0;

void modify(long long &a)
{
    if(a>=mod) a%=mod;
}

void solve(long long a)
{
    long long b=1;
    while(a)
    {
        long long d=(a%10);
        a/=10;
        for(int i=0;i<2;i++)
        {
            res+=d*b;
            modify(res);
            b*=10;
            modify(b);
        }
    }
}

int main()
{
	long long n;
	scanf("%I64d",&n);
	for(int i=0;i<n;i++)
    {
        long long a;
        scanf("%I64d",&a);
        solve(a);
    }
    res*=n;
    modify(res);
    printf("%I64d\n",res);
	return 0;
}