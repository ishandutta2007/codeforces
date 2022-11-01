#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a=1,b=1000000000;
        for(int i=0;i<n;i++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            a=max(a,l);
            b=min(b,r);
        }
        printf("%d\n",max(0,a-b));
    }
    return 0;
}