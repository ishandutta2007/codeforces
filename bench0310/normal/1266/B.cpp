#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long x;
        scanf("%I64d",&x);
        if(x>14&&1ll<=(x%14)&&(x%14)<=6ll) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}