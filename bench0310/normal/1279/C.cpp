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
        vector<int> a(n+1),b(m+1);
        vector<int> p(n+1);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            p[a[i]]=i;
        }
        for(int i=1;i<=m;i++) scanf("%d",&b[i]);
        int d=0;
        long long res=0;
        for(int i=1;i<=m;i++)
        {
            if(p[b[i]]<=d) res++;
            else
            {
                d=p[b[i]];
                res+=(2*(p[b[i]]-i)+1);
            }
        }
        printf("%I64d\n",res);
    }
    return 0;
}