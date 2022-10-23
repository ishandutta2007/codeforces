#include<bits/stdc++.h>

using namespace std;

const int N=100005;

vector<int> v[N];
long long val[N],dp[N];
long long S=0;

void dfs(int s,int p,long long x)
{
    if(x>1e13)
        x=0;
    dp[s]=x;
    for(int j:v[s])
        if(j!=p)
            dfs(j,s,x*(long long)(v[s].size()-1));
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%lld",val+i),S+=val[i];
    for(int i=1;i<=n-1;++i)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    v[1].push_back(0);
    dfs(1,0,1ll);

    long long u=2e18,lcm=0;
    bool first=false;

    for(int i=1;i<=n;++i)
    {
        if(v[i].size()==1)
        {
            if(val[i]==0)
            {
                u=0;
                break;
            }
            if((long long)1e18/val[i]>=dp[i])
                u=min(u,val[i]*dp[i]);
            if(lcm==0 && !first)
                lcm=dp[i],first=true;
            else if(lcm==0)
                break;
            else
            {
                long long x=__gcd(lcm,dp[i]);
                lcm/=x;
                if((long long)1e18/lcm>=dp[i])
                    lcm=lcm*dp[i];
            }
        }
    }
    if(u==0 || lcm==0)
    {
        printf("%lld",S);
        return 0;
    }
    u=u/lcm*lcm;
    printf("%lld\n",S-u);

}