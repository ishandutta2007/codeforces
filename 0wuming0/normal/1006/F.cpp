#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll a[24][24];
vector<ll>save1[24][24];
vector<ll>save2[24][24];
ll ans;
void solve(vector<ll>&v1,vector<ll>&v2,ll k)
{
    map<ll,int>mp;
    for(auto a:v1)
    {//cout<<"<<"<<a<<" "<<k<<endl;
        a^=k;
        if(mp.find(a)!=mp.end())mp[a]++;
        else mp[a]=1;
    }
    for(auto a:v2)
    {//cout<<"<<"<<a<<endl;
        if(mp.find(a)!=mp.end())ans+=mp[a];
    }
}
int main()
{
    int n,m;
    ll k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
    int mid=(n+m>>1)+1;
    save1[1][1].push_back(a[1][1]);
    save2[n][m].push_back(a[n][m]);
    for(int s=2;s<mid;s++)
    {
        for(int i=1;i<=n;i++)
        {
            int j=s-i;
            if(j>m||j<1)continue;
            int i2,j2;
            i2=i+1;j2=j;
            if(i2<=n&&j2<=m&&i2>0&&j2>0)for(auto b:save1[i][j])save1[i2][j2].push_back(b^a[i2][j2]);
            i2=i;j2=j+1;
            if(i2<=n&&j2<=m&&i2>0&&j2>0)for(auto b:save1[i][j])save1[i2][j2].push_back(b^a[i2][j2]);
        }
    }
    for(int s=n+m;s>mid;s--)
    {
        for(int i=1;i<=n;i++)
        {
            int j=s-i;
            if(j>m||j<1)continue;
            int i2,j2;
            i2=i-1;j2=j;
            if(i2<=n&&j2<=m&&i2>0&&j2>0)for(auto b:save2[i][j])save2[i2][j2].push_back(b^a[i2][j2]);
            i2=i;j2=j-1;
            if(i2<=n&&j2<=m&&i2>0&&j2>0)for(auto b:save2[i][j])save2[i2][j2].push_back(b^a[i2][j2]);
        }
    }//for(auto k:save2[3][3])cout<<"??"<<k<<endl;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
    {
        if(i+j!=mid)continue;
        solve(save1[i][j],save2[i][j],a[i][j]^k);
    }
    cout<<ans<<endl;
    return 0;
}