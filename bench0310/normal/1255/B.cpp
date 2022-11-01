#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int res=0;
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            res+=(2*a);
        }
        if(m<n||n==2) printf("-1\n");
        else
        {
            printf("%d\n",res);
            for(int i=0;i<n;i++) printf("%d %d\n",i+1,(i+1)%n+1);
        }
    }
    return 0;
}