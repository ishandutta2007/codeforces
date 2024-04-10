#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,x,a,b;
        scanf("%d%d%d%d",&n,&x,&a,&b);
        if(a>b) swap(a,b);
        if(x>=a-1)
        {
            x-=(a-1);
            a=1;
        }
        else
        {
            a-=x;
            x=0;
        }
        if(x>=n-b)
        {
            x-=(n-b);
            b=n;
        }
        else
        {
            b+=x;
            x=0;
        }
        printf("%d\n",b-a);
    }
    return 0;
}