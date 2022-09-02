#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, h;
    cin>>n>>h;
    vector<pair<ll, ll>> a(n);
    for (int i = 0; i<n; i++) cin>>a[i].first>>a[i].second;
    vector<ll> b(n-1);
    for (int i = 0; i<n-1; i++) b[i] = a[i+1].first-a[i].second;
    
    ll maxres = 0;
    int idx = 0;
    ll fly = a[0].second-a[0].first;
    ll fall = 0;

    
    idx = 0; fall = 0;
    for (int i = 0; i<n; i++)
    {
        if (i!=0) {fly-=(a[i-1].second-a[i-1].first); if (idx>=i) fall -=(a[i].first-a[i-1].second);}
        if (idx<i) {idx++; fly+=(a[idx].second-a[idx].first);}
        while (idx<n-1&&fall+a[idx+1].first-a[idx].second<h) {fall+=a[idx+1].first-a[idx].second; idx++; fly+=a[idx].second-a[idx].first;}
        maxres = max(maxres, fly+h);
        //cout<<i<<' '<<idx<<' '<<fly<<' '<<fall<<endl;
    }

    cout<<maxres;
}