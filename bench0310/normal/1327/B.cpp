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
        vector<bool> vis(n+1,0);
        int idx=0;
        for(int o=1;o<=n;o++)
        {
            int k;
            scanf("%d",&k);
            vector<int> v(k);
            for(int i=0;i<k;i++) scanf("%d",&v[i]);
            bool ok=0;
            for(int x:v)
            {
                if(vis[x]==0)
                {
                    vis[x]=1;
                    ok=1;
                    break;
                }
            }
            if(!ok) idx=o;
        }
        if(idx==0) printf("OPTIMAL\n");
        else
        {
            int x;
            for(int i=1;i<=n;i++) if(vis[i]==0) x=i;
            printf("IMPROVE\n");
            printf("%d %d\n",idx,x);
        }
    }
    return 0;
}