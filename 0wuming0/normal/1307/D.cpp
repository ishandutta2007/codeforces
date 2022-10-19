#include"bits/stdc++.h"
using namespace std;
int save[200005];
vector<int>v[200005];
int vis[200005];
int dis1[200005];
int dis2[200005];
int tp[200005],l,r;
void solve(int bg,int dis[])
{
    l=r=0;
    tp[r++]=bg;
    int now=0;
    memset(vis,0,sizeof(vis));
    vis[bg]=1;
    while(l!=r)
    {//cout<<l<<" "<<r<<endl;
        int sv=r;
        for(int i=r-1;i>=l;i--)
        {
            //cout<<"??"<<tp[i]<<" "<<now<<endl;
            dis[tp[i]]=now;
        }
        for(int i=r-1;i>=l;i--)for(auto j:v[tp[i]])if(vis[j]==0)
        {//cout<<"!!"<<tp[i]<<" "<<j<<" "<<vis[j]<<endl;
            vis[j]=1;
            tp[r++]=j;
        }
        l=sv;
        now++;
    }
}
bool cmp1(int x,int y)
{
    return dis1[x]<dis1[y];
}
int dp[200005];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<k;i++)
    {
        scanf("%d",save+i);
    }
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }//cout<<"ok"<<endl;
    solve(1,dis1);//cout<<"ok"<<endl;
    solve(n,dis2);//cout<<"??"<<dis2[n]<<endl;
    //for(int i=1;i<=n;i++)cout<<"<<"<<1<<" "<<i<<" "<<dis1[i]<<endl;
    //for(int i=1;i<=n;i++)cout<<"<<"<<n<<" "<<i<<" "<<dis2[i]<<endl;
    int ans=0;
    sort(save,save+k,cmp1);
    for(int i=k-1;i>=0;i--)
    {
        dp[i]=max(dp[i+1],dis2[save[i]]);
        //cout<<"<<"<<i<<" "<<dp[i]<<" "<<save[i]<<" "<<dis2[save[i]]<<endl;
    }
    for(int i=0;i<k-1;i++)
    {
        int x=save[i];
        ans=max(ans,dis1[x]+1+dp[i+1]);
    }
    ans=min(ans,dis1[n]);
    cout<<ans<<endl;
    return 0;
}
/*
5 5 2
1 5
1 2
2 3
3 4
3 5
2 4
*/