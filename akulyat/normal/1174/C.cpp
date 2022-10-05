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

ll del(ll p)
{
for (ll i=2; i*i<=p; i++)
  if (p%i==0)
    return i;
return p;
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
m.resize(n+2);
vector <ll> p=erat(n+10);
ll nex=1;
for (auto i:p)
  if (i<=n)
    m[i]=nex, nex++;
for (ll i=4; i<=n; i++)
  {
  ll d=del(i);
  m[i]=m[d];
  }
for (ll i=2; i<=n; i++)
  cout<<m[i]<<' ';





    return 0;
}