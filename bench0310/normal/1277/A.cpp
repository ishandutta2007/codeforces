#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n;
        scanf("%I64d",&n);
        int res=0;
        for(int o=1;o<=9;o++)
        {
            long long x=o;
            while(x<=n)
            {
                res++;
                x=10*x+o;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}