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
        long long c=9;
        long long res=0;
        while(c<=b)
        {
            res+=a;
            c=10*c+9;
        }
        printf("%I64d\n",res);
    }
    return 0;
}