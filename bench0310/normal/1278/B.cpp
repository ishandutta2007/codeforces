#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long a,b;
        scanf("%I64d%I64d",&a,&b);
        long long d=max(a-b,b-a);
        long long t;
        for(t=0;;t++)
        {
            if((t*(t+1)/2)<d) continue;
            if((a+b+(t*(t+1)/2))&1) continue;
            break;
        }
        printf("%I64d\n",t);
    }
    return 0;
}