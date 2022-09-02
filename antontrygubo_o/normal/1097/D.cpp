#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll p = 1e9+7;

ll n, k;

ll po(ll n, ll deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return (po(n, deg-1)*n)%p;
    ll t = po(n, deg/2);
    return (t*t)%p;
}

ll inv(ll n)
{
    return po(n, p-2);
}

vector<ll> inverse(10000);

ll E(ll prime, ll deg)
{
    vector<vector<ll>> a(k+1, vector<ll>(deg+1));
    a[0][0] = 1;
    for (int i = 1; i<=deg; i++) a[0][i] = (a[0][i-1]*prime)%p;
    
    for (int j = 1; j<=k; j++)
    {
        ll summ = 0;
        for (int i = 0; i<=deg; i++) 
        {
            summ = (summ+a[j-1][i])%p; a[j][i] = (summ*inverse[i+1])%p;
        }
    }
    return a[k][deg];
}

ll result = 1;

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    
    for (int i = 1; i<10000; i++) inverse[i] = inv(i);
    
    if (n==1) {cout<<1; return 0;}
    for (int i = 2; i<=sqrt(n); i++) if (n%i==0)
    {
        ll count = 0;
        while (n%i==0) {count++; n/=i;}
        result = (result*E(i, count))%p;
    }
    
    if (n!=1) result = (result*E(n, 1))%p;
    
    cout<<result;
}