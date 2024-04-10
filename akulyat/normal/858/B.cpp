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
vector <pll> m;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll f;
cin>>f>>n;
f--;
for (i=0; i<n; i++)
  {
  ll a,b;
  cin>>a>>b;
  a--; b--;
  m.push_back({a, b});
  }
if (n==0)
  {
  if (f==0)
    cout<<1;
  else
    cout<<-1;
  return 0;
  }

set <ll> ans;
for (i=1; i<1000; i++)
  {
  bool good=true;
  for (auto j:m)
    if (j.F/i!=j.S)
      good=false;
  if (good)
    ans.insert(f/i+1);
  }
if (ans.size()>1)
  {
  cout<<-1<<endl;
  return 0;
  }
cout<<*ans.begin()<<endl;


    return 0;
}