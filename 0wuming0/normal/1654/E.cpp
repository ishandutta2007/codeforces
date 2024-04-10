#include"bits/stdc++.h"
using namespace std;
int num[35000000];
int a[100005];
int main()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=0;i<n;i++)scanf("%d",a+i);
    for(int d=0;d<330;d++)
    {
        int now=0;
        for(int i=0;i<n;i++)
        {
            int k=a[i]+d*i;
            num[k]++;
            now=max(now,num[k]);
        }
        for(int i=0;i<n;i++)
        {
            int k=a[i]+d*i;
            num[k]--;
        }
        ans=max(ans,now);
    }
    for(int i=0,j=n-1;i<j;i++,j--)swap(a[i],a[j]);
    for(int d=0;d<330;d++)
    {
        int now=0;
        for(int i=0;i<n;i++)
        {
            int k=a[i]+d*i;
            num[k]++;
            now=max(now,num[k]);
        }
        for(int i=0;i<n;i++)
        {
            int k=a[i]+d*i;
            num[k]--;
        }
        ans=max(ans,now);
    }
    for(int j=0;j<n;j++)
    {
        int now=0;
        int l=j-330,r=j+330;
        if(l<0)l=0;
        if(r>=n)r=n-1;
        for(int i=l;i<=r;i++)if(i!=j&&(a[i]-a[j])%(i-j)==0)
        {
            int k=(a[i]-a[j])/(i-j)+100005;
            num[k]++;
            now=max(now,num[k]);
        }
        for(int i=l;i<=r;i++)if(i!=j&&(a[i]-a[j])%(i-j)==0)
        {
            int k=(a[i]-a[j])/(i-j)+100005;
            num[k]--;
        }
        ans=max(ans,now+1);
    }
    cout<<n-ans<<endl;
    return 0;
}