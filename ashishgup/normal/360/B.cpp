#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2005;

int n, k;
int a[N], dp[N];

int check(int cur)
{
    for(int i=1;i<=n;i++)
    {
        dp[i]=i-1;
        int maxd=cur;
        for(int j=i-1;j>=1;j--)
        {
            if(abs(a[i]-a[j])<=maxd)
            {
                dp[i]=min(dp[i], dp[j]+i-j-1);
            }
            maxd+=cur;
        }
    }
    int min1=1e18;
    for(int i=1;i<=n;i++)
    {
        dp[i]+=n-i;
        min1=min(min1, dp[i]);
    }
    if(min1<=k)
        return true;
    else
        return false;
}

int binsearch(int lo, int hi)
{
    while(lo<hi)
    {
        int mid=(lo+hi)>>1;
        if(check(mid))
        {
            hi=mid;
        }
        else
        {
            lo=mid+1;
        }
    }
    return lo;
}

int32_t main()
{
    IOS;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int ans=binsearch(0, 2e9);
    cout<<ans<<endl;
    return 0;
}