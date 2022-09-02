#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n, k, d;
    cin>>n>>k>>d;
    ll a[n];
    for (int i = 0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a, a+n);
    set<ll> good;
    good.insert(0);
    for (int i = 1; i<=n; i++)
    {
        if (i<k) continue;
        else
        {
            while (good.size()>0&&a[*(good.begin())]<a[i-1]-d) good.erase(good.begin());
        }
        if (good.size()>0&&i-*(good.begin())>=k) good.insert(i);
    }
    if (good.find(n)!=good.end()) cout<<"YES";
    else cout<<"NO";
}