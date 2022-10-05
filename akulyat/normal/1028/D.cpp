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


ll n,i,j,ans;
vector <ll> m;
bool viv=false;
set <ll> s,b,r;

void add(ll v)
{
if ((*s.begin())<v)
  {
  s.insert(v);
  return ;
  }
if ((*b.rbegin())>v)
  {
  b.insert(v);
  return ;
  }
r.insert(v);
return ;
}

void take(ll v)
{
if (*s.begin()==v)
  {
  s.erase(v);
  for (auto i:r)
    b.insert(i);
  r.clear();
  return;
  }
if (*b.rbegin()==v)
  {
  b.erase(v);
  for (auto i:r)
    s.insert(i);
  r.clear();
  return;
  }

if ((b.find(v)!=b.end())||(s.find(v)!=s.end()))
  {
  cout<<0;
  exit(0);
  }
r.erase(v);
ans*=2;
ans%=mod;

for (auto i:r)
  if (i<v)
    b.insert(i);
  else
    s.insert(i);
r.clear();
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
ans=1;
s.insert(mod*10);
b.insert(-1);
for (i=0; i<n; i++)
  {
  string s;
  ll a;
  cin>>s>>a;
  if (s[1]=='D')
    add(a);
  else
    take(a);
  }

ans*=((ll)r.size()+1);
ans%=mod;

cout<<ans<<endl;

    return 0;
}

/*
12
ADD 1
ADD 2
ADD 3
ADD 4
ADD 5
ACCEPT 5
ACCEPT 4
ACCEPT 3
ACCEPT 2
ACCEPT 1
ADD 10
ACCEPT 10

24
ADD 1
ACCEPT 1
ADD 2
ACCEPT 2
ADD 3
ACCEPT 3
ADD 1
ACCEPT 1
ADD 2
ACCEPT 2
ADD 3
ACCEPT 3
ADD 1
ACCEPT 1
ADD 2
ACCEPT 2
ADD 3
ACCEPT 3
ADD 1
ACCEPT 1
ADD 2
ACCEPT 2
ADD 3
ACCEPT 3


*/