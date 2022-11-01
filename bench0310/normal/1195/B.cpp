#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,k;
    scanf("%I64d%I64d",&n,&k);
    long long l=0,r=n;
    while(l<r-1)
    {
        long long m=(l+r)/2;
        long long t=n-m;
        if(((t*(t+1)/2)-m)<k) r=m;
        else l=m;
    }
    printf("%I64d\n",l);
	return 0;
}