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
        bool ok=1;
        if((2*a-b)%3) ok=0;
        if((2*b-a)%3) ok=0;
        if(2*a-b<0) ok=0;
        if(2*b-a<0) ok=0;
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}