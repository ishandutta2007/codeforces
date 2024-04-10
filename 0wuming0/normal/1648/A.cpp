#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll sum[100005];
ll cal(vector<int>v)
{
    int n=v.size();
    if(n<=1)return 0;
    sort(v.begin(),v.end());
    sum[0]=v[0];
    for(int i=1;i<n;i++)sum[i]=sum[i-1]+v[i];
    ll ans=0;
    for(int i=n-1;i>0;i--)
    {
        ans+=i*1ll*v[i]-sum[i-1];
    }
    return ans;
}
vector<int>l[100005],r[100005];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)
    {
        int c;
        scanf("%d",&c);
        l[c].push_back(i);
        r[c].push_back(j);
    }
    ll ans=0;
    for(int i=0;i<100005;i++)
    {
        ans+=cal(l[i]);
        ans+=cal(r[i]);
    }
    cout<<ans<<endl;
    return 0;
}