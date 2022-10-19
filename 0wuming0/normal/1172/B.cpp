#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll mod=998244353;
vector<int>v[200005];
int vis[200005];
int num[200005];
ll jie[200005];
ll solve(int i)
{
    vis[i]=1;
    int ni=1;
    ll ans=1;
    int mi=0;
    for(auto j:v[i])if(vis[j]==0)
    {
        ans=ans*solve(j)%mod;
        ni+=num[j];
        mi++;
    }
    if(i==1)
    {
        ans=ans*jie[mi]%mod;
        return ans;
    }
    num[i]=ni;
    ans=ans*(mi+1)%mod;//*ni
    ans=ans*jie[mi]%mod;
    //cout<<"<<<<"<<i<<" "<<ans<<endl;
    return ans;
}
int main()
{
    jie[0]=jie[1]=1;
    for(int i=2;i<200005;i++)jie[i]=jie[i-1]*i%mod;
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cout<<solve(1)*n%mod<<endl;
    return 0;
}
/*
2
1 2

4
2 3
2 1
2 4

4
2 3
2 4
3 1

4
2 4
2 3
4 1
*/