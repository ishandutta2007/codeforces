#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> a(n+1,-1);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int m;
    scanf("%d",&m);
    const int inf=(1<<30);
    map<int,set<int>> pos;
    for(int i=1;i<=m;i++)
    {
        int b;
        scanf("%d",&b);
        pos[b].insert(i);
    }
    for(auto p:pos) pos[p.first].insert(inf);
    for(int x:a) pos[x].insert(inf);
    vector<vector<int>> dp(n+1,vector<int>(n+1,inf));
    vector<vector<int>> p(n+1,vector<int>(n+1,inf));
    dp[0][0]=0;
    for(int o=1;o<=n;o++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=o;j++)
            {
                if(a[j]>=a[o]||dp[j][i-1]==inf) continue;
                int x=*pos[a[o]].upper_bound(dp[j][i-1]);
                if(x<dp[o][i])
                {
                    dp[o][i]=x;
                    p[o][i]=j;
                }
            }
        }
    }
    int res=0;
    array<int,2> best={0,0};
    for(int o=1;o<=n;o++)
    {
        for(int i=1;i<=n;i++)
        {
            if(dp[o][i]!=inf&&i>res)
            {
                res=i;
                best={o,i};
            }
        }
    }
    printf("%d\n",res);
    vector<int> v;
    while(best[1])
    {
        v.push_back(a[best[0]]);
        best[0]=p[best[0]][best[1]];
        best[1]--;
    }
    reverse(v.begin(),v.end());
    for(int i=0;i<res;i++) printf("%d%c",v[i]," \n"[i==res-1]);
    return 0;
}