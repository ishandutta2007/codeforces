#include"bits/stdc++.h"
using namespace std;
int vis[1000005];
int now[1000005];
int n,k;
void pr()
{
    for(int i=0;i<n;i++)if(vis[i]!=2)
    {
        vis[i]=2;
        vis[now[i]]=2;
        printf("%d %d\n",i,now[i]);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        if(n==4&&k==3)
        {
            cout<<"-1"<<endl;
            continue;
        }
        for(int i=0;i<=n;i++)vis[i]=0;
        int p=n-1;
        for(int i=0;i<n;i++)if(vis[i]==0)
        {
            vis[i]=vis[i^p]=1;
            now[i]=i^p;
            now[i^p]=i;
        }
        if(k==0)
        {
            pr();
            continue;
        }
        if(n==k+1)
        {
            /*
            n-1 n-2
            1 n-3
            2 0
            3 n-4
            */
            now[0]=2;
            now[2]=0;
            now[3]=n-4;
            now[n-4]=3;
            now[1]=n-3;
            now[n-3]=1;
            now[n-1]=n-2;
            now[n-2]=n-1;
            pr();
            /*
            0 n-1
            1 n-2
            2 n-3
            3 n-4
            */
            continue;
        }
        int t=now[k];
        //k t
        //0 n-1
        now[0]=t;
        now[t]=0;
        now[k]=n-1;
        now[n-1]=k;
        pr();
    }
    return 0;
}