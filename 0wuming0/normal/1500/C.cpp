#include"bits/stdc++.h"
using namespace std;
int a[1505][1505];
int b[1505][1505];
int num[1505];
vector<int>v[1506];
int vis[1505];
int n,m;
int ans[1505],nn;
void solve(int j)
{
    for(int i=1;i<n;i++)
    {
        if(b[i][j]!=b[i+1][j]&&vis[i]==0)
        {
            vis[i]=1;
            vector<int>::iterator it;
            for(it=v[i].begin();it!=v[i].end();it++)
            {
                num[*it]--;
                if(num[*it]==0)
                {
                    ans[nn++]=*it;
                    num[*it]=-1;
                    solve(*it);
                }
            }
        }
    }
}
int nowpos[1505];
int pos[1505];
int cmpnum;
bool cmp(int x,int y)
{
    if(a[x][cmpnum]!=a[y][cmpnum])return a[x][cmpnum]<a[y][cmpnum];
    return nowpos[x]<nowpos[y];
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
    {
        scanf("%d",&a[i][j]);
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
    {
        scanf("%d",&b[i][j]);
    }
    for(int j=1;j<=m;j++)
    {
        for(int i=1;i<n;i++)
        {
            if(b[i][j]>b[i+1][j])
            {
                v[i].push_back(j);
                num[j]++;
            }
        }
    }
    for(int j=1;j<=m;j++)if(num[j]==0)
    {
        ans[nn++]=j;
        num[j]=-1;
        solve(j);
    }
    for(int i=0,j=nn-1;i<j;i++,j--)
    {
        swap(ans[i],ans[j]);
    }
    for(int i=1;i<=n;i++)pos[i]=i;
    for(int i=0;i<nn;i++)
    {
        for(int j=1;j<=n;j++)
        {
            nowpos[pos[j]]=j;
        }
        cmpnum=ans[i];
        sort(pos+1,pos+1+n,cmp);
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
    {
        if(a[pos[i]][j]!=b[i][j])
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<nn<<endl;
    for(int i=0;i<nn;i++)printf("%d%c",ans[i]," \n"[i==nn-1]);
    return 0;
}