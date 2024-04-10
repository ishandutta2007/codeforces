#include"bits/stdc++.h"
using namespace std;
int a[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long x,y;
        scanf("%lld%lld",&x,&y);
        if(y%x==0)printf("%lld\n",x);
        else if(x<y)
        {
            printf("%lld\n",(y/x*x+y)/2);
        }
        else if(x>y)printf("%lld\n",(x+y));
    }
    return 0;
}
/*
4
12 16
12 21302
*/