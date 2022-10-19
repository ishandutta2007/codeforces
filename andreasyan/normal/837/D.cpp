#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=202,INF=999999;

int n,k;
int h[N],e[N];

const int m=N*26;

int dp[N][m];
int ydp[N][m];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("transform.in","r",stdin);
    //freopen("transform.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;++i)
    {
        long long x;
        cin>>x;
        while(1)
        {
            if(x%5==0)
            {
                h[i]++;
                x/=5;
            }
            else
                break;
        }
        while(1)
        {
            if(x%2==0)
            {
                e[i]++;
                x/=2;
            }
            else
                break;
        }
    }
    for(int kk=0;kk<=k;++kk)
    {
        for(int hh=0;hh<m;++hh)
        {
            dp[kk][hh]=-INF;
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int kk=0;kk<=k;++kk)
        {
            for(int hh=0;hh<m;++hh)
            {
                ydp[kk][hh]=-INF;
            }
        }
        ydp[1][h[i]]=e[i];
        for(int kk=1;kk<=k;++kk)
        {
            for(int hh=0;hh<m;++hh)
            {
                if(dp[kk-1][hh]+e[i]>ydp[kk][h[i]+hh])
                    ydp[kk][h[i]+hh]=dp[kk-1][hh]+e[i];
            }
        }
        for(int kk=1;kk<=k;++kk)
        {
            for(int hh=0;hh<m;++hh)
                dp[kk][hh]=max(dp[kk][hh],ydp[kk][hh]);
        }
    }
    int ans=0;
    for(int kk=1;kk<=k;++kk)
    {
        for(int hh=0;hh<m;++hh)
        {
            ans=max(ans,min(hh,dp[kk][hh]));
        }
    }
    cout<<ans<<endl;
    return 0;
}