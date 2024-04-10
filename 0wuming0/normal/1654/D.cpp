#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll mod=998244353;
vector<pair<int,pair<int,int> > >v[200005];
int vis[200005];
int prime[200005];
int mul[200005];
ll inv[200005];
ll nowans,now;
int getprime(int &n)
{
    int ans=prime[n];
    if(ans==0)ans=n;
    n/=ans;
    return ans;
}
void add(int p)
{
    while(p!=1)
    {
        int a=getprime(p);
        mul[a]++;
        now=now*a%mod;
    }
}
void del(int p)
{
    while(p!=1)
    {
        int a=getprime(p);
        if(mul[a]==0)nowans=nowans*a%mod;
        else
        {
            mul[a]--;
            now=now*inv[a]%mod;
        }
    }
}
void dfs(int i)
{
    nowans=(nowans+now)%mod;
    vis[i]=1;
    for(auto &pr:v[i])if(vis[pr.first]==0)
    {
        int &j=pr.first;
        int &a=pr.second.first;
        int &b=pr.second.second;
        add(b);del(a);
        dfs(j);
        add(a);del(b);
    }
}
int main()
{
    inv[1]=1;
    for(int i=2;i<200005;i++)inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    for(int i=2;i<200005;i++)if(prime[i]==0)for(int j=2;i*j<200005;j++)prime[i*j]=i;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<=n+2;i++)
        {
            v[i].clear();
            vis[i]=0;
            mul[i]=0;
        }
        nowans=0;
        now=1;
        for(int i=1;i<n;i++)
        {
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            v[a].push_back(pair<int,pair<int,int> >(b,pair<int,int>(c,d)));
            v[b].push_back(pair<int,pair<int,int> >(a,pair<int,int>(d,c)));
        }
        dfs(1);
        cout<<nowans<<endl;
    }
    return 0;
}