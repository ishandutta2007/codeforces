#include"bits/stdc++.h"
using namespace std;
vector<int>v[200005];
int vis[200005];
int dp[200005][2][2];
int use[200005][2];
void dfs(int i)
{
    vis[i]=1;
    int ans00=0,ans01=0;
    int ans10=0,ans11=0;
    for(auto j:v[i])if(vis[j]==0)
    {
        dfs(j);
        ans00+=dp[j][0][0];
        ans01+=dp[j][0][1];
        if(dp[j][0][0]>dp[j][1][0]||(dp[j][0][0]==dp[j][1][0]&&dp[j][0][1]<dp[j][1][1]))
        {
            ans10+=dp[j][0][0];
            ans11+=dp[j][0][1];
        }
        else
        {
            ans10+=dp[j][1][0];
            ans11+=dp[j][1][1];
        }
    }
    dp[i][0][0]=ans10;
    dp[i][0][1]=ans11;
    dp[i][1][0]=ans00+1;
    dp[i][1][1]=ans01+v[i].size()-1;
    //cout<<"???"<<i<<" "<<dp[i][0][0]<<" "<<dp[i][0][1]<<" "<<dp[i][1][0]<<" "<<dp[i][1][1]<<endl;
}
int ans[200005];
void solve(int i)
{
    vis[i]=1;
    int ans00=0,ans01=0;
    int ans10=0,ans11=0;
    if(use[i][0])
    {
        ans[i]=1;
        for(auto j:v[i])if(vis[j]==0)
        {
            if(dp[j][0][0]>dp[j][1][0]||(dp[j][0][0]==dp[j][1][0]&&dp[j][0][1]<dp[j][1][1]))
            {
                ans10+=dp[j][0][0];
                ans11+=dp[j][0][1];
                use[j][0]=1;
            }
            else
            {
                ans10+=dp[j][1][0];
                ans11+=dp[j][1][1];
                use[j][1]=1;
            }
            solve(j);
        }
    }
    else
    {
        ans[i]=v[i].size();
        for(auto j:v[i])if(vis[j]==0)
        {
            ans00+=dp[j][0][0];
            ans01+=dp[j][0][1];
            use[j][0]=1;
            solve(j);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    if(n==2)
    {
        cout<<"2 2"<<endl;
        cout<<"1 1"<<endl;
        return 0;
    }
    dfs(1);
    for(int i=1;i<=n;i++)vis[i]=0;
    if(dp[1][0][0]>dp[1][1][0]||(dp[1][0][0]==dp[1][1][0]&&dp[1][0][1]<dp[1][1][1]))
    {
        cout<<dp[1][0][0]<<" "<<dp[1][0][1]+n<<endl;
        use[1][0]=1;
    }
    else
    {
        cout<<dp[1][1][0]<<" "<<dp[1][1][1]+n<<endl;
        use[1][1]=1;
    }
    solve(1);
    for(int i=1;i<=n;i++)printf("%d%c",ans[i]," \n"[i==n]);
    return 0;
}