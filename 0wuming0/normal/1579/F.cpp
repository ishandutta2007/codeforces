#include"bits/stdc++.h"
using namespace std;
int vis[1000005];
int a[1000005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        for(int i=0;i<n;i++)scanf("%d",a+i);
        int ans=0;
        int fg=1;
        for(int i=0;i<n;i++)if(vis[i]==0)
        {
            int f=1;
            int now=i;
            int s=0;
            while(1)
            {
                if(a[now])s++;
                else
                {
                    f=0;
                    ans=max(ans,s);
                    s=0;
                }
                now=now+d;
                now%=n;
                if(vis[now]==2)break;
                vis[now]++;
            }
            if(f)fg=0;
        }
        if(fg)cout<<ans<<endl;
        else cout<<-1<<endl;
        for(int i=0;i<n;i++)vis[i]=0;
    }
    return 0;
}