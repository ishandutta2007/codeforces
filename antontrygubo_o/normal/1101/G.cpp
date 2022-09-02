#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);    

    ll n;
    cin>>n;
    vector<ll> a(n);
    for (int i = 0; i<n; i++) cin>>a[i];
    
    vector<ll> b(n);
    b[0] = a[0];
    for (int i = 1; i<n; i++) b[i] = b[i-1]^a[i];
    if (b[n-1]==0) {cout<<-1; return 0;}
    
    int counter = 1;

    int k = 0;
    while (b[n-1]>=1<<k) k++;
    k--;
    for (int i = 0; i<n; i++) if (b[i]&(1<<k)) b[i]^=b[n-1];
    
    while (1)
    {
        ll maxx = 0;
        for (int i = 0; i<n; i++) maxx = max(maxx, b[i]);
        if (maxx==0) {cout<<counter; return 0;}
        counter++;
        int k = 0;
        while (maxx>=1<<k) k++;
        k--;
        for (int i = 0; i<n; i++) if (b[i]&(1<<k)) b[i]^=maxx;
    }
}