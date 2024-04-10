#include"bits/stdc++.h"
using namespace std;
int a[105][105];
int ans[105][105][15];
struct _
{
    int x;
    int y;
    int s;
}st[100005];
int n,q,c;
int solve(int t,int m[105][105])
{
    ans[1][1][t]=m[1][1];
    for(int i=2;i<103;i++)
    {
        ans[i][1][t]=ans[i-1][1][t]+m[i][1];
        ans[1][i][t]=ans[1][i-1][t]+m[1][i];
    }
    for(int i=2;i<103;i++)for(int j=2;j<103;j++)
    {
        ans[i][j][t]=ans[i-1][j][t]+ans[i][j-1][t]-ans[i-1][j-1][t]+m[i][j];
    }
}
int main()
{
    cin>>n>>q>>c;//cout<<"ok";
    for(int i=0;i<n;i++)
    {
        scanf("%d",&st[i].x);
        scanf("%d",&st[i].y);
        scanf("%d",&st[i].s);
    }
    for(int t=0;t<=c;t++)
    {
        int m[105][105]={0};
        for(int i=0;i<n;i++)
        {
            m[st[i].x][st[i].y]+=(st[i].s+t)%(c+1);
        }
        solve(t,m);
    }
    while(q--)
    {
        int t;
        int x1,y1,x2,y2;
        scanf("%d",&t);
        t%=(c+1);
        scanf("%d",&x1);
        scanf("%d",&y1);
        scanf("%d",&x2);
        scanf("%d",&y2);
        printf("%d\n",ans[x2][y2][t]-ans[x2][y1-1][t]-ans[x1-1][y2][t]+ans[x1-1][y1-1][t]);
    }
    return 0;
}