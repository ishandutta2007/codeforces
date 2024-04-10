#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long x,y,a,b;
        scanf("%I64d%I64d%I64d%I64d",&x,&y,&a,&b);
        if(((y-x)%(a+b))==0) printf("%I64d\n",(y-x)/(a+b));
        else printf("-1\n");
    }
    return 0;
}