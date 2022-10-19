#include"bits/stdc++.h"
using namespace std;
int a[1005][1005];
int rpos[1005][1005];
int lpos[1005][1005];
int rans[1005][1005];
int lans[1005][1005];
int nowr,nowl;
int cmpr(int x,int y)
{
    return a[nowr][x]<a[nowr][y];
}
int cmpl(int x,int y)
{
    return a[x][nowl]<a[y][nowl];
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
        scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
    {
        nowr=i;
        for(int j=1;j<=m;j++)rpos[i][j]=j;
        sort(rpos[i]+1,rpos[i]+m+1,cmpr);
        rans[i][rpos[i][1]]=1;
        for(int j=2;j<=m;j++)
        {
            if(a[i][rpos[i][j]]==a[i][rpos[i][j-1]])rans[i][rpos[i][j]]=rans[i][rpos[i][j-1]];
            else rans[i][rpos[i][j]]=rans[i][rpos[i][j-1]]+1;
        }
        rans[i][0]=rans[i][rpos[i][m]];
    }
    for(int j=1;j<=m;j++)
    {
        nowl=j;
        for(int i=1;i<=n;i++)lpos[j][i]=i;
        sort(lpos[j]+1,lpos[j]+n+1,cmpl);
        lans[lpos[j][1]][j]=1;
        for(int i=2;i<=n;i++)
        {
            if(a[lpos[j][i]][j]==a[lpos[j][i-1]][j])lans[lpos[j][i]][j]=lans[lpos[j][i-1]][j];
            else lans[lpos[j][i]][j]=lans[lpos[j][i-1]][j]+1;
        }
        lans[0][j]=lans[lpos[j][n]][j];
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
    {
        int ans;
        if(rans[i][j]>lans[i][j])
        {
            ans=max(rans[i][0],lans[0][j]+rans[i][j]-lans[i][j]);
        }
        else
        {
            ans=max(rans[i][0]-rans[i][j]+lans[i][j],lans[0][j]);
        }//cout<<endl<<i<<","<<j<<":"<<rans[i][0]<<" "<<lans[0][j]<<endl;
        printf("%d%c",ans," \n"[j==m]);
    }
    return 0;
}