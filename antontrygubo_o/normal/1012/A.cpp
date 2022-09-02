#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 998244353;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<ll> a;
    ll temp;
    for (int i = 0; i<2*n; i++) {cin>>temp; a.push_back(temp);}
    sort(a.begin(), a.end());
    ll minn = (a[n-1]-a[0])*(a[2*n-1]-a[n]);
    for (int i = 1; i<n; i++) minn = min(minn, (a[2*n-1]-a[0])*(a[i+n-1]-a[i]));
    cout<<minn;
}