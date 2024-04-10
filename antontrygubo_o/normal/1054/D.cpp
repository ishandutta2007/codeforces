#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll p = 1e9 + 7;

ll res(ll a)
{
    return (a*(a-1))/2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    ll n, k;
    cin>>n>>k;
    vector<ll> a(n);
    for (int i = 0; i<n; i++) cin>>a[i];
    vector<ll> b(n+1);
    b[0] = 0;
    for (int i = 0; i<n; i++) b[i+1] = b[i]^a[i];
    ll t = 1;
    for (int i = 0; i<k; i++) t*=2;
    t-=1;
    for (int i = 0; i<=n; i++) if (2*b[i]>t) b[i] = b[i]^t;
    sort(b.begin(), b.end());
    
    
    ll counter = 0;
    
    ll current = 1;
    for (int i = 1; i<=n+1; i++)
    {
        if ((i==n+1)||(b[i]!=b[i-1])) 
        {
            ll x1 = current/2;
            ll x2 = current - x1;
            counter+=res(x1); 
            counter+=res(x2);
            current = 1;
        }
        else current++;
    }
    
    cout<<n*(n+1)/2 - counter;
}