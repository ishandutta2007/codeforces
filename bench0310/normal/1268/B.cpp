#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    long long a=0,b=0;
    while(n--)
    {
        long long t;
        scanf("%I64d",&t);
        if(n&1)
        {
            a+=(t+1)/2;
            b+=t/2;
        }
        else
        {
            b+=(t+1)/2;
            a+=t/2;
        }
    }
    printf("%I64d\n",min(a,b));
    return 0;
}