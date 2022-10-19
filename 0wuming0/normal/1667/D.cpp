#include"bits/stdc++.h"
using namespace std;
bool dp[200005][2];
vector<int>v[200005];
vector<int>save[200005];
int vis[200005];
int fa[200005];
void dfs(int i)
{
    vis[i]=1;
    for(auto j:v[i])if(vis[j]==0)
    {
        fa[j]=i;
        save[i].push_back(j);
        dfs(j);
    }
}
void solve(int i)
{
    int s[4]={0};
    for(auto j:v[i])
    {
        solve(j);
        //cout<<"<<"<<j<<" "<<dp[j][0]<<" "<<dp[j][1]<<endl;
        if(dp[j][0]==0&&dp[j][1]==0)return;
        int tt=0;
        if(dp[j][0])tt|=2;
        if(dp[j][1])tt|=1;
        s[tt]++;
    }
    int num=v[i].size();
    if(i-1)num++;
    if(num&1)
    {
        int num2=num/2;
        int num1=num-num2;//cout<<"??"<<i<<" "<<num1<<" "<<num2<<endl;
        num1-=s[1];
        num2-=s[2];//cout<<"??"<<i<<" "<<num1<<" "<<num2<<endl;
        if(num1<0||num2<0)return;
        if(i==1)
        {
            dp[i][0]=1;
            return;
        }
        if(num1)dp[i][1]=1;
        if(num2)dp[i][0]=1;
        //1 2 1 2 1 2 1 2
    }
    else
    {
        int num1=num/2;
        int num2=num-num1;
        num1-=s[1];
        num2-=s[2];
        if(num1<0||num2<0)return;
        if(i==1)
        {
            dp[i][0]=1;
            return;
        }
        if(num1)dp[i][1]=1;
        if(num2)dp[i][0]=1;
    }
}
void solve2(int i,int op)
{//cout<<"<<"<<"ok"<<" "<<i<<" "<<op<<endl;
    vector<int>save[4];
    int s[4]={0};
    for(auto j:v[i])
    {
        int tt=0;
        if(dp[j][0])tt|=2;
        if(dp[j][1])tt|=1;
        save[tt].push_back(j);
    }
    int num=v[i].size();
    if(i-1)num++;
    bool flag=1;
    if(i==1)flag=0;
    for(;num;num--)
    {
        if(num&1)
        {
            if(flag&&op==1)
            {
                printf("%d %d\n",fa[i],i);
                flag=0;
            }
            else if(save[1].size())
            {
                solve2(save[1][save[1].size()-1],1);
                save[1].pop_back();
            }
            else if(save[3].size())
            {
                solve2(save[3][save[3].size()-1],1);
                save[3].pop_back();
            }
        }
        else
        {
            if(flag&&op==2)
            {
                printf("%d %d\n",fa[i],i);
                flag=0;
            }
            else if(save[2].size())
            {
                solve2(save[2][save[2].size()-1],2);
                save[2].pop_back();
            }
            else if(save[3].size())
            {
                solve2(save[3][save[3].size()-1],2);
                save[3].pop_back();
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(1);
        for(int i=0;i<=n;i++)
        {
            v[i]=save[i];
            save[i].clear();
        }
        solve(1);
        //cout<<"<<"<<1<<" "<<dp[1][0]<<" "<<dp[1][1]<<endl;
        if(dp[1][0]||dp[1][1])
        {
            printf("YES\n");
            solve2(1,0);
        }
        else
        {
            printf("NO\n");
        }
        for(int i=0;i<=n;i++)dp[i][0]=dp[i][1]=vis[i]=0;
        for(int i=0;i<=n;i++)v[i].clear();
    }
    return 0;
}