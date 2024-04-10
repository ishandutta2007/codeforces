#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 998244353;
const ll MAX = 100000000000;

int main()
{
ios_base::sync_with_stdio(false);
ll n, m;
cin>>n>>m;
vector<ll> a(n, 0);
cin>>a[0];
for (int i = 1; i<n; i++) {cin>>a[i]; a[i]+=a[i-1];}
cout<<a[0]/m<<' ';
for (int i = 1; i<n; i++) cout<<((a[i]/m)-(a[i-1]/m))<<' ';

}