#include"bits/stdc++.h"
using namespace std;
#define ll long long
vector<int>v1[100005],v2[100005];
int vis1[100005],vis2[100005];
void dfs1(int i)
{
    vis1[i]=1;
    for(auto j:v1[i])if(vis1[j]==0)
    {
        dfs1(j);
    }
}
void dfs2(int i)
{
    vis2[i]=1;
    for(auto j:v2[i])if(vis2[j]==0)
    {
        dfs2(j);
    }
}
int main()
{
    int n,m1,m2;
    cin>>n>>m1>>m2;
    for(int i=0;i<m1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v1[a].push_back(b);
        v1[b].push_back(a);
    }
    for(int i=0;i<m2;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v2[a].push_back(b);
        v2[b].push_back(a);
    }
    cout<<n-max(m1,m2)-1<<endl;
    dfs1(1);dfs2(1);
    for(int i=1;i<=n;i++)
    {
        if(vis1[i]==0&&vis2[i]==0)
        {
            printf("%d %d\n",1,i);
            dfs1(i);dfs2(i);
        }
    }
    for(int i=1,j=1;i<=n&&j<=n;i++,j++)
    {
        while(vis1[i]!=1||vis2[i]!=0)
        {
            i++;
            if(i>n)return 0;
        }
        while(vis1[j]!=0||vis2[j]!=1)
        {
            j++;
            if(j>n)return 0;
        }
        dfs1(j);dfs2(i);
        printf("%d %d\n",i,j);
    }
    return 0;
}