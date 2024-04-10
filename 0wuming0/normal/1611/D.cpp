#include"bits/stdc++.h"
using namespace std;
int p[200005];
int b[200005];
long long w[200005];
int ans[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",b+i);
        for(int i=1;i<=n;i++)scanf("%d",p+i);
        for(int i=1;i<=n;i++)w[i]=-1;
        if(b[p[1]]!=p[1])
        {
            printf("-1\n");
            continue;
        }
        w[p[1]]=0;
        ans[p[1]]=0;
        long long now=0;
        for(int i=2;i<=n;i++)
        {
            if(w[b[p[i]]]==-1)
            {
                printf("-1\n");
                goto ne;
            }
            w[p[i]]=now+1;
            ans[p[i]]=now+1-w[b[p[i]]];
            now++;
        }
        for(int i=1;i<=n;i++)printf("%d%c",ans[i]," \n"[i==n]);
        ne:;
    }
    return 0;
}