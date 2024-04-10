#include <bits/stdc++.h>
using namespace std;
const int N=20;

int n;
double a[N][N];
double ans[1<<N][N];

void dfs(int x,int u)
{
    if(x==(1<<(n-1))-1)
    {
        ans[x][u]=a[0][u];
        return;
    }
    for(int i=1;i<n;++i)
    {
        int y=(x|(1<<(i-1)));
        if(y!=x)
        {
            if(ans[y][i]<0)
                dfs(y,i);
            if(ans[y][u]<0)
                dfs(y,u);
            ans[x][u]=max(ans[x][u],ans[y][i]*a[i][u]+ans[y][u]*a[u][i]);
        }
    }
}

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(15);
//////////////////////////////////////
    cin>>n;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>a[i][j];
        }
    }
    if(n==1)
    {
        cout<<1.0<<endl;
        return 0;
    }
    for(int i=0;i<(1<<(n-1));++i)
        for(int j=0;j<n;++j)
            ans[i][j]=-1;
    double yans=-1;
    for(int i=1;i<n;++i)
    {
        int x=(1<<(i-1));
        dfs(x,i);
            yans=max(yans,ans[x][i]);
    }
    cout<<yans<<endl;
    return 0;
}