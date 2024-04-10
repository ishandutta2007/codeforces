#include"bits/stdc++.h"
using namespace std;
int a[100005];
int sum[100005];
int n,t;
int fd(int i)
{
    int x1,x2,x;
    x1=i;x2=n+1;
    while(x1+1!=x2)
    {
        x=(x1+x2)/2;
        if(sum[x]-sum[i]>t)x2=x;
        else x1=x;
    }
    return x1-i;
}
int main()
{
    cin>>n>>t;
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;i++)ans=max(ans,fd(i-1));
    cout<<ans<<endl;
    return 0;
}