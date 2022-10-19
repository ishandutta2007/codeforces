#include <bits/stdc++.h>
using namespace std;
const long long mek=1;
const int N=55;

int n,k;
long long a[N];

bool stgg(long long x,long long y)
{
    for(long long i=0;i<=62;++i)
        if(!(x&(mek<<i)) && (y&(mek<<i)))
           return false;
    return true;
}

bool dp[N][N];
bool stg(long long x)
{
    for(int i=0;i<=n;++i)for(int j=0;j<=k;++j)dp[i][j]=false;
    dp[0][0]=true;
    for(int r=1;r<=n;++r)
    {
        for(int j=1;j<=k;++j)
        {
            long long sum=0;
            for(int l=r;l>=1;--l)
            {
                sum+=a[l];
                if(dp[l-1][j-1] && stgg(sum,x))
                {
                    dp[r][j]=true;
                    break;
                }
            }
        }
    }
    return (dp[n][k]);
}

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    long long ans=0;
    for(long long i=62;i>=0;--i)
    {
        if(i==4)
            cout<<"";
        if(stg(ans^(mek<<i)))
        {
            ans^=(mek<<i);
        }
    }
    cout<<ans<<endl;
    return 0;
}