#include"bits/stdc++.h"
using namespace std;
int vis[5000005][2];
int a[200005];
int ans[200005],nn;
int ans2[200005],nn2;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        vis[a[i]][0]++;
    }
    int flag=0,save;
    for(int i=0;i<=5e6;i++)
    {
        if(vis[i][0]>=4)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[j]==i)ans[nn++]=j;
            }
            cout<<"YES"<<endl;
            cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<endl;
            return 0;
        }
        if(vis[i][0]>=2)
        {
            if(flag==0)
            {
                flag=1;
                save=i;
            }
            else
            {
                for(int j=1;j<=n;j++)
                {
                    if(a[j]==i)ans[nn++]=j;
                }
                for(int j=1;j<=n;j++)
                {
                    if(a[j]==save)ans2[nn2++]=j;
                }
                cout<<"YES"<<endl;
                cout<<ans[0]<<" "<<ans2[0]<<" "<<ans[1]<<" "<<ans2[1]<<endl;
                return 0;
            }
        }
        vis[i][0]=0;
    }
    if(flag==1)
    {
        map<int,int>mp;
        for(int i=1;i<=n;i++)
        {
            mp[a[i]]=i;
        }
        for(int i=1;i<=n;i++)if(a[i]!=save)
        {
            if(mp.find(2*save-a[i])!=mp.end())
            {
                for(int j=1;j<=n;j++)
                {
                    if(a[j]==save)ans[nn++]=j;
                }
                //(mp.find(2*save-a[i]))->second;
                cout<<"YES"<<endl;
                cout<<i<<" "<<((mp.find(2*save-a[i]))->second)<<" "<<ans[0]<<" "<<ans[1]<<endl;
                return 0;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[a[i]][0])a[i]=0;
        vis[a[i]][0]=1;
    }
    for(int i=0;i<=5e6;i++)vis[i][0]=0;
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(a[i]!=0&&a[j]!=0)
    {
        if(vis[a[i]+a[j]][0])
        {
            cout<<"YES"<<endl;
            cout<<vis[a[i]+a[j]][0]<<" "<<vis[a[i]+a[j]][1]<<" "<<i<<" "<<j<<endl;
            return 0;
        }
        vis[a[i]+a[j]][0]=i;
        vis[a[i]+a[j]][1]=j;
    }
    cout<<"NO"<<endl;
    return 0;
}