#include"bits/stdc++.h"
using namespace std;
#define ll long long
//ll k;
ll solve(ll n,ll k)
{
    if(n%2)return k-(n+1)/2;
    return solve(n/2,k/2);
}
int main()
{
    ll n,k,q;
    int t;
    cin>>n>>t;
    for(k=1;k<=n;k*=2);
    k/=2;
    while(t--)
    {
        scanf("%lld",&q);
        ll r=n-k;
        if(q%2==1&&(q+1)/2<=r)
        {
            printf("%lld\n",(q+1)/2);
        }
        else if(q%2==0&&q/2<=r)
        {
            printf("%lld\n",n-solve(k-r+q/2,k));
        }
        else
        {
            printf("%lld\n",n-solve(q-2*r,k));
        }
        //solve(?,k);
    }
    return 0;
}