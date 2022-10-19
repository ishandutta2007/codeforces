#include"bits/stdc++.h"
using namespace std;
int a[104];
int sum[104];
int n;
int solve(int i,int j)
{
    int one=sum[j]-sum[i-1];
    int zero=j-i+1-one;
    return sum[n]-one+zero;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        sum[i]=sum[i-1]+a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)
    {
        ans=max(ans,solve(i,j));
    }
    cout<<ans<<endl;
}