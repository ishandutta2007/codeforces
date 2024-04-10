#include"bits/stdc++.h"
using namespace std;
char s[205];
int a[205];
int vis[205];
char temp[405];
int nn;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        int n;
        cin>>n;
        cin>>s+1;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        long long ans=1;
        for(int i=1;i<=n;i++)if(vis[i]==0)
        {
            nn=0;
            int now=i;
            temp[nn++]=s[now];
            vis[now]=1;
            while(1)
            {
                now=a[now];
                if(vis[now])break;
                temp[nn++]=s[now];
                vis[now]=1;
            }
            for(int j=nn;j<2*nn;j++)temp[j]=temp[j-nn];
            long long tt;
            for(tt=1;;tt++)
            {
                int j;
                for(j=0;j<nn;j++)
                {
                    if(temp[j]!=temp[j+tt])break;
                }
                if(j==nn)break;
            }
            ans*=tt/__gcd(ans,tt);
        }
        cout<<ans<<endl;
    }
    return 0;
}