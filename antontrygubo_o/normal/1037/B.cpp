#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, s;
    cin>>n>>s;
    vector<ll> a(n); for (int i = 0; i<n; i++) cin>>a[i];
    sort(a.begin(), a.end());
    int k = n/2;
    ll kek = a[k];
    if (kek==s) {cout<<0; return 0;}
    if (kek<s) 
    {
        ll result = 0;
        int idx = k;
        while (idx<n&&a[idx]<s) {result+=s-a[idx]; idx++;}
        cout<<result;
    }
    else if (kek>s) 
    {
        ll result = 0;
        int idx = k;
        while (idx>=0&&a[idx]>s) {result+=a[idx]-s; idx--;}
        cout<<result;
    }
}