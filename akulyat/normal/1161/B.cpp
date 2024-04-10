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
const long long gs=500*kk;

long n,m,i,j;
vector <long> reb[gs+10];
vector <ll> col,tc;
vector <vector <ll>> l;
vector <ll> d;
set <pll> base;
bool viv=false;

vector <ll> make(ll n)
{
vector <ll> r;
for (ll i=1; i<n; i++)
  if (!(n%i))
    r.push_back(i);
return r;
}

bool work(ll add)
{
if (viv)
  cout<<"       Check "<<add<<endl;
set <pll> get;
for (auto p:base)
  {
  p.F+=add;
  p.S+=add;
  p.F%=n;
  p.S%=n;
  if (2*(max(p.F, p.S)-min(p.F, p.S))==n)
    if (p.F>p.S)
      swap(p.F, p.S);
  get.insert(p);
  }
if (viv)
  {
  for (auto p:get)
    cout<<p.F<<' '<<p.S<<"    ";
  cout<<endl;
  }
for (auto p:get)
  if (!base.count(p))
    return false;
return true;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m;
d=make(n);
for (i=0; i<m; i++)
  {
  long a,b;
  cin>>a>>b;
  a--; b--;
  if ((b-a+3*n)%n>n/2)
    swap(a, b);
  ll len=(b-a+3*n)%n;
  if (len*2==n)
    {
    if (a>b)
      swap(a, b);
    }

  if (viv)
    cout<<len<<endl;
  base.insert({a, b});
  }
for (auto i:d)
  if (work(i))
    {
    cout<<"Yes";
    exit(0);
    }
cout<<"No"<<endl;






    return 0;
}