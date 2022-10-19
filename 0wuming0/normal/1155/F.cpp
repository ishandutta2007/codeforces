#include"bits/stdc++.h"
using namespace std;
bool can[14][14][17000];
int use[14][14][17000];
int mp[14][14];
int ans[14][14];
vector<int>bit[15],hv[17000];
int num[17000];
int dp[17000];
int last[17000][4];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<(1<<n);i++)
    {
        int k=0;
        for(int j=0;j<n;j++)if(i&(1<<j))k++;
        bit[k].push_back(i);
    }
    for(int i=1;i<(1<<n);i++)hv[0].push_back(i);
    for(int i=1;i<(1<<n);i++)
    {
        int j=0;
        while((i&(1<<j))==0)j++;
        num[i]=num[i^(1<<j)]+1;
        for(auto k:hv[i^(1<<j)])if((k&(1<<j))==0)hv[i].push_back(k);
    }
    for(int i=1;i<(1<<n);i++)dp[i]=1000;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        mp[a][b]=mp[b][a]=1;
        if(a>b)swap(a,b);
        can[a][b][(1<<a)|(1<<b)]=can[b][a][(1<<a)|(1<<b)]=1;
        use[a][b][(1<<a)|(1<<b)]=a;
        use[b][a][(1<<a)|(1<<b)]=b;
    }
    for(int bt=2;bt<n;bt++)for(auto l:bit[bt])for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(i!=j&&can[i][j][l])for(int k=0;k<n;k++)if(!((1<<k)&l)&&mp[j][k])
    {
        can[i][k][l|(1<<k)]=1;
        use[i][k][l|(1<<k)]=j;
        if(mp[i][k])
        {
            can[i][i][l|(1<<k)]=1;
            use[i][i][l|(1<<k)]=k;
            dp[l|(1<<k)]=bt+1;
            last[l|(1<<k)][0]=i;
            last[l|(1<<k)][1]=k;
            last[l|(1<<k)][2]=l|(1<<k);
            last[l|(1<<k)][3]=0;
        }
    }
    for(int bt=3;bt<n;bt++)for(auto l:bit[bt])if(dp[l]<1000)for(int i=0;i<n;i++)for(int j=i;j<n;j++)if(l&(1<<i)&&l&(1<<j))
    {
        for(auto k:hv[l])if(can[i][j][((1<<i)|(1<<j))^k]&&dp[l|k]>dp[l]+num[k]+1)
        {
            dp[l|k]=dp[l]+num[k]+1;
            last[l|k][0]=i;
            last[l|k][1]=j;
            last[l|k][2]=((1<<i)|(1<<j))^k;
            last[l|k][3]=l;
        }
    }
    for(int i=(1<<n)-1;i;i=last[i][3])
    {
        int ii=last[i][0];
        int jj=last[i][1];
        int kk=last[i][2];
        if(ii==jj)
        {
            jj=use[ii][jj][kk];
            ans[ii][jj]=ans[jj][ii]=1;
        }
        while(1)
        {
            ans[use[ii][jj][kk]][jj]=1;
            ans[jj][use[ii][jj][kk]]=1;
            if(use[ii][jj][kk]==ii)break;
            kk^=1<<jj;
            jj=use[ii][jj][kk^(1<<jj)];
        }
        if(last[i][3]==0)
        {
            ans[last[i][0]][last[i][1]]=1;
            ans[last[i][1]][last[i][0]]=1;
        }
    }
    cout<<dp[(1<<n)-1]<<endl;
    for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)if(ans[i][j])cout<<i+1<<" "<<j+1<<endl;
    return 0;
}