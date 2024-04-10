#include"bits/stdc++.h"
using namespace std;
int dp[505];
int a[505];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            scanf("%d",a+i);
        }
        sort(a,a+n);
        for(int i=0;i<=500;i++)dp[i]=0;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                for(int j=1;j<=500;j++)
                {
                    dp[j]=abs(j-a[i]);
                }
                continue;
            }
            int t=dp[1];
            dp[1]=1e7;
            for(int j=2;j<=500;j++)
            {
                int last=t;
                t=min(t,dp[j]);
                dp[j]=last+abs(j-a[i]);
            }
        }
        int t=1e7;
        for(int i=1;i<=500;i++)t=min(t,dp[i]);
        cout<<t<<endl;
    }
    return 0;
}