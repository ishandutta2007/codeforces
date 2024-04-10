#include <bits/stdc++.h>

using namespace std;

int main()
{
    int z;
    scanf("%d",&z);
    while(z--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int l=m;
        int r=m;
        int t=0;
        bool res=1;
        for(int i=0;i<n;i++)
        {
            int now,a,b;
            scanf("%d%d%d",&now,&a,&b);
            l-=(now-t);
            r+=(now-t);
            t=now;
            if(b<l||r<a) res=0;
            l=max(l,a);
            r=min(r,b);
        }
        if(res) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}