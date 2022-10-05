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
vector <ll> m,p;
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
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  p.push_back(a);
  }
sort(m.begin(), m.end());
sort(p.begin(), p.end());

ll h=0;
ll raz=0;
while (p.size()+m.size())
  {
  if (h==0)
    {
    ll my=-inf;
    ll his=-inf;
    if (!m.empty())
      my=m.back();
    if (!p.empty())
      his=p.back();
    if (his>my)
      p.pop_back();
    else
      raz+=m.back(), m.pop_back();
    }
  if (h==1)
    {
    ll my=-inf;
    ll his=-inf;
    if (!p.empty())
      my=p.back();
    if (!m.empty())
      his=m.back();
    if (his>my)
      m.pop_back();
    else
      raz-=p.back(), p.pop_back();
    }
  h^=1;
  }

cout<<raz;



    return 0;
}