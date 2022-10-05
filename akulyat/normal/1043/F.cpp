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
const long long N=300*kk+2;

long n,i,j;
long kol[N];
long dp[10][N];
vector <long> m;
vector <ll> fac,rfac;
map <ll, ll> mp;
bool viv=false;

long long obr(long long v, long long mod)
{
long long i=0;
long long st=mod-2;
vector <long long> bin;
long long l=0;
while(st>0)
  {
  bin.push_back(st&1);
  st/=2;
  l++;
  }

vector <long long> sq;
sq.push_back(v);
for (i=1; i<l; i++)
  {
  long long s=sq.back();
  s*=s;
  s%=mod;
  sq.push_back(s);
  }

long long ans=1;
for (i=0; i<l; i++)
  if (bin[i])
    {
    ans*=sq[i];
    ans%=mod;
    }
return ans;
}

void prepare()
{
fac.push_back(1);
for (ll i=1; i<N; i++)
  fac.push_back(fac.back()*i), fac.back()%=mod;
for (auto i:fac)
  rfac.push_back(obr(i, mod));
}

long C(ll n, ll k)
{
if (k>n)
  return 0;
if (k<0)
  return 0;
ll r=1;
r*=fac[n]; r%=mod;
r*=rfac[k]; r%=mod;
r*=rfac[n-k]; r%=mod;
return r;
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
  mp[a]++;
  m.push_back(a);
  }
ll g=m[0];
for (auto i:m)
  g=GCD(g, i);
if (g!=1)
  {
  cout<<-1;
  return 0;
  }

for (i=1; i<N; i++)
  {
  j=i;
  while (j<N)
    {
    kol[i]+=mp[j];
    j+=i;
    }
  }
prepare();
for (j=1; j<=7; j++)
  {
  for (i=N-1; i>0; i--)
    {
    dp[j][i]=C(kol[i], j);
    long i2=2*i;
    while (i2<N)
      dp[j][i]-=dp[j][i2], dp[j][i]%=mod, i2+=i;
    }
  if (dp[j][1])
    {
    cout<<j<<endl;
    return 0;
    }
  }



    return 0;
}