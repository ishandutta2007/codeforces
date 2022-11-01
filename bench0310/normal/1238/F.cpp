#include <bits/stdc++.h>

using namespace std;

const int N=300005;
vector<int> v[N];
vector<int> dp(N);
int res;

void dfs(int a,int p=-1)
{
    vector<int> t;
    for(int to:v[a])
    {
        if(to==p) continue;
        dfs(to,a);
        t.push_back(dp[to]);
    }
    sort(t.begin(),t.end(),greater<int>());
    dp[a]=v[a].size()+(p==-1);
    if(!t.empty()) dp[a]+=(t[0]-1);
    res=max(res,dp[a]+(p!=-1));
    if(t.size()>=2) res=max(res,1+t[0]+t[1]+(int)v[a].size()-2);
}

int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        res=0;
        dfs(1);
        printf("%d\n",res);
        for(int i=1;i<=n;i++)
        {
            dp[i]=0;
            v[i].clear();
        }
    }
    return 0;
}