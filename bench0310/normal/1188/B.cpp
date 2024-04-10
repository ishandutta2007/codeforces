#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int n;
    ll p,k;
    scanf("%d%I64d%I64d",&n,&p,&k);
    map<ll,ll> m;
    for(int i=0;i<n;i++)
    {
        ll x;
        scanf("%I64d",&x);
        ll a=1;
        for(int j=0;j<4;j++) a=(a*x)%p;
        a=(((a-k*x)%p)+p)%p;
        m[a]++;
    }
    ll res=0;
    for(auto [a,c]:m) res+=(c*(c-1)/2);
    printf("%I64d\n",res);
    return 0;
}