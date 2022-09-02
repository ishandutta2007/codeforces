#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll p = 998244353;


int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<ll> a(n);
    for (int i = 0; i<n; i++) cin>>a[i];
    vector<ll> h(n), ha(n), har(n), hard(n);
    
    if (s[0]=='h') h[0] = a[0];
    for (int i = 1; i<n; i++)
    {
        h[i] = h[i-1]; if (s[i]=='h') h[i]+=a[i];
    }
    
    for (int i = 1; i<n; i++)
    {
        ha[i] = ha[i-1];
        if (s[i]=='a') ha[i] = min(ha[i-1]+a[i], h[i-1]);
    }
    
    for (int i = 2; i<n; i++)
    {
        har[i] = har[i-1];
        if (s[i]=='r') har[i] = min(har[i-1]+a[i], ha[i-1]);
    }
    
    for (int i = 3; i<n; i++)
    {
        hard[i] = hard[i-1];
        if (s[i]=='d') hard[i] = min(hard[i-1]+a[i], har[i-1]);
    }
    
    cout<<hard[n-1];
}