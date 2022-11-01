#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,m;
	scanf("%I64d%I64d",&n,&m);
	long long b=0;
	if(n&1) b=(2*(n/2)*(n/2+1)/2);
	else b=(2*(n/2-1)*(n/2)/2+n/2);
	long long res=0;
	while(m--)
    {
        long long x,d;
        scanf("%I64d%I64d",&x,&d);
        res+=(n*x);
        if(d>=0) res+=(n*(n-1)*d/2);
        else res+=b*d;
    }
    printf("%.15f\n",(double)res/n);
	return 0;
}