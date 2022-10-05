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

void normal()
{
vector <pll> v;
sort(m.begin(), m.end());
m.push_back({mod, mod});
for (ll i=0; i<n; i++)
  if (m[i].F!=m[i+1].F)
    v.push_back(m[i]);
m=v;
n=m.size();
}

bool pop(vector <pll> tr)
{
ll n=tr.size();
tr.push_back(tr[0]);
ll res=0;
for (ll i=0; i<n; i++)
  res+=(tr[i+1].F-tr[i].F)*(tr[i+1].S+tr[i].S);
return (res<=0);
}

vector <pll> build_hull(vector <pll> m)
{
vector <pll> v;
v.push_back(m[0]);
n=m.size();
for (ll i=1; i<n; i++)
  {
  while (v.size()>1&&pop({v[v.size()-2], v[v.size()-1], m[i]}))
    v.pop_back();
  v.push_back(m[i]);
  }
return v;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a,b;
  cin>>a>>b;
  m.push_back({a, b-a*a});
  }
normal();
vector <pll> ch=build_hull(m);
cout<<ch.size()-1<<endl;







    return 0;
}