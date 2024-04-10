#include <bits/stdc++.h>
using namespace std;
const int N=100005,M=320;

int n,s;
int a[N];

int dp[N][M];
int main()
{
    cin>>n;
    s=sqrt(n*1.0);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    for(int i=n;i>=1;--i)
    {
        for(int k=1;k<s;++k)
        {
            if((i+a[i]+k)>n)
            {
                dp[i][k]=1;
            }
            else
            {
                dp[i][k]=dp[i+a[i]+k][k]+1;
            }
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int i,k;
        cin>>i>>k;
        if(k<s)
            cout<<dp[i][k]<<endl;
        else
        {
            int ans=0;
            for(;i<=n;i=i+a[i]+k)
                ++ans;
            cout<<ans<<endl;
        }
    }
    return 0;
}