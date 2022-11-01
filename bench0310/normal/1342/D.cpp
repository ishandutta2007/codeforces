#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    vector<int> cnt(k+1,0);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }
    vector<int> c(k+1,0);
    for(int i=1;i<=k;i++) scanf("%d",&c[i]);
    vector<vector<int>> res(n+1);
    auto solve=[&](int m)->bool
    {
        for(int i=1;i<=n;i++) res[i].clear();
        priority_queue<array<int,2>> q;
        for(int i=1;i<=m;i++) q.push({c[1],i});
        for(int i=1;i<=k;i++)
        {
            for(int j=0;j<cnt[i];j++)
            {
                if(q.empty()) return 0;
                auto [now,id]=q.top();
                q.pop();
                now=min(now,c[i]);
                res[id].push_back(i);
                now--;
                if(now>0) q.push({now,id});
            }
        }
        return 1;
    };
    int l=0,r=n;
    while(l<r-1)
    {
        int m=(l+r)/2;
        if(solve(m)==1) r=m;
        else l=m;
    }
    solve(r);
    printf("%d\n",r);
    for(int i=1;i<=r;i++)
    {
        printf("%d",(int)res[i].size());
        for(int x:res[i]) printf(" %d",x);
        printf("\n");
    }
    return 0;
}