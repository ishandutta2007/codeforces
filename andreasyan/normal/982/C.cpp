#include <bits/stdc++.h>
using namespace std;
const int N=100005;

int n;
vector<int> a[N];

int dp[N][2];
void dfs(int x,int p)
{
    if(a[x].size()==1 && p!=-1)
    {
        dp[x][0]=-1;
        dp[x][1]=0;
        return;
    }
    int m=0;
    for(int i=0;i<a[x].size();++i)
    {
        int h=a[x][i];
        if(p==h)
            continue;
        dfs(h,x);
        //0000000
        if(dp[h][0]!=-1)
            dp[x][0]+=dp[h][0];
        else
        {
            dp[x][0]+=dp[h][1];
            ++m;
        }
        //1111111
    }
    if(m%2==1)
    {
        dp[x][0]+=m;
        dp[x][1]=-1;
    }
    else
    {
        dp[x][1]=dp[x][0]+m;
        dp[x][0]=-1;
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1,-1);
    if(dp[1][0]==-1)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    cout<<(n-1)-dp[1][0]<<endl;
    return 0;
}