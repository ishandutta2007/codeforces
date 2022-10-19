#include"bits/stdc++.h"
using namespace std;
#define ll long long
int dp[200005];
int solve(int a[],int maxa,int withcode)
{
    int ans=0;
    if(maxa==1)return a[1];
    if(maxa==2)return a[1]+a[2];
    //int newn=(int)sqrt(maxa)+1;
    for(int i=2;i<=maxa;i++)if(a[i])
    {
        if(!dp[i*withcode])
        {
            int *num=new int[maxa/i+5];
            int last=1;
            num[0]=0;
            for(int j=1;i*j<=maxa;j++)
            {
                if(a[i*j])
                {
                    last=j;
                    num[j]=a[i*j];
                }
                else num[j]=0;
            }
            dp[withcode*i]=solve(num,last,withcode*i);
            //cout<<maxa<<":"<<ans<<endl;
            delete []num;
        }
        ans=max(ans,dp[withcode*i]);
    }
    return ans+a[1];
}
int a[200005];
int num[200005];
int n;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int ans=0;
        cin>>n;
        for(int i=0;i<200005;i++)num[i]=dp[i]=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",a+i);
            num[a[i]]++;
        }
        sort(a,a+n);
        cout<<n-solve(num,a[n-1],1)<<endl;
    }
    return 0;
}