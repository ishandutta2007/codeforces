#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int a,b,n,s;
        scanf("%d%d%d%d",&a,&b,&n,&s);
        int t=(max(0,s-b))+(n-(max(0,s-b))%n)%n;
        if(a>=(t/n)&&t<=s) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}