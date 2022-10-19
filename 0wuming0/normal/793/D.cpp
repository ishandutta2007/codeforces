#include"bits/stdc++.h"
using namespace std;
int dp[82][82][82][82];
map<int,int>mp[82];
int nn[82];
pair<int,int>save[82][82];
int main()
{
    //printf("%f",pow(82,4)*4);
    int n,k;
    cin>>n>>k;
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a==b)continue;
        if(mp[a].find(b)==mp[a].end())mp[a][b]=c;
        else mp[a][b]=min(mp[a][b],c);
        //if(mp[b].find(a)==mp[b].end())mp[b][a]=c;
        //else mp[b][a]=min(mp[b][a],c);
    }
    for(int i=1;i<=n;i++)for(auto pr:mp[i])save[i][nn[i]++]=pr;
    for(int num=2;num<=k;num++)
    for(int i=1;i<=n;i++)for(int d=0;i+d<=n;d++)
    {
        int j=i+d;
        //dp[i][j][now][k]
        for(int now=i;now<=j;now++)
        {
            dp[i][j][now][num]=1e9;
            for(int c=0;c<nn[now];c++)if(i<=save[now][c].first&&save[now][c].first<=j)
            {
                if(save[now][c].first<now)
                    dp[i][j][now][num]=min(dp[i][j][now][num],dp[i][now-1][save[now][c].first][num-1]+save[now][c].second);
                else dp[i][j][now][num]=min(dp[i][j][now][num],dp[now+1][j][save[now][c].first][num-1]+save[now][c].second);
            }
        }
    }
    int ans=1e9;
    for(int i=1;i<=n;i++)ans=min(ans,dp[1][n][i][k]);
    if(ans==1e9)ans=-1;
    cout<<ans<<endl;
    return 0;
}