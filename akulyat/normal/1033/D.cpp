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
const long long mod=998244353;
const long long inf=ml*ml*ml+7;


ll n,i,j;
vector <ll> m,t1,t2;
vector <pll> t;
set <ll> s;
map <ll, ll> kol;
bool viv=false;

pll type(ll a)
{
ll l=1;
ll r=40*kk;
while (l+1<r)
  {
  ll m=l+r>>1;
  if (m*m*m*m<=a)
    l=m;
  else
    r=m;
  }
if (l*l*l*l==a)
  return {l, 4};


l=1;
r=ml*kk*2;
while (l+1<r)
  {
  ll m=l+r>>1;
  if (m*m<=a)
    l=m;
  else
    r=m;
  }
if (l*l==a)
  return {l, 2};

l=1;
r=ml+(ml/2);
while (l+1<r)
  {
  ll m=l+r>>1;
  if (m*m*m<=a)
    l=m;
  else
    r=m;
  }
if (l*l*l==a)
  return {l, 3};


return {a, 1};
}


long long GCD(long long a, long long b)
{
if (a==0&&b==0)
  return 1;
while (a!=0&&b!=0)
  {
  if (a>=b)
    a%=b;
  else
    b%=a;
  }
return a+b;
}




int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  t.push_back(type(a));
  }

for (auto i:t)
  {
  ll v=i.F;
  ll ty=i.S;
  if (ty!=1)
    {
    s.insert(v);
    kol[v]+=ty;
    }
  else
    t1.push_back(v);
  }

for (auto v:t1)
  {
  bool was=false;
  for (auto i:s)
    if (v%i==0&&!was)
      {
      ll a=i;
      ll b=v/a;
      s.insert(a);
      s.insert(b);
      kol[a]++;
      kol[b]++;
      was=true;
      }
  if (!was)
    t2.push_back(v);
  }

ll l=t2.size();
vector <bool> will(l, true);
for (i=0; i<l; i++)
  for (j=0; j<l;  j++)
    if (i!=j&&t2[i]!=t2[j])
      if (will[i])
      {
      ll a=t2[i];
      ll b=t2[j];
      ll d=GCD(a, b);
      if (d!=1)
        {
        ll a1=a/d;
        s.insert(a1);
        s.insert(d);
        will[i]=false;
        kol[a1]++;
        kol[d]++;
        }
      }

vector <ll> t3;
for (i=0; i<t2.size(); i++)
  if (will[i])
    t3.push_back(t2[i]);
sort(t3.begin(), t3.end());
vector <ll> rep;
rep.push_back(1);
for (i=1; i<t3.size(); i++)
  {
  rep.push_back(1);
  if (t3[i]==t3[i-1])
    rep.back()+=rep[i-1];
  }
rep.push_back(mod);

ll ans=1;
if (t3.size())
  {
  for (i=0; i<rep.size()-1; i++)
    if (rep[i]+1!=rep[i+1])
      ans*=(rep[i]+1),
      ans%=mod,
      ans*=(rep[i]+1),
      ans%=mod;
  }



for (auto i:s)
  {
  ans*=(kol[i]+1);
  ans%=mod;
  }

cout<<ans<<endl;
 /*
for (auto i:t)
  cout<<i.F<<' '<<i.S<<' ';
cout<<endl;
for (auto i:t1)
  cout<<i<<' ';
cout<<endl;
for (auto i:t2)
  cout<<i<<' ';
cout<<endl;
cout<<endl;
for (auto i:s)
  cout<<i<<' '<<kol[i]<<endl;
// */


    return 0;
}