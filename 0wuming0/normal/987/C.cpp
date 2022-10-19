#include"bits/stdc++.h"
using namespace std;
int a[3005],c[3005];
int l[3005],r[3005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=n;i++)l[i]=r[i]=1e9;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)if(a[i]<a[j])r[i]=min(r[i],c[j]);
        for(int j=1;j<i;j++)if(a[j]<a[i])l[i]=min(l[i],c[j]);
    }
    long long ans=1e9;
    for(int i=1;i<=n;i++)
    {
        if(l[i]+r[i]+0ll+c[i]<=ans)
        {
            ans=l[i]+r[i]+0ll+c[i];
        }
    }
    if(ans==1e9)ans=-1;
    cout<<ans<<endl;
    return 0;
}