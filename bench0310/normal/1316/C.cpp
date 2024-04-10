#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,p;
    scanf("%d%d%d",&n,&m,&p);
    int x=-1,y=-1;
    for(int i=0;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        if((t%p)&&x==-1) x=i;
    }
    for(int i=0;i<m;i++)
    {
        int t;
        scanf("%d",&t);
        if((t%p)&&y==-1) y=i;
    }
    printf("%d\n",x+y);
    return 0;
}