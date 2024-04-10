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
const long long inf=998244353;


ll n,i,j,k,l,pr;
vector <ll> m,v,v1;
bool viv=false;

long long var(long long v, long long mod, long long ss)
{
long long i=0;
long long st=ss;
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

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>l>>n>>k;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
pr=m.back();
for (i=n-1; i>0; i--)
  m[i]-=m[i-1];
for (auto i:m)
  v.push_back(var(k, mod, i));

ll ans=var(k, mod, l-2*pr);
for (auto i:v)
  ans*=i, ans%=mod;
for (auto i:v)
  ans*=(i+1), ans%=mod;

ans*=obr(var(2, mod, n), mod);
ans%=mod;
cout<<ans<<endl;

    return 0;
}