#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, k;
    cin>>n>>k;
    if (k<=n+1 )
    {
        cout<<(k-1)/2; return 0;
    }
    ll k1 = 2*(n+1)-k; 
    if (k1<=2) {cout<<0; return 0;}
    cout<<(k1-1)/2;

}