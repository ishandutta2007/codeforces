#include"bits/stdc++.h"
using namespace std;
int aim[55][55];
int n,m;
int mp[55][55];
int line,now;
bool flag;
bool vis[55][55];
int ans[10801][4],nn;
void add(int a,int b,int c,int d)
{//cout<<"??"<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    ans[nn][0]=a;
    ans[nn][1]=b;
    ans[nn][2]=c;
    ans[nn++][3]=d;
    swap(mp[a][b],mp[c][d]);
    //for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)printf("%d%c",mp[i][j]," \n"[j==n]);
}
int lastx,lasty;
int bg;
void dfs(int i,int j)
{//cout<<"<<"<<i<<" "<<j<<" "<<mp[i][j]<<endl;
    vis[i][j]=1;
    if(mp[i][j])
    {
        flag=1;
        lastx=i;
        lasty=j;
        return;
    }
    if(vis[i][j+1]==0)dfs(i,j+1);
    if(flag)
    {
        add(lastx,lasty,i,j);
        lastx=i;
        lasty=j;
        return;
    }
    if(vis[i][j-1]==0)dfs(i,j-1);
    if(flag)
    {
        add(lastx,lasty,i,j);
        lastx=i;
        lasty=j;
        return;
    }
    if(vis[i+1][j]==0)dfs(i+1,j);
    if(flag)
    {
        add(lastx,lasty,i,j);
        lastx=i;
        lasty=j;
        return;
    }
    if(vis[i-1][j]==0)dfs(i-1,j);
    if(flag)
    {
        add(lastx,lasty,i,j);
        lastx=i;
        lasty=j;
        return;
    }
}
void clr()
{
    flag=0;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<=now;i++)vis[line][i]=1;
    for(int i=0;i<=n;i++)vis[i][0]=vis[n+1][i]=vis[0][i]=vis[i][n+1]=1;
}
void clr2(int kk)
{
    flag=0;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<=n;i++)vis[i][0]=vis[n+1][i]=vis[0][i]=vis[i][n+1]=1;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(mp[i][j]&&mp[i][j]!=kk)vis[i][j]=1;
}
int num[100];
void get(int kk)
{
    for(int i=1;i<=n;i++)if(mp[n][i])
    {
        for(int j=i-1;mp[n][j]==0&&j>0;j--)
        {
            add(n,j+1,n,j);
        }
    }
    for(int i=n;i>=1;i--)if(mp[n][i]==kk)
    {
        add(n,i,n-1,i);
        for(int j=i+1;mp[n-1][j]==0&&j<=n;j++)
        {
            add(n-1,j-1,n-1,j);
        }
        return;
    }
}
int main()
{
    cin>>n>>m;
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        mp[x][y]=i+1;
    }
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        aim[x][y]=i+1;
        num[x]++;
    }
    {
        line=n;
        for(now=1;now<=m;now++)
        {
            for(int i=n;i>=1;i--)for(int j=1;j<=n;j++)if(mp[i][j])
            {
                int ii=i+1;
                while(ii<=n&&mp[ii][j]==0)
                {
                    add(ii-1,j,ii,j);
                    ii++;
                }
            }
            clr();
            dfs(line,now);
        }
    }
    for(int i=1;i<=n-2;i++)for(int j=1;j<=n;j++)if(aim[i][j])
    {
        for(int ii=1;ii<=n;ii++)for(int jj=1;jj<=n;jj++)if(mp[ii][jj]==aim[i][j])
        {
            add(ii,jj,ii-1,jj);
            ii--;
            if(jj<j)while(jj!=j)
            {
                add(ii,jj,ii,jj+1);
                jj++;
            }
            if(jj>j)while(jj!=j)
            {
                add(ii,jj,ii,jj-1);
                jj--;
            }
            while(ii!=i)
            {
                add(ii,jj,ii-1,jj);
                ii--;
            }
            goto ne;
        }
        ne:;
    }
    for(int i=n;i>=1;i--)
    {
        if(aim[n-1][i])get(aim[n-1][i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(aim[n][i])get(aim[n][i]);
    }//cout<<"ok"<<endl;
    for(int i=n;i>=1;i--)
    {
        if(aim[n][i])
        {
            clr2(aim[n][i]);
            dfs(n,i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(aim[n-1][i])
        {
            clr2(aim[n-1][i]);
            dfs(n-1,i);
        }
    }
    //for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)printf("%d%c",mp[i][j]," \n"[j==n]);
    //for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)printf("%d%c",aim[i][j]," \n"[j==n]);
    cout<<nn<<endl;
    for(int i=0;i<nn;i++)printf("%d %d %d %d\n",ans[i][0],ans[i][1],ans[i][2],ans[i][3]);
    return 0;
}
/*
4 3
4 1
4 2
4 4
4 1
3 2
3 1
*/