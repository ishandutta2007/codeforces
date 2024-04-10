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


ll n,i,j;
vector <ll> m,var;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
var.push_back(0);
for (ll i=0; i<n; i++)
  {
  vector <ll> a,b;
  for (auto j:var)
    a.push_back(j+m[i]),
    b.push_back(j-m[i]);
  var.clear();
  for (auto i:a)
    var.push_back(i);
  for (auto i:b)
    var.push_back(i);
  }
for (auto &i:var)
  {
  i%=360;
  i+=360*10;
  i%=360;
  }
for (auto i:var)
  if ((i%360)==0)
    {
    cout<<"YES";
    return 0;
    }
cout<<"NO";








    return 0;
}