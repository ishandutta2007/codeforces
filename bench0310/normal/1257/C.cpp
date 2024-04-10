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
        vector<int> v[n+1];
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            v[a].push_back(i);
        }
        int res=n+1;
        for(int o=1;o<=n;o++)
        {
            for(int i=0;i<(int)v[o].size()-1;i++)
            {
                res=min(res,v[o][i+1]-v[o][i]+1);
            }
        }
        if(res<=n) printf("%d\n",res);
        else printf("-1\n");
    }
    return 0;
}