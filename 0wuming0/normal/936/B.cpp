#include"bits/stdc++.h"
using namespace std;
#define ll long long
int n,m;
int dp[100005];
vector<int>v[100005];
vector<int>vout[100005];
int num[100005];
int vis[100005][2];
int dp2[100005][2];
void solve(int i,int op,int dd)
{
    vis[i][op]=1;
    dp2[i][op]=dd;
    for(auto p:vout[i])
    {
        if(vis[p][op^1]==0)
        {
            solve(p,op^1,dd+1);
        }
    }
}
int vis2[100005][2];
void output(int i,int op)
{
    vis2[i][op]=1;
    if(v[i].size()==0)
    {
        return;
    }
    for(auto p:v[i])
    {
        if(vis[p][op^1]==1&&dp2[i][op]>dp2[p][op^1])
        {
            printf(" %d",p);
            output(p,op^1);
            return;
        }
    }
    exit(1);
}
void solve2(int i)
{
    dp[i]=1;
    for(auto j:vout[i])
    {
        num[j]--;
        if(num[j]==0&&dp[j]==0)
            solve2(j);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int c;
        scanf("%d",&c);
        num[i]=c;
        while(c--)
        {
            int t;
            scanf("%d",&t);
            v[i].push_back(t);
            vout[t].push_back(i);
        }
    }
    int bg;
    cin>>bg;
    for(int i=0;i<=n;i++)dp2[i][0]=dp2[i][1]=1e9;
    for(int i=1;i<=n;i++)if(vis[i][0]==0&&num[i]==0)
    {
        solve(i,0,0);
    }
    for(int i=1;i<=n;i++)if(dp[i]==0&&num[i]==0)
    {
        solve2(i);
    }
    //for(int i=1;i<=n;i++)printf("%d%c",vis[i][0]," \n"[i==n]);
    //for(int i=1;i<=n;i++)printf("%d%c",vis[i][1]," \n"[i==n]);
    if(vis[bg][1]==1)
    {
        cout<<"Win"<<endl;
        cout<<bg;
        output(bg,1);
        cout<<endl;
    }
    else if(dp[bg]==1)cout<<"Lose"<<endl;
    else cout<<"Draw"<<endl;
    return 0;
}
/*
5 1
1 2
0
0
0
0
1
*/