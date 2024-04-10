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


ll n,i,j,a,b;
vector <ll> m;
bool viv=false;


int main()
{
cin>>n>>a>>b;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m[i]=abs(m[i]-a);
  }

a+=b;

for (j=0; j<a; j++)
  {
  ll z=0;
  for (i=0; i<n; i++)
    if (m[i]>m[z])
      z=i;
  m[z]--;
  m[z]=abs(m[z]);
  }

ll ans=0;
for (i=0; i<n; i++)
  ans+=m[i]*m[i];

cout<<ans;


    return 0;
}