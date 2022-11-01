#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        long long c,sum;
        scanf("%I64d%I64d",&c,&sum);
        long long a=sum/c;
        long long b=sum%c;
        long long res=(c-b)*a*a+b*(a+1)*(a+1);
        printf("%I64d\n",res);
    }
    return 0;
}