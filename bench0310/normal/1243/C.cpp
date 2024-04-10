#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    scanf("%I64d",&n);
    int cnt=0;
    long long d=1;
    for(long long i=2;i*i<=n;i++)
    {
        if((n%i)==0)
        {
            cnt++;
            d=i;
        }
        while((n%i)==0) n/=i;
    }
    if(n>1)
    {
        cnt++;
        d=n;
    }
    if(cnt==1) printf("%I64d\n",d);
    else printf("1\n");
    return 0;
}