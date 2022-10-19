#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll dp[400005];
ll me[200005];
int a[200005];
int pos[200005];
int cmp(int x,int y)
{
    return me[x]*a[y]>me[y]*a[x];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)scanf("%lld",me+i);
        for(int i=0;i<n;i++)scanf("%d",a+i);
        for(int i=0;i<n;i++)pos[i]=i;
        sort(pos,pos+n,cmp);
        //for(int i=0;i<n;i++)cout<<pos[i];cout<<endl;
        dp[0]=0;
        ll now=0,nowm=0;
        for(int i=0;i<n;i++)
        {
            nowm+=me[pos[i]];
            now+=a[pos[i]];
            dp[now]=nowm;
        }
        now=0,nowm=0;
        for(int i=0;i<n;i++)
        {
            int j;
            if(a[pos[i]]==2)
            {
                for(j=i;j<n;j++)if(a[pos[j]]==1)break;
                if(j==n)break;
                for(;i<=j;i++)
                {
                    dp[now+1]=max(nowm+me[pos[j]],dp[now+1]);
                    nowm+=me[pos[i]];
                    now+=a[pos[i]];
                }
                i--;
                continue;
            }
            nowm+=me[pos[i]];
            now+=a[pos[i]];
        }
        now=0,nowm=0;
        int lastpos=-1;
        for(int i=0;i<n;i++)
        {
            if(a[pos[i]]==2&&lastpos!=-1)
            {
                dp[now+1]=max(nowm+me[pos[i]]-me[pos[lastpos]],dp[now+1]);
            }
            else if(a[pos[i]]==1)
            {
                lastpos=i;
            }
            /*
            int j;
            if(a[pos[i]]==1)
            {
                for(j=i;j<n;j++)if(a[pos[j]]==2)break;
                if(j==n)break;
                for(;i<=j;i++)
                {
                    dp[now+2]=max(nowm+me[pos[j]],dp[now+2]);
                    nowm+=me[pos[i]];
                    now+=a[pos[i]];
                }
                i--;
                continue;
            }*/
            nowm+=me[pos[i]];
            now+=a[pos[i]];
        }//for(int i=0;i<2*n+3;i++)cout<<i<<":"<<dp[i]<<endl;
        int ans=1e9;
        for(int i=0;i<2*n+3;i++)
        {
            if(dp[i]>=m)ans=min(ans,i);
        }
        if(ans==1e9)cout<<"-1"<<endl;
        else cout<<ans<<endl;;
        for(int i=0;i<2*n+3;i++)dp[i]=0;
    }
    return 0;
}
/*
1
4 11
8 2 2 2
2 2 2 2
*/