#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    vector<vector<int>> d(n,vector<int>(n,0));
    for(int o=0;o<n;o++) for(int i=0;i<n;i++) scanf("%d",&d[o][i]);
    vector<vector<vector<pair<int,int>>>> best(n,vector<vector<pair<int,int>>>(n,vector<pair<int,int>>()));
    for(int o=0;o<n;o++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==o||j==i) continue;
                best[o][i].push_back({d[o][j]+d[j][i],j});
            }
            sort(best[o][i].begin(),best[o][i].end());
        }
    }
    vector<int> v(k+1,0);
    int res=(1<<30);
    function<void(int)> solve=[&](int pos)->void
    {
        if(pos==k)
        {
            int now=0;
            for(int i=1;i<k;i+=2)
            {
                for(auto [dist,id]:best[v[i-1]][v[i+1]])
                {
                    bool ok=1;
                    for(int j=0;j<=k;j+=2) if(id==v[j]) ok=0;
                    if(ok)
                    {
                        now+=dist;
                        break;
                    }
                }
            }
            res=min(res,now);
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                v[pos]=i;
                solve(pos+2);
            }
        }
    };
    solve(2);
    printf("%d\n",res);
    return 0;
}