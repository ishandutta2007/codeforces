#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<vector<int>> v;

array<int,3> solve(int x)
{
    vector<int> mask(n,0);
    vector<int> dp((1<<m),-1);
    for(int o=0;o<n;o++)
    {
        for(int i=0;i<m;i++) if(v[o][i]>=x) mask[o]+=(1<<i);
        dp[mask[o]]=o;
    }
    for(int i=(1<<m)-1;i>=0;i--)
    {
        if(dp[i]==-1) continue;
        for(int j=0;j<m;j++)
        {
            if(i&(1<<j)) dp[i-(1<<j)]=dp[i];
        }
    }
    array<int,3> a={0,0,0};
    for(int i=0;i<n;i++)
    {
        if(dp[(1<<m)-1-mask[i]]!=-1) a={i,dp[(1<<m)-1-mask[i]],1};
    }
    return a;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int o=0;o<n;o++)
    {
        vector<int> t(m);
        for(int i=0;i<m;i++) scanf("%d",&t[i]);
        v.push_back(t);
    }
    int l=0,r=1000000001;
    while(l<r-1)
    {
        int mid=(l+r)/2;
        if(solve(mid)[2]) l=mid;
        else r=mid;
    }
    array<int,3> a=solve(l);
    printf("%d %d\n",a[0]+1,a[1]+1);
    return 0;
}