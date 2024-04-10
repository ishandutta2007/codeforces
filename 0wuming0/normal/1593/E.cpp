#include"bits/stdc++.h"
using namespace std;
vector<int>v[400005];
int save[400005];
int vis[400005];
int num[400005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        int l=0,m=0,r=0;
        for(int i=1;i<=n;i++)if(v[i].size()<=1)
        {
            vis[i]=1;
            save[r++]=i;
        }
        else num[i]=v[i].size();
        while(k--)
        {
            m=r;
            if(l==m)break;
            for(int i=l;i<m;i++)
            {
                for(auto j:v[save[i]])if(vis[j]==0)
                {
                    num[j]--;
                    if(num[j]<=1)
                    {
                        save[r++]=j;
                        vis[j]=1;
                    }
                }
            }
            l=m;
        }
        printf("%d\n",n-l);
        for(int i=0;i<=n;i++)
        {
            v[i].clear();
            num[i]=vis[i]=0;
        }
    }
    return 0;
}