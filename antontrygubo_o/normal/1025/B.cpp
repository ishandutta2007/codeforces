#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll N = 998244353;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin>>n;
    ll gcd;
    ll a, b;
    ll a1, b1;
    a1 = a; b1 = b;
    cin>>a>>b;
    gcd = a*b;
    for (int i = 0; i<n-1; i++)
    {
        cin>>a>>b; gcd=__gcd(gcd, a*b);
    }
    if (gcd==1) {cout<<-1; return 0;}
    ll gcd1 = __gcd(gcd, a);
    if (gcd1>1) {for (int i = 2; i<=sqrt(gcd1); i++) if (gcd1%i==0) {cout<<i; return 0;} cout<<gcd1; return 0;}
    gcd1 = __gcd(gcd, b);
    if (gcd1>1) {for (int i = 2; i<=sqrt(gcd1); i++) if (gcd1%i==0) {cout<<i; return 0;} cout<<gcd1;}
    
}