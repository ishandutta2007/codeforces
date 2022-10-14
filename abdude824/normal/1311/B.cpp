#include <cstdio>
#include <algorithm>
using namespace std;
int a[105],p[105];
int main()
{
    int t,n,m,pp;
    bool f;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=m;i++)
            scanf("%d",&p[i]);
        sort(p+1,p+m+1);
        pp=1;
        for(int i=2;i<=m;i++)
            if(p[i]!=p[i-1]+1)
            {
                sort(a+p[pp],a+p[i-1]+2);
                pp=i;
            }
        sort(a+p[pp],a+p[m]+2);
        f=false;
        for(int i=1;i<=n;i++)
            if(a[i]<a[i-1])
            {
                f=true;
                break;
            }
        if(f)
            printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}