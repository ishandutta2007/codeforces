#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long x,y;
        scanf("%I64d%I64d",&x,&y);
        if(x-y>1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}