#include"bits/stdc++.h"
using namespace std;
#define ll long long
int ans[100005];
int now[100005];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<100005;i++)ans[i]=1e9;
    for(int ii=1;ii<=n;ii++)
    {
        ll t,x,y;
        cin>>t>>x>>y;
        for(int i=0;i<=100000;i++)
        {
            if(ans[i]<300)
            {
                now[i]=y;
            }
            else now[i]=-1;
        }
        for(int i=0;i<=100000;i++)
        {
            long long ne;
            if(t==2)ne=i*x/100000+(i*x%100000>0);
            else ne=i+x/100000+(x%100000>0);
            if(ne<=100000)now[ne]=max(now[ne],now[i]-1);
        }
        for(int i=0;i<=100000;i++)if(now[i]!=-1)
        {
            ans[i]=min(ii,ans[i]);
        }
    }
    for(int i=0;i<=100000;i++)if(ans[i]>300)ans[i]=-1;
    for(int i=1;i<=m;i++)printf("%d%c",ans[i]," \n"[i==m]);
    return 0;
}