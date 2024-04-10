#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll ans;
void cal(ll a,ll b,ll c)
{
    ll now=a*b/__gcd(a,b);
    now=now*c/__gcd(c,now);
    ans=max(now,ans);
}
int main()
{
    int n;
    cin>>n;
    for(int i=max(n-8,1);i<=n;i++)for(int j=i;j<=n;j++)for(int k=j;k<=n;k++)
    {
        cal(i,j,k);
    }
    cout<<ans<<endl;
    return 0;
}