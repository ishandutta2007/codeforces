#include"bits/stdc++.h"
using namespace std;
int a[400005];
int sum[400005];
int sum2[400005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,p,k;
        cin>>n>>p>>k;
        int ans=0;
        for(int i=1;i<=n;i++)scanf("%d",a+i);
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++)
        {
            sum[i]=a[i];
            sum2[i]=a[i];
        }
        for(int i=0;i<k;i++)sum[i]=0;
        for(int i=k;i<=n;i++)
        {
            sum[i+k]+=sum[i];
        }
        for(int i=2;i<=n;i++)sum2[i]+=sum2[i-1];
        for(int i=1;i<=n;i++)
        {//cout<<i<<" "<<sum[i]<<" "<<sum2[i]<<endl;
            long long my=sum2[i%k];
            my+=sum[i];//cout<<my<<endl;
            if(p>=my)ans=max(ans,i);
        }
        cout<<ans<<endl;
    }
    return 0;
}