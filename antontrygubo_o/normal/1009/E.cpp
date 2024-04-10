#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll N = 998244353;

ll power(ll a, ll d)
{
    if (d==0) return 1;
    if (d%2==1) return ( (power(a, d-1)*a)%N );
    if (d%2==0) {ll t = power(a, d/2); return (t*t)%N;}
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<ll> a(n);
    for (int i = 0; i<n; i++) cin>>a[i];
    vector<ll> b(n);
    b[0] = a[0];
    for (int i = 1; i<n; i++) b[i] = (b[i-1]+a[i])%N;

    ll result = 0;
    
    ll checker;
    ll here = 1;
    for (int i = n-1; i>=0; i--) 
    {
        if (i<=n-3)
        {checker = here;
        here = (here*2)%N;
        checker = (checker*(n-i+2))%N;}
        if (i==n-2)
        {
            checker = 2;
        }
        if (i==n-1)
        {
            checker = 1;
        }
        result=(result+b[i]*checker)%N;
    }
    cout<<result;
    
    
}