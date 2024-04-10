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
    if (n%2==0) {cout<<n/2; return 0;}
    for (int i = 3; i<=sqrt(n); i++) if (n%i==0)
    {
        cout<<1+(n-i)/2; return 0;
    }
    cout<<1;
}