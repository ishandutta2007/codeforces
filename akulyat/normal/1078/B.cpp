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
vector <ll> m,ofac,fac;
bool viv=false;
ll kol[200];
ll can[10*kk+202][102];

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


ll C(ll n, ll k)
{
ll r=1;
r*=fac[n];
r%=mod;
r*=ofac[k];
r%=mod;
r*=ofac[n-k];
r%=mod;
return r;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
fac.push_back(1);
for (ll i=1; i<300; i++)
  fac.push_back(fac.back()*i), fac.back()%=mod;
for (ll i=0; i<300; i++)
  ofac.push_back(obr(fac[i], mod)), ofac.back()%=mod;
cin>>n;
can[0][0]=1;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  kol[a]++;
  }
ll raz=0;
for (i=0; i<=100; i++)
  if (kol[i])
    raz++;
for (auto j:m)
  for (ll i=10*kk; i>=j; i--)
    for (ll kol=100; kol>=1; kol--)
      can[i][kol]+=can[i-j][kol-1], can[i][kol]%=mod;

ll ans=0;
for (i=0; i<=100; i++)
  {
  for (j=1; j<=kol[i]; j++)
    {
    ll sh=C(kol[i], j);
//    cout<<i<<' '<<j<<' '<<sh<<endl;
    if (can[i*j][j]==sh)
      {
      ans=max(ans, j);
      if (raz==2&&kol[i]==j)
        ans=n;
      }
    }
  }
cout<<ans<<endl;








    return 0;
}