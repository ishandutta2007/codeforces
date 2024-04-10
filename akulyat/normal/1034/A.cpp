#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long   ll;
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

vector <long> erat(long long last)
{
vector <bool> bad;
vector <long> r;
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
  ll a;
  cin>>a;
  m.push_back(a);
  }
// /*
ll x=m[0];
for (auto i:m)
  x=GCD(x, i);
for (auto &i:m)
  i/=x;
ll kol=0;
for (i=0; i<n; i++)
  if (m[i]==1)
    kol++;
if (kol==n)
  {
  cout<<-1;
  return 0;
  }
// */
ll con=3900;
vector <ll> p=erat(con);
vector <long> num,pl;
for (i=0; i<con; i++)
  num.push_back(0),
  pl.push_back(0);

vector <ll> an;
for (i=0; i<p.size(); i++)
  pl[p[i]]=i;
for (auto v:m)
  {
  ll v1=v;
  j=0;
  while (p[j]*p[j]<=v1)
    {
    if (v1%p[j]==0)
      num[j]++;
    while (v1%p[j]==0)
      v1/=p[j];
    j++;
    }
  if (v1!=1)
    {
    if (v1>con)
      an.push_back(v1);
    else
      num[pl[v1]]++;
    }
  }
sort(an.begin(), an.end());
vector <ll> rep(an.size(), 1);
for (i=1; i<rep.size(); i++)
  if (an[i]==an[i-1])
    rep[i]+=rep[i-1];
ll ans=n;
for (auto i:num)
  if (i!=n)
    ans=min(ans, n-i);
for (auto i:rep)
  if (i!=n)
    ans=min(ans, n-i);
if (ans==n)
  ans=-1;
cout<<ans<<endl;






    return 0;
}