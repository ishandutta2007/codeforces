#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll p = 998244353;



int main()
{
    ios_base::sync_with_stdio(0);

    ll n;
    cin>>n;
    ll ans = 1;
    for (ll i = 1; i<=n+1; i++) ans = (ans*i)%p;
    
    ll temp = 1;
    for (ll i = n; i>=1; i--) 
    {
        temp = (temp*i)%p;
        ans = (ans-temp)%p;
    }
    
    if (ans<0) ans+=p;
    cout<<ans;
    
}