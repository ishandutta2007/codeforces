#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll p = 998244353;

ll fill(ll n)
{
    ll i = max((ll)(sqrt(n))-10, (ll)(0));
    while (i*(i+1)/2<n) i++;
    return i;
}

int main()
{
    ios_base::sync_with_stdio(0);

    ll n, m;
    cin>>n>>m;
    if (n<=m) {cout<<n; return 0;}
    n-=m;
    cout<<fill(n) + m;
    
}