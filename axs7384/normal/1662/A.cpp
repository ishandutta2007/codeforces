#include<bits/stdc++.h>
using namespace std;
const int inf=10000;
int t,n;
const int N=10005;
int a[N];
int main()
{
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        for (int i=1;i<=10;++i)
            a[i]=-inf;
        for (int i=1;i<=n;++i)
        {
            int b,d;
            scanf("%d%d",&b,&d);
            a[d]=max(a[d],b);
        }
        int ans=0;
        for (int i=1;i<=10;++i)
            ans+=a[i];
        if (ans<0)
            puts("MOREPROBLEMS");
        else
            printf("%d\n",ans);
    }
    return 0;
}