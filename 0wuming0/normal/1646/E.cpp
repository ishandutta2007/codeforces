#include"bits/stdc++.h"
using namespace std;
int dp[2005];
bool apr[31000000];
int n,m;
int cal(int now)
{//cout<<now<<" "<<dp[now]<<endl;
    if(dp[now])return dp[now];
    int sp=now*m;
    for(int i=1;i<=sp;i++)apr[i]=0;
    for(int i=1;i<=now;i++)
    {
        int sp=i*m;
        for(int j=i;j<=sp;j+=i)
        {
            apr[j]=1;
        }
    }
    for(int i=1;i<=sp;i++)dp[now]+=apr[i];//
    return dp[now];
}
int ans[1000006];
int main()
{
    cin>>n>>m;
    long long sum=1;
    for(int i=2;i<=n;i++)ans[i]=1;
    for(int i=2;i<=n;i++)if(ans[i])
    {
        for(long long j=(long long)i*i;j<=n;j*=i)
        {
            ans[i]+=ans[j];
            ans[j]=0;
        }
    }//cout<<"ok"<<endl;
    for(int i=2;i<=n;i++)if(ans[i])
    {
        sum+=cal(ans[i]);
    }
    cout<<sum<<endl;
    return 0;
}