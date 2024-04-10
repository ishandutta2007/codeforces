#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        bool res=1;
        if(a<=3&&b>3) res=0;
        if(a==1&&b>1) res=0;
        if(res) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}