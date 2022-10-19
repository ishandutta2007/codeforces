#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int t,n,b[N],a[N],f[N];
int main()
{
    int m=50;
    for (int i=2;i<=m;++i)
    {
        for (int j=0;j<=m;++j)
            b[j]=0;
        for (int j=1;j<i;++j)
            b[f[j]^f[i-j]]=1;
        for (int j=0;j<=m+1;++j)
            if (!b[j])
            {
                f[i]=j;
                break;
            }
    }
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        int ans=0;
        for (int i=1;i<=n;++i)
        {
            scanf("%d",&a[i]);
            ans^=f[a[i]];
        }
        puts(ans?"errorgorn":"maomao90");
    }
    return 0;
}