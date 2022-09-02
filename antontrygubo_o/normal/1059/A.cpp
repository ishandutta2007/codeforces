#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n, L, a;
    cin>>n>>L>>a;
    if (n==0) {cout<<L/a; return 0;}
    ll t[n];
    ll l[n];
    for (int i = 0; i<n; i++) cin>>t[i]>>l[i];
    ll ans[n+1];
    ans[0] = t[0];
    ans[n] = L-t[n-1]-l[n-1];
    for (int i = 1; i<n; i++) ans[i] = t[i] - t[i-1] - l[i-1];
    ll answer = 0;
    for (int i = 0; i<=n; i++) answer+=ans[i]/a;
    cout<<answer;
}