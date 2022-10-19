#include"bits/stdc++.h"
using namespace std;
#define ll long long
vector<int>v[100005];
int vis[100005];
ll mod=1e9+7;
int solve(int i)
{
    int ans=1;
    vis[i]=1;//cout<<"<<<"<<v[i].size()<<endl;//if(i==1)cout<<v[1][0]<<" "<<vis[2]<<endl;
    for(vector<int>::iterator it=v[i].begin();it!=v[i].end();++it)
    {//cout<<*it<<" "<<<<endl;
        if(vis[*it]==0)
    {
        ans+=solve(*it);
    }}
    return ans;
}
int main()
{
    ll n,k;
    cin>>n>>k;
    ll ans=1;
    for(int i=0;i<k;i++)
    {
        ans=ans*n%mod;
    }
    for(int i=1;i<n;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(c==0)
        {
            v[a].push_back(b);
            v[b].push_back(a);
        }
    }
    for(int i=1;i<=n;i++)if(vis[i]==0)
    {
        ll t=solve(i);//cout<<t<<endl;
        ll sum=1;
        for(int j=0;j<k;j++)
        {
            sum=sum*t%mod;
        }ans-=sum;
    }
    ans%=mod;
    if(ans<0)ans+=mod;
    cout<<ans<<endl;
    return 0;
}