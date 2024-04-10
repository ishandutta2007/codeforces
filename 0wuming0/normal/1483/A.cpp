#include"bits/stdc++.h"
using namespace std;
vector<int>v[100006];
int ans[100006],nn;
int vis[100006];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<=m;i++)v[i].clear();
        nn=0;
        for(int i=1;i<=m;i++)
        {
            int k;
            scanf("%d",&k);
            for(int j=0;j<k;j++)
            {
                int c;
                scanf("%d",&c);
                v[i].push_back(c);
            }
        }
        for(int i=1;i<=m;i++)
        {
            ans[nn++]=v[i][0];
            vis[v[i][0]]++;
        }
        int lim;
        if(m%2==0)lim=m/2;
        else lim=m/2+1;
        int save=0;
        int num=-1;
        for(int i=0;i<nn;i++)
        {
            if(vis[ans[i]]>lim)
            {
                save=vis[ans[i]];
                num=ans[i];
                break;
            }
        }
        for(int i=0;i<nn;i++)vis[ans[i]]=0;
        if(num!=-1)
        {
            for(int i=1;i<=m;i++)if(v[i].size()>1&&v[i][0]==num)
            {
                ans[i-1]=v[i][1];
                save--;
                if(save<=lim)break;
            }
        }
        if(save<=lim)
        {
            printf("YES\n");
            for(int i=0;i<nn;i++)printf("%d%c",ans[i]," \n"[i==nn-1]);
        }
        else printf("NO\n");
        ne:;
    }
    return 0;
}