#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll c[300005],d[300005];
int lowbit(int x)  //==2^k k0
{
    return x&(-x);
}
pair<ll,int> getsum(int x)
{
    ll ans=0;
    int num=0;
    for(int i=x;i>0;i-=lowbit(i))//
    {
        ans+=c[i];
        num+=d[i];
    }
    return pair<ll,int>(ans,num);
}
void update(int x,ll value)
{
    for(int i=x;i<=300000;i+=lowbit(i))
    {
        c[i]+=value;
        d[i]++;
    }
}
ll x[200005],v[200005];
int pos[200005];
bool cmp(int a,int b)
{
    if(v[a]!=v[b])return v[a]<v[b];
    else return x[a]<x[b];
}
int main()
{
    int n;
    cin>>n;
    ll ans=0;
    map<ll,int>mp;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",x+i);
        mp[x[i]]=1;
    }
    int nn=0;
    for(auto &pr:mp)pr.second=++nn;
    for(int i=1;i<=n;i++)scanf("%lld",v+i),pos[i]=i;
    sort(pos+1,pos+1+n,cmp);
    for(int i=1;i<=n;i++)
    {//cout<<x[pos[i]]<<" "<<v[pos[i]]<<endl;
        auto pr=getsum(mp[x[pos[i]]]);//cout<<"!!"<<pr.first<<" "<<pr.second<<endl;
        ans+=x[pos[i]]*pr.second-pr.first;//cout<<"???"<<ans<<endl;
        update(mp[x[pos[i]]],x[pos[i]]);
    }
    cout<<ans<<endl;
    return 0;
}