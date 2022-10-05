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
vector <ll> m,pr;
bool viv=false;

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


bool ask(ll a, ll b)
{
cout<<'?'<<' '<<a<<' '<<b<<endl;
string ans;
cin>>ans;
if (ans[0]=='x')
  return true;
if (ans[0]=='y')
  return false;
if (ans[0]=='e')
  {
  ll b=0;
  while (b<ml*ml)
    b++;
  }
return false;
}

void solve(ll z)
{
ll z1=z;
vector <pll> del;
for (auto d:pr)
  if (z1%d==0)
    {
    del.push_back({d, 0});
    while (z1%d==0)
      z1/=d, del.back().S++;
    }
if (z1>1)
  del.push_back({z1, 1}), z1=1;

for (auto p:del)
  {
  ll v=p.F;
  ll kol=p.S;
  ll cont=true;
  while (cont&&kol)
    {
    kol--;
    z/=v;
    cont=false;
    if (!ask(z, 1))
      cont=true;
    }
  if (!cont)
    z*=v;
  }
cout<<'!'<<' '<<z<<endl;
}

void work()
{
string s;
cin>>s;
if (s[0]!='s')
  exit(0);
if (ask(0, 1))
  {
  cout<<"! 1"<<endl;
  return;
  }
ll l=1;
ll r=2;
while (!ask(l, r))
  l*=2, r*=2;

while (l+1<r)
  {
  ll mi=l+r>>1;
  if (!ask(l, mi))
    l=mi;
  else
    r=mi;
  }
cout<<"! "<<r<<endl;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
pr=erat(100*kk);
while (true)
  work();




    return 0;
}