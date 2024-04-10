#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,p,k;
    scanf("%d%d%d",&n,&p,&k);
    vector<pair<long long,int>> a(n+1);
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i].first);
        a[i].second=i;
    }
    vector<vector<long long>> s(n+1,vector<long long>(p));
    for(int o=1;o<=n;o++) for(int i=0;i<p;i++) scanf("%I64d",&s[o][i]);
    sort(a.begin()+1,a.end(),greater<pair<int,int>>());
    vector<vector<long long>> dp(n+1,vector<long long>((1<<p),-1));
    dp[0][0]=0;
    auto mx=[](long long &one,long long two)->void
    {
        one=max(one,two);
    };
    auto popcnt=[](int x)->int
    {
        int cnt=0;
        while(x)
        {
            cnt+=(x&1);
            x/=2;
        }
        return cnt;
    };
    for(int o=0;o<n;o++)
    {
        long long x=a[o+1].first;
        vector<long long> y=s[a[o+1].second];
        for(int mask=0;mask<(1<<p);mask++)
        {
            if(dp[o][mask]==-1) continue;
            //add as player i
            for(int i=0;i<p;i++)
            {
                if(mask&(1<<i)) continue;
                mx(dp[o+1][(mask|(1<<i))],dp[o][mask]+y[i]);
            }
            //add as audience
            if(o-popcnt(mask)<k)
            {
                mx(dp[o+1][mask],dp[o][mask]+x);
            }
            //don't add
            mx(dp[o+1][mask],dp[o][mask]);
        }
    }
    printf("%I64d\n",dp[n][(1<<p)-1]);
    return 0;
}