#include"bits/stdc++.h"
using namespace std;
int dp[500005];
int a[500005];
int l[500005],r[500005];
int num[500005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        if(!l[a[i]])l[a[i]]=i;
        r[a[i]]=i;
    }
    dp[n]=1;
    num[a[n]]++;
    for(int i=n-1;i>0;i--)
    {
        dp[i]=dp[i+1];
        num[a[i]]++;
        dp[i]=max(dp[i],num[a[i]]);
        if(l[a[i]]==i)dp[i]=max(dp[i],num[a[i]]+dp[r[a[i]]+1]);
    }
    cout<<n-dp[1]<<endl;
    return 0;
}