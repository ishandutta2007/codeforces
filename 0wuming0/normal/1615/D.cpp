#include"bits/stdc++.h"
using namespace std;
vector<int>v[201005];
vector<pair<int,int> >mem[201005];
int save[201005][3];
int vis[201005];
int ans[201005];
int ok;
void dfs(int i,int op)
{//cout<<"<<<"<<i<<" "<<op<<endl;
    vis[i]=1;
    ans[i]=op;
    for(auto pr:mem[i])
    {
        int j=pr.first;
        int vv=pr.second;
        if(vis[j]==1)
        {
            if(ans[j]^ans[i]^vv)
            {ok=0;
            break;}
        }
        else
        {
            dfs(j,ans[i]^vv);
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        ok=1;
        for(int i=0;i<=n+5;i++)
        {
            vis[i]=0;
            v[i].clear();
            mem[i].clear();
        }
        for(int i=1;i<n;i++)
        {
            int a,b,g;
            scanf("%d%d%d",&a,&b,&g);
            save[i][0]=a;
            save[i][1]=b;
            save[i][2]=g;
            v[a].push_back(b);
            v[b].push_back(a);//cout<<"???"<<g<<endl;
            if(g>=0)
            {
                int k=0;
                for(int j=0;j<31;j++)if((1<<j)&g)k++;
                k%=2;//cout<<"???"<<k<<endl;
                mem[a].push_back(make_pair(b,k));
                mem[b].push_back(make_pair(a,k));
            }
        }
        for(int i=0;i<m;i++)
        {
            int a,b,v;
            scanf("%d%d%d",&a,&b,&v);
            //if(v>=0)
            {
                int k=v;
                mem[a].push_back(make_pair(b,k));
                mem[b].push_back(make_pair(a,k));
            }
        }
        for(int i=1;i<=n;i++)if(vis[i]==0)dfs(i,0);
        for(int i=1;i<n;i++)if(save[i][2]==-1)
        {
            save[i][2]=(ans[save[i][0]]^ans[save[i][1]]);
        }
        if(ok)
        {
            printf("YES\n");
            for(int i=1;i<n;i++)
            {
                printf("%d %d %d\n",save[i][0],save[i][1],save[i][2]);
            }
        }
        else printf("NO\n");
        for(int i=0;i<=n+5;i++)
        {
            vis[i]=0;
            v[i].clear();
            mem[i].clear();
            ans[i]=0;
            save[i][0]=save[i][1]=save[i][2]=0;
        }
    }
    return 0;
}
/*
1000
5 3
1 2 -1
1 3 -1
3 4 -1
3 5 8

1 2 1
2 4 1
4 5 0

*/