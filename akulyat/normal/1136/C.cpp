#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;


ll n,i,j, m;
bool viv=false;
multiset <long> sa[2*kk];
multiset <long> sb[2*kk];

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m;
for (i=0; i<n; i++)
  {
  for (ll j=0; j<m; j++)
    {
    ll x;
    cin>>x;
    sa[i+j].insert(x);
    }
  }
for (i=0; i<n; i++)
  {
  for (ll j=0; j<m; j++)
    {
    ll x;
    cin>>x;
    sb[i+j].insert(x);
    }
  }
for (ll i=0; i<n+m-1; i++)
  if (sa[i]!=sb[i])
    {
    cout<<"NO";
    exit(0);
    }
cout<<"YES";




    return 0;
}