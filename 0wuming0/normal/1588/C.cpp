#include"bits/stdc++.h"
using namespace std;
int a[300005];
long long save[300005],nn;
long long sum[300005];
long long ans;
void solve(int l,int r)
{
    if(l==r)
    {
        if(a[l]==0)ans++;
        return;
    }
    int x=l+r>>1;
    solve(l,x);
    solve(x+1,r);
    map<long long,long long>mp1;
    map<long long,long long>mp2;
    nn=0;
    for(int i=x+1;i<=r;i++)
    {
        save[nn++]=a[i];
        while(nn>=3)
        {
            if(save[nn-1]<0)break;
            if(save[nn-2]>=save[nn-1]&&save[nn-2]>=save[nn-3])
            {
                nn-=2;
                save[nn-1]=save[nn-1]+save[nn+1]-save[nn];
            }
            else break;
        }
        if(save[nn-1]<0)break;
        if(nn==1)sum[nn-1]=save[nn-1];
        else if(nn&1)sum[nn-1]=sum[nn-2]+save[nn-1];
        else sum[nn-1]=sum[nn-2]-save[nn-1];
        if(nn>1&&save[nn-1]>save[nn-2])continue;
        mp1[sum[nn-1]]++;
    }
    nn=0;
    for(int i=x;i>=l;i--)
    {
        save[nn++]=a[i];
        while(nn>=3)
        {
            if(save[nn-1]<0)break;
            if(save[nn-2]>=save[nn-1]&&save[nn-2]>=save[nn-3])
            {
                nn-=2;
                save[nn-1]=save[nn-1]+save[nn+1]-save[nn];
            }
            else break;
        }
        if(save[nn-1]<0)break;
        if(nn==1)sum[nn-1]=save[nn-1];
        else if(nn&1)sum[nn-1]=sum[nn-2]+save[nn-1];
        else sum[nn-1]=sum[nn-2]-save[nn-1];
        if(nn>1&&save[nn-1]>save[nn-2])continue;
        mp2[sum[nn-1]]++;
    }
    for(auto &pr:mp1)
    {
        ans+=pr.second*mp2[pr.first];
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
        }
        ans=0;
        solve(1,n);
        printf("%lld\n",ans);
    }
    return 0;
}