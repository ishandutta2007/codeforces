#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll p = 998244353;



int main()
{
    ios_base::sync_with_stdio(0);
    ll n;
    cin>>n;
    vector<ll> good;
    for (ll i = 1; i<=sqrt(n); i++) if (n%i==0)
    {
        ll m = n/i;
        good.push_back(m+(n*(m-1))/2);
        if (m*m!=n) good.push_back(i+(n*(i-1))/2);
    }
    sort(good.begin(), good.end());
    //cout<<good.size()<<endl;
    for (int i = 0; i<good.size(); i++) cout<<good[i]<<' ';
}