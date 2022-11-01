#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,a,b;
        scanf("%d%d%d",&n,&a,&b);
        bool ok=0;
        for(int i=0;i<a;i++)
        {
            int c;
            scanf("%d",&c);
            if(c==n) ok=1;
        }
        for(int i=0;i<b;i++)
        {
            int c;
            scanf("%d",&c);
            if(c==n) ok=0;
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}