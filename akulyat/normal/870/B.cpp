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


ll n,i,j,k;
vector <ll> m;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
if (k==1)
  {
  ll z=inf;
  for (auto i:m)
    z=min(z, i);
  cout<<z<<endl;
  return 0;
  }
if (k>=3)
  {
  ll z=-inf;
  for (auto i:m)
    z=max(z, i);
  cout<<z<<endl;
  return 0;
  }
cout<<max(m[0], m.back())<<endl;








    return 0;
}