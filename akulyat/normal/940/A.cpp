#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;



ll n,i,j,d;
vector <ll> m;

int main()
{
cin>>n>>d;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
sort(m.begin(), m.end());
ll ans=0;
for (i=0; i<n; i++)
  for (j=i; j<n; j++)
    {
    if (m[j]-m[i]<=d)
      ans=max(ans, j-i+1);
    }

cout<<n-ans;
    return 0;
}