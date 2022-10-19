#include"bits/stdc++.h"
using namespace std;
int a[100005];
int ll[100005];
int lr[100005];
int rl[100005];
int rr[100005];
int maxl[100005],maxr[100005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<n;i++)
    {
        if(a[i]>a[i+1])
        {
            int t=i;
            while(t<n&&a[t]>a[t+1])t++;
            for(int j=i;j<=t;j++)rl[j]=t-j;
            i=t-1;
        }
        else
        {
            int t=i;
            while(t<n&&a[t]<a[t+1])t++;
            for(int j=i;j<=t;j++)rr[j]=t-j;
            i=t-1;
        }
    }
    for(int i=n;i>1;i--)
    {
        if(a[i]>a[i-1])
        {
            int t=i;
            while(t>1&&a[t]>a[t-1])t--;
            for(int j=t;j<=i;j++)ll[j]=j-t;
            i=t+1;
        }
        else
        {
            int t=i;
            while(t>1&&a[t]<a[t-1])t--;
            for(int j=t;j<=i;j++)lr[j]=j-t;
            i=t+1;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)maxl[i]=max(maxl[i-1],max(rl[i]+rr[i],lr[i]+ll[i]));
    for(int i=n;i>0;i--)maxr[i]=max(maxr[i+1],max(rl[i]+rr[i],lr[i]+ll[i]));
    for(int i=2;i<n;i++)if(ll[i]>0&&rl[i]>0)
    {
        if(ll[i]!=rl[i])continue;
        if(ll[i]%2)continue;
        int r=i+rl[i];
        int l=i-ll[i];
        int t=max(lr[l],rr[r]);
        t=max(t,maxl[l-1]);
        t=max(t,maxr[r+1]);
        if(t>=ll[i])continue;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
/*
10
1 2 5 4 3 6 7 10 9 8
*/