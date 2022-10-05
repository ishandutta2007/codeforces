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
vector <ll> p,p1;


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

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a,b;
  cin>>a>>b;
  m.push_back({a, b});
  }

ll a=m[0].F;
ll b=m[0].S;
p1=erat(50000);
for (auto c:p1)
  if (a%c==0||b%c==0)
    {
    p.push_back(c);
    while (!(a%c))
      a/=c;
    while (!(b%c))
      b/=c;
    }
if (a!=1)
  p.push_back(a);
if (b!=1)
  p.push_back(b);
for (auto c:p)
  {
  ll kol=0;
  for (auto i:m)
    if ((i.F%c==0)||(i.S%c==0))
      kol++;
  if (kol==n)
    {
    cout<<c<<endl;
    return 0;
    }
  }

cout<<-1;






    return 0;
}