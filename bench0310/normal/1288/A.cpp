#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,d;
        scanf("%d%d",&n,&d);
        int r=1;
        while((r+1)*(r+1)<=d) r++;
        int a=d;
        for(int i=-10000;i<=10000;i++)
        {
            int x=i+r;
            if(x>=0) a=min(a,x+((d+x)/(x+1)));
        }
        if(a<=n) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}