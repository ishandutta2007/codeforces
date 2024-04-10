#include <bits/stdc++.h>

using namespace std;

int main()
{
    const int inf=1000000000;
    int n;
    scanf("%d",&n);
    vector<pair<int,int>> v(n+1);
    v[0]={0,0};
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&v[i].first);
        v[i].second=i;
    }
    sort(v.begin(),v.end());
    vector<int> dp(n+1,inf);
    dp[0]=0;
    vector<int> p(n+1,-1);
    for(int o=1;o<=n;o++)
    {
        for(int i=o-3;i>=max(0,o-5);i--)
        {
            if(dp[o]>dp[i]+v[o].first-v[i+1].first)
            {
                dp[o]=dp[i]+v[o].first-v[i+1].first;
                p[o]=i;
            }
        }
    }
    vector<int> res(n+1,0);
    int team=1;
    int idx=n;
    while(idx)
    {
        for(int i=idx;i>p[idx];i--) res[v[i].second]=team;
        team++;
        idx=p[idx];
    }
    printf("%d %d\n",dp[n],team-1);
    for(int i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
    return 0;
}