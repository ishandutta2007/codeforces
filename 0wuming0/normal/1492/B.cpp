#include"bits/stdc++.h"
using namespace std;
int a[100005];
int vis[100005];
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
            vis[i]=0;
        }
        int now=n,l=n,r=n;
        while(1)
        {
            while(a[l]!=now)l--;
            if(l==1)
            {
                for(int i=l;i<=r;i++)
                {
                    printf("%d%c",a[i]," \n"[i==r]);
                }
                break;
            }
            else for(int i=l;i<=r;i++)printf("%d ",a[i]);
            for(int i=l;i<=r;i++)vis[a[i]]=1;
            r=l-1;
            while(vis[now])now--;
        }
    }
    return 0;
}