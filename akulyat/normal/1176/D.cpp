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
vector <ll> m;
bool viv=false;
vector <ll> pp, sos, p;
set <ll> s;
multiset <ll> hp;
vector <pll> f;
map <ll, ll> num, forg;

vector <long long> erat(long long last)
{
vector <bool> bad;
vector <long long> r;
for (long long i=0; i<last+10; i++)
  bad.push_back(true);
for (long long i=2; i<=last; i++)
  if (bad[i])
    {
    long long j=2;
    while (j*i<=last)
      {
      bad[j*i]=false;
      j++;
      }
    r.push_back(i);
    }
return r;
}

ll del(ll v)
{
for (auto i:p)
  if (v%i==0)
    return i;
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
p=erat(3*ml);
for (auto i:p)
  s.insert(i);
for (ll i=0; i<p.size(); i++)
  num[p[i]]=i+1;
for (i=0; i<2*n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
sort(m.rbegin(), m.rend());

for (auto i:m)
  {
  if (forg[i]>0)
    forg[i]--;
  else
    if (s.count(i))
      {
      ll mn=num[i];
      forg[mn]++;
      f.push_back({mn, i});
      }
    else
      {
      ll d=del(i);
      f.push_back({i, i/d});
      forg[i/d]++;
      }
  }
for (auto p:f)
  cout<<p.F<<' ';



    return 0;
}