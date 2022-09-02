#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll a, b, x, y;
    cin>>a>>b>>x>>y;
    ll t = __gcd(x, y);
    x/=t;
    y/=t;
    ll res1 = a/x;
    ll res2 = b/y;
    cout<<min(res1, res2);
}