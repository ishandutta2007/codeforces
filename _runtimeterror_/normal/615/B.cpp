#include<iostream>
#include<vector>

using namespace std;

const int N = 100005;

int dp[N];
vector<int> v[N];

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;++i)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].push_back(y),v[y].push_back(x);
    }
    long long ans = 0;
    dp[1] = 1;
    ans = dp[1]*1LL*(int)v[1].size();
    for(int i=2;i<=n;++i)
    {
        for(int j:v[i])
            if(j<i)
                dp[i] = max(dp[i],dp[j]);
        ++dp[i];
        ans = max(ans,dp[i]*1LL*(int)v[i].size());
    }
    printf("%lld",ans);
    
}