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

bool solve(ll kol)
{
if (viv)
  cout<<"Check "<<kol<<endl;
ll las=-1;
for (ll i=0; i<n; i++)
  {
  ll v=m[i];
  ll to=v+kol;
  if (to<k)
    {
    if (las>to)
      return false;
    las=max(las, v);
    }
  else
    {
    if (to>=las+k)
      {}
    else
      {
      las=max(v, las);
      }
    }
  if (viv)
    cout<<"new "<<las<<endl;
  }
return true;
}

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
ll l=-1;
ll r=k-1;
while (l+1<r)
  {
  ll mi=l+r>>1;
  if (solve(mi))
    r=mi;
  else
    l=mi;
  }
cout<<r<<endl;






    return 0;
}